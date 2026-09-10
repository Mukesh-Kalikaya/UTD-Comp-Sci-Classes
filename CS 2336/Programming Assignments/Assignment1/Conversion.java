/* This program initially gets an input from the user thats inbetween the number 1-7
and this chooses an option on a menu which is displayed before asking for the input.
The program then asks the user for the measurement for converting based on their respective
choice and then displays the converted output. After this, the program then asks loops back 
and displays the menu and asks the user for a choice again.*/
import java.util.Scanner;

public class Conversion {
    public static void main(String[] args) 
    {
        // Define variables
        Scanner input = new Scanner(System.in);
        int choice = 0;

        // Logic for the menu
        while (choice != 7) 
        {
            // Displays the menu to the user
            choices();

            // Asks the user to select from 1-7 to do the
            // corresponding conversion and then get the input from the user
            System.out.print("Enter an option from 1 - 7: ");
            choice = input.nextInt();

            // If the user enters 7, exit/end the program.
            if (choice == 7) 
            {
                System.out.println("Ending the program.");
                break;
            }

            // Checks to see if the option that the user entered is valid and keeps
            // it within bounds
            if (choice < 1 || choice > 7) 
            {
                System.out.println("Invalid option");
                continue;
            }

            // Respective measurement conversion methods
            if (choice == 1) 
            {
                fahrenheitToCelsius(input);
            } 
            else if (choice == 2) 
            {
                gallonsToLiter(input);
            } 
            else if (choice == 3) 
            {
                poundsToKilograms(input);
            } 
            else if (choice == 4) 
            {
                milesToKilometers(input);
            } 
            else if (choice == 5) 
            {
                inchToCentimeters(input);
            } 
            else if (choice == 6) 
            {
                yardsToMeter(input);
            }
        }
    }

    // Displays the menu
    public static void choices() 
    {
        System.out.println("1. Convert Fahrenheit to Celsius");
        System.out.println("2. Convert Gallons to Liter");
        System.out.println("3. Convert Pounds to Kilograms");
        System.out.println("4. Convert Miles to Kilometers");
        System.out.println("5. Convert Inch to Centimeters");
        System.out.println("6. Convert Yards to Meter");
        System.out.println("7. Exit the program");
    }

    // Does the conversion from Fahrenheit to Celsius and displays the output
    // to the user
    public static void fahrenheitToCelsius(Scanner input) 
    {
        // Define variables
        double celsius;
        double temp;

        // Ask the user for the measurement to convert
        System.out.print("Please enter the temperature in Fahrenheit to convert: ");
        temp = input.nextDouble();

        // Conversion formula
        celsius = (temp - 32) * (5.0 / 9.0);

        System.out.format("The temperature %f °F in Celsius is %.2f °C %n", temp, celsius);
    }

    // Does the conversion from Gallon(s) to Liter(s) and displays the output
    // to the user
    public static void gallonsToLiter(Scanner input) 
    {
        // Define variables
        double quantity;
        double gallons;

        // Ask the user for the measurement to convert
        System.out.print("Please enter the number of gallons to covert: ");
        quantity = input.nextDouble();

        // Validate the response from the user convert or end accordingly
        if (quantity < 0.0) {
            return;
        } else {
            // Conversion formula and output
            gallons = quantity * 3.785;
            System.out.format("%f gallons in liters is %.2f%n", quantity, gallons);
        }
    }

    // Does the conversion from Pound(s) to Kilogram(s) and displays the output
    // to the user
    public static void poundsToKilograms(Scanner input) 
    {
        // Define variables
        double weight;
        double kilo;

        // Ask for the measurement to convert
        System.out.println("Please enter the weight in pounds to convert: ");
        weight = input.nextDouble();

        // Validate the response from the user convert or end accordingly
        if (weight < 0.0) {
            return;
        } else {
            // Conversion formula and output
            kilo = weight / 2.205;
            System.out.format("%f pounds in Kilograms is %.2f%n", weight, kilo);
        }
    }

    // Does the conversion from Mile(s) to Kilometer(s) and displays the output
    // to the user
    public static void milesToKilometers(Scanner input) 
    {
        // Define variables
        double distance;
        double km;

        // Ask for the measurement to convert
        System.out.print("Please enter the distance in miles to convert: ");
        distance = input.nextDouble();

        // Validate the response from the user convert or end accordingly
        if (distance < 0.0) {
            return;
        } else {
            // Conversion formula and output
            km = distance * 1.609;
            System.out.format("%f miles in kilometers is %.2f%n", distance, km);
        }
    }

    // Does the conversion from Inches to Centimeters and displays the output
    // to the user
    public static void inchToCentimeters(Scanner input) 
    {
        // Define variables
        double inch;
        double cm;

        // Ask for the measurement to convert
        System.out.println("Please enter the distance in inches to convert: ");
        inch = input.nextDouble();

        // Validate the response from the user convert or end accordingly
        if (inch < 0.0) {
            return;
        } else {
            // Conversion formula and output
            cm = inch * 2.54;
            System.out.format("%f inches in centimeters is %.2f%n", inch, cm);
        }
    }

    // Does the conversion from Yard(s) to Meter(s) and displays the output
    // to the user
    public static void yardsToMeter(Scanner input) 
    {
        // Define variables
        double yards;
        double meter;

        // Ask for the measurement to convert
        System.out.print("Please enter the distance in yards to convert: ");
        yards = input.nextDouble();

        // Validate the response from the user convert or end accordingly
        if (yards < 0.0) {
            return;
        } else {
            // Conversion formula and output
            meter = yards * 0.9144;
            System.out.format("%f yards in meters is %.2f%n", yards, meter);    
        }
    }
}
