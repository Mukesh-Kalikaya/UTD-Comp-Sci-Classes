/* This program reads a text file, finds dates, displays the dates,
and saves the dates to a report file. */
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.format.ResolverStyle;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DateExtractor {
    // Stores the month names and abbreviations
    private static final String MONTH_NAMES =
            "January|February|March|April|May|June|July|August|September|October|November|December"
            + "|Jan|Feb|Mar|Apr|Jun|Jul|Aug|Sep|Sept|Oct|Nov|Dec";

    // Looks for dates written in different formats
    private static final Pattern[] DATE_PATTERNS = {
        // Looks for dates with the month first
        Pattern.compile("\\b(?:0?[1-9]|1[0-2])[/.-](?:0?[1-9]|[12][0-9]|3[01])[/.-]\\d{4}\\b"),

        // Looks for dates with the year first
        Pattern.compile("\\b\\d{4}[/.-](?:0?[1-9]|1[0-2])[/.-](?:0?[1-9]|[12][0-9]|3[01])\\b"),

        // Looks for dates with the month written first
        Pattern.compile("\\b(?:" + MONTH_NAMES + ")\\.?\\s+(?:0?[1-9]|[12][0-9]|3[01])"
                + "(?:st|nd|rd|th)?[,]?\\s+\\d{4}\\b", Pattern.CASE_INSENSITIVE),

        // Looks for dates with the day written first
        Pattern.compile("\\b(?:0?[1-9]|[12][0-9]|3[01])(?:st|nd|rd|th)?\\s+(?:"
                + MONTH_NAMES + ")\\.?[,]?\\s+\\d{4}\\b", Pattern.CASE_INSENSITIVE),

        // Looks for dates separated by dashes
        Pattern.compile("\\b(?:0?[1-9]|[12][0-9]|3[01])-(?:Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Sept|Oct|Nov|Dec)-\\d{4}\\b",
                Pattern.CASE_INSENSITIVE)
    };

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        String inputFile;
        String reportFile;

        // Gets the input file name
        if (args.length >= 1) {
            inputFile = args[0];
        } else {
            System.out.print("Enter the name of the text file to read: ");
            inputFile = keyboard.nextLine().trim();
        }

        // Gets the report file name
        if (args.length >= 2) {
            reportFile = args[1];
        } else {
            reportFile = "date_report.txt";
        }

        try {
            // Reads the text from the input file
            String documentText = new String(
                    Files.readAllBytes(Paths.get(inputFile)), StandardCharsets.UTF_8);

            // Finds the dates in the text
            List<DateMatch> dates = extractDates(documentText);

            // Outputs the dates that were found
            System.out.println("Dates found:");
            if (dates.isEmpty()) {
                // Outputs a message if no dates were found
                System.out.println("No dates were found.");
            } else {
                // Outputs each date
                for (DateMatch date : dates) {
                    System.out.println(date.text);
                }
            }

            // Outputs the total number of dates
            System.out.println("Total number of dates: " + dates.size());

            // Saves the dates to the report file
            writeReport(dates, reportFile);
            System.out.println("The report was saved to: " + reportFile);

        } catch (IOException e) {
            // Outputs an error message if the file cannot be used
            System.out.println("Error: Could not read or write a file.");
            System.out.println("Check that the file name and location are correct.");
        }

        // Closes the keyboard input
        keyboard.close();
    }

    // Finds all valid dates in the text
    private static List<DateMatch> extractDates(String text) {
        List<DateMatch> foundDates = new ArrayList<>();

        // Checks the text for each date pattern
        for (Pattern pattern : DATE_PATTERNS) {
            Matcher matcher = pattern.matcher(text);

            while (matcher.find()) {
                String possibleDate = matcher.group();

                // Checks if the date is valid
                if (isValidDate(possibleDate)) {
                    foundDates.add(new DateMatch(possibleDate, matcher.start(), matcher.end()));
                }
            }
        }

        // Sorts the dates in the order they appear in the text
        Collections.sort(foundDates, Comparator.comparingInt(date -> date.start));

        // Removes duplicate dates
        List<DateMatch> finalDates = new ArrayList<>();
        int lastEnd = -1;

        for (DateMatch date : foundDates) {
            if (date.start >= lastEnd) {
                finalDates.add(date);
                lastEnd = date.end;
            }
        }

        return finalDates;
    }

    // Checks if a date is a real calendar date
    private static boolean isValidDate(String dateText) {
        try {
            String cleanedDate = dateText
                    .replaceAll("(?i)(\\d)(st|nd|rd|th)\\b", "$1")
                    .replace(".", "")
                    .replace(",", "")
                    .replaceAll("\\s+", " ")
                    .trim();
            cleanedDate = cleanedDate.replaceAll("(?i)\\bSept\\b", "Sep");

            // Checks dates with the year first
            if (cleanedDate.matches("\\d{4}[/.-]\\d{1,2}[/.-]\\d{1,2}")) {
                String[] parts = cleanedDate.split("[/.-]");
                LocalDate.of(Integer.parseInt(parts[0]),
                        Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
                return true;
            }

            if (cleanedDate.matches("\\d{1,2}[/.-]\\d{1,2}[/.-]\\d{4}")) {
                String[] parts = cleanedDate.split("[/.-]");
                LocalDate.of(Integer.parseInt(parts[2]),
                        Integer.parseInt(parts[0]), Integer.parseInt(parts[1]));
                return true;
            }

            // Stores the possible written date formats
            String[] formats = {
                "MMMM d uuuu", "MMM d uuuu", "d MMMM uuuu", "d MMM uuuu",
                "d-MMM-uuuu", "d-LLLL-uuuu"
            };

            for (String format : formats) {
                try {
                    DateTimeFormatter formatter = DateTimeFormatter
                            .ofPattern(format, Locale.ENGLISH)
                            .withResolverStyle(ResolverStyle.STRICT);
                    LocalDate.parse(cleanedDate, formatter);
                    return true;
                } catch (DateTimeParseException e) {
                    // Tries the next date format
                }
            }

        } catch (DateTimeParseException | NumberFormatException e) {
            return false;
        } catch (RuntimeException e) {
            // Returns false if the date is not valid
            return false;
        }

        return false;
    }

    // Writes the dates and total number of dates to the report
    private static void writeReport(List<DateMatch> dates, String reportFile)
            throws IOException {
        List<String> reportLines = new ArrayList<>();

        for (DateMatch date : dates) {
            reportLines.add(date.text);
        }

        reportLines.add("Total number of dates: " + dates.size());
        Files.write(Paths.get(reportFile), reportLines, StandardCharsets.UTF_8);
    }

    // Stores a date and its position in the text
    private static class DateMatch {
        private final String text;
        private final int start;
        private final int end;

        private DateMatch(String text, int start, int end) {
            this.text = text;
            this.start = start;
            this.end = end;
        }
    }
}