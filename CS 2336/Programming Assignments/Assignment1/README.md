# README: Assignemnt 1 - US to Metric Unit Converter
## Instructions
### Requirements
Online Editor or JDK (Java Development Kit) downloaded locally on your system.
### Online Editor
1. Paste the code into the Online Editor
2. Run the code.
3. Enter any number between and including 1-7 based on your choice in the menu.
4. Enter the measurement that you would like to convert to Metric.
5. End the program if you are done using it or select another option from the menu by entering a number between 1-7 again.

## Pseudocode
```text
START
    Set choice = 0
    
    WHILE choice != 7 DO
        Call choices() method to display menu options
        
        Prompt user: "Enter an option from 1 - 7: "
        Read choice from user
        
        IF choice EQUALS 7 THEN
            Print "Ending the program."
            BREAK loop
        END IF
        
        IF choice < 1 OR choice > 7 THEN
            Print "Invalid option"
            CONTINUE loop
        END IF
        
        IF choice == 1 THEN
            Call fahrenheitToCelsius(input)
        ELSE IF choice == 2 THEN
            Call gallonsToLiter(input)
        ELSE IF choice == 3 THEN
            Call poundsToKilograms(input)
        ELSE IF choice == 4 THEN
            Call milesToKilometers(input)
        ELSE IF choice == 5 THEN
            Call inchToCentimeters(input)
        ELSE IF choice == 6 THEN
            Call yardsToMeter(input)
        END IF
    END WHILE
END

Method choices()
    Print menu choices (Options 1 through 7)
END Method

Method fahrenheitToCelsius(input)
    Prompt user for temperature in Fahrenheit
    Read temp from user
    
    celsius = (temp - 32) * (5.0 / 9.0)
    Print formatted result: temp and celsius
END Method

Method gallonsToLiter(input)
    Prompt user for gallons
    Read quantity from user
    
    IF quantity < 0.0 THEN
        RETURN
    ELSE
        gallons = quantity * 3.785
        Print formatted result: quantity and gallons
    END IF
END Method

Method poundsToKilograms(input)
    Prompt user for weight in pounds
    Read weight from user
    
    IF weight < 0.0 THEN
        RETURN
    ELSE
        kilo = weight / 2.205
        Print formatted result: weight and kilo
    END IF
END Method

Method milesToKilometers(input)
    Prompt user for distance in miles
    Read distance from user
    
    IF distance < 0.0 THEN
        RETURN
    ELSE
        km = distance * 1.609
        Print formatted result: distance and km
    END IF
END Method

Method inchToCentimeters(input)
    Prompt user for distance in inches
    Read inch from user
    
    IF inch < 0.0 THEN
        RETURN
    ELSE
        cm = inch * 2.54
        Print formatted result: inch and cm
    END IF
END Method

Method yardsToMeter(input)
    Prompt user for distance in yards
    Read yards from user
    
    IF yards < 0.0 THEN
        RETURN
    ELSE
        meter = yards * 0.9144
        Print formatted result: yards and meter
    END IF
END Method
```

## Test Cases
```
Test Case 1: Fahrenheit to Celsius
Input: 
  Choice: 1
  Measurement: 25
Output: 
  The temperature 25.000000 °F in Celsius is -3.89 °C
```

```
Test Case 2: Gallons to Liter
Input: 
  Choice: 2
  Measurement: 25
Output: 
  25.000000 gallons in liters is 94.63
```

```
Test Case 3: Pounds to Kilograms
Input: 
  Choice: 3
  Measurement: 25
Output: 
  25.000000 pounds in Kilograms is 11.34
```

```
Test Case 4: Miles to Kilometers
Input: 
  Choice: 4
  Measurement: 25
Output: 
  25.000000 miles in kilometers is 40.23
```

```
Test Case 5: Inch to Centimeters
Input: 
  Choice: 5
  Measurement: 25
Output: 
  25.000000 inches in centimeters is 63.50
```

```
Test Case 6: Yards to Meter
Input: 
  Choice: 6
  Measurement: 25
Output: 
  25.000000 yards in meters is 22.86
```

```
Test Case 7: Exit Program
Input: 
  Choice: 7
Output: 
  Ending the program.
```