# README: Assignment 4 - Date Extractor

## Instructions
### Requirements
Online Editor or JDK (Java Development Kit) downloaded locally on your system.

You also need a text file with dates in it for the program to read.

### Online Editor
1. Paste the code into the Online Editor.
2. Make a text file with some dates in it.
3. Run the code with the name of the text file.
4. If no file name is entered when the program starts, enter the file name when the program asks for it.
5. Check the dates printed in the output and the `date_report.txt` file.

## Pseudocode
```text
START
    Set inputFile and reportFile

    IF an input file name was given when the program starts THEN
        Use that file name
    ELSE
        Ask the user for the input file name
    END IF

    IF a report file name was given THEN
        Use that file name
    ELSE
        Set reportFile = "date_report.txt"
    END IF

    Read all of the text from the input file
    Find all of the dates in the text

    IF no dates were found THEN
        Print "No dates were found."
    ELSE
        Print each date that was found
    END IF

    Print the total number of dates
    Write the dates and total to the report file
    Print the name of the report file

    IF the file cannot be read or written THEN
        Print an error message
    END IF
END

Method extractDates(text)
    Set foundDates to an empty list

    FOR each date pattern
        Search the text for dates

        WHILE another possible date is found
            IF the date is valid THEN
                Add the date to foundDates
            END IF
        END WHILE
    END FOR

    Sort the dates in the order they appear
    Remove duplicate dates
    Return the dates
END Method

Method isValidDate(date)
    Clean the date

    IF the date has numbers with the year first THEN
        Check if the date is valid
    ELSE IF the date has numbers with the month first THEN
        Check if the date is valid
    ELSE
        Check the written date formats
    END IF

    Return true if the date is valid
    Return false if the date is not valid
END Method

Method writeReport(dates, reportFile)
    Write each date to the report file
    Write the total number of dates
END Method
```

## Test Cases
```
Test Case 1: Dates with different formats
Input file:
  The meeting is on 11/16/2026.
  The project is due on November 20, 2026.
  Another date is 2026-12-01.
  The test is on 5-Jan-2027.

Output:
  11/16/2026
  November 20, 2026
  2026-12-01
  5-Jan-2027
  Total number of dates: 4
```

```
Test Case 2: No dates
Input file:
  There are no dates in this file.

Output:
  No dates were found.
  Total number of dates: 0
```

```
Test Case 3: Invalid date
Input file:
  The date February 30, 2024 is not valid.

Output:
  No dates were found.
  Total number of dates: 0
```
