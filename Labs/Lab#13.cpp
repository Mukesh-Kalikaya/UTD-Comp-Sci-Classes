/* This program uses a do-while loop to display a table of temperatures
in Fahrenheit and Celsius. The program gets an input from the user of the 
initial temperature in Fahrenheit and it then calculates the Celsius 
equivalent and outputs this value. The value of Fahrenheit is incremented by 
4 each time the loop is run until the temperature in Fahrenheit is less than
or equal to 120.0.*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Define variables
    double fahrenheit;
    double celsius;
    
    // Get the fahrenheit temperature from the user
    cout << "Enter a Fahrenheit temperature of 120 or lower: ";
    cin >> fahrenheit;
    
    // Check if the temperature entered is greater than 120
    if (fahrenheit > 120) {
        return 0;
    }
    
    // Start the output of the table
    cout << "\n|Fahrenheit| Celsius|" << endl;
    
    // Write the loop for outputting the temperature in fahrenheit and 
    // celsius until the temperature less than or equal to 120.0
    do {
        celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
        
        cout << "|" << setw(10) << fixed << setprecision(1) << fahrenheit
             << "|" << setw(8) << fixed << setprecision(1) << celsius
             << "|" << endl;
        
        fahrenheit += 4.0;
    } while (fahrenheit <= 120.0);

    return 0;
}