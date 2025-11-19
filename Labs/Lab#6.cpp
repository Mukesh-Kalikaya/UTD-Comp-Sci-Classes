/* This program */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    // Define all variables
    double saleValue, tip20, tip22, tip25, salesAmount, tipValue, total;
    
    // Get the tip input from the user
    cout << "Enter the amount of the sale in $: ";
    cin >> saleValue;

    // Calculate the top needed
    tip20 = saleValue * 0.20;
    tip22 = saleValue * 0.22;
    tip25 = saleValue * 0.25;
    
    // Round the values to exactly two decimal points
    cout << fixed << setprecision(2);
    
    // Display the rounded tip values
    cout << endl << "20% tip: $" << tip20 << endl;
    cout << "22% tip: $" << tip22 << endl;
    cout << "25% tip: $" << tip25 << endl;
    
    // Get the tip value from the user
    cout << endl << "Enter the amount of the tip in $: ";
    cin >> tipValue;

    // Calculate the total value including the tip
    total = saleValue + tipValue;
    
    // Output the bill details that include the sales amount,
    // the tip value, and the total
    cout << endl << left << setw(15) << "Sales Amount: " 
         << "$" << saleValue << endl;
    cout << left << setw(15) << "Tip Amount: " << "$" << tipValue 
         << endl;
    cout << left << setw(15) << "Total: " << "$" << total << endl;

    return 0;
}