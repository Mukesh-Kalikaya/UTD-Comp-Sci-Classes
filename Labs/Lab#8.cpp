/* This program gets the value of the stock sale and then displays the 
ammount of commission on the sale using the table that was given which 
has specific levels of commission for different values of stock sales*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Define the variables
    double stockValue, commission, saleValue;
    
    // Gets the stock sale from the user
    cout << "Please enter the amount of the stock sale: $ ";
    cin >> stockValue;

    // Calculates the commission
    if (stockValue <= 0) {
        cout << endl << "Error, invalid sales amount entered." << endl;
        return 0;
    } else if (stockValue > 0 && stockValue <= 500) {
        commission = 35;
    } else if (stockValue > 500 && stockValue <= 1500) {
        saleValue = (0.02 * (stockValue - 500));
        commission = 35 + saleValue;
    } else if (stockValue > 1500 && stockValue <= 10000) {
        saleValue = (0.01 * (stockValue - 1500));
        commission = 45 + saleValue;
    } else if (stockValue > 10000 && stockValue <= 100000) {
        saleValue = (0.0075 * (stockValue - 10000));
        commission = 130 + saleValue;
    } else {
        commission = 1000;
    }
    
    // Outputs the commission to the user
    cout << fixed << setprecision(2);
    cout << endl << "The commission is $" << commission << endl;
    
    return 0;
}