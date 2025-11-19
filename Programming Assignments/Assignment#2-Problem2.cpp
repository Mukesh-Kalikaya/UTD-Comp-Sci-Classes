/* This program gets the amount of dollars(including cents) from the user 
and then translates them to the amount of dollars, quarters, dimes, nickels, 
and pennies.*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Define variables
    double dollarInput;
    int dollars, quarters, dimes, nickels, pennies;
    
    // Get the input from the user
    cout << "Enter the change amount to make in dollars: ";
    cin >> dollarInput;
    
    // Convert all of the money to pennies
    dollars = static_cast <int>(dollarInput);
    pennies = round((dollars * 100) + ((dollarInput - dollars) * 100));

    // Convert the pennies back to its respective values
    dollars = pennies / 100;
    pennies %= 100;
    
    quarters = pennies / 25;
    pennies %= 25;
    
    dimes = pennies / 10;
    pennies %= 10;
    
    nickels = pennies / 5;
    pennies %= 5;
    
    // Output the change.
    cout << "Change Due:" << endl;
    cout << "\t" << dollars << " dollars" << endl;
    cout << "\t" << quarters << " quarters" << endl;
    cout << "\t" << dimes << " dimes" << endl;
    cout << "\t" << nickels << " nickels" << endl;
    cout << "\t" << pennies << " pennies" << endl;
    
    return 0;
}