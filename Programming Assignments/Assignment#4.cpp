/* This program is a tip calculator with multiple functions. This program asks 
the user for the sale amount and then calculates the default tip percentages
(10, 15, 20) and then outputs a menu for the user to either pick the default 
percentages or ask the user for either a custom percentage or custom amount. It
then checks to see if the arguements passed in by the user are valid and if 
they are, it outputs the sale amount, the tip amount, and then the total 
amount. */
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
double calcTipAmt(double saleAmt, double tipPercent);
char getMenuItem(double saleAmt);
double calcTotalSale(double saleAmt, double total);
void displayResults(double saleAmt, double tipAmt, double total);

int main() {
    // Define variables
    double saleAmt, tipAmt = 0.0, total = 0.0;
    char menuChoice;
    bool valid = true;
    
    // Get the sale amount from the user
    cout << "Enter the amount of the sale: ";
    cin >> saleAmt;
    
    // Check to see if the sales amount entered is valid
    if (saleAmt <= 0) {
        cout << "\nError, invalid sales amount entered." << endl;
        valid = false;
        
        return 0;
    }
    
    menuChoice = getMenuItem(saleAmt);
    
    // Calculate the tip based on the character that the user entered
    switch (menuChoice) {
        case 'T':
        case 't':
            tipAmt = calcTipAmt(saleAmt, 10);
            break;
        case 'F':
        case 'f':
            tipAmt = calcTipAmt(saleAmt, 15);
            break;
        case 'W':
        case 'w':
            tipAmt = calcTipAmt(saleAmt, 20);
            break;
        case 'P':
        case 'p':
            double percent;
            cout << "Enter custom tip percentage: ";
            cin >> percent;
            if (percent < 0) {
                cout << "\nError, invalid percentage entered." << endl;
                cout << "Valid percentages are non-negative." << endl;
                valid = false;
                
                return 0;
            } else {
                tipAmt = calcTipAmt(saleAmt, percent);
            }
            break;
        case 'A':
        case 'a':
            double customTip;
            
            cout << "Enter custom tip amount: ";
            cin >> customTip;
            
            if (customTip < 0) {
                cout << "\nError, invalid tip amount entered." << endl;
                cout << "Valid amounts are non-negative." << endl;
                valid = false;
                
                return 0;
            } else {
                tipAmt = customTip;
            }
            break;
        default:
            cout << "\nError, invalid menu choice entered." << endl;
            valid = false;
            
            break;
    }
    
    if (valid) {
        total = calcTotalSale(saleAmt, tipAmt);
        displayResults(saleAmt, tipAmt, total);
    }

    return 0;
}

/* This function takes in two arguments, the sales amount and the percentage 
of tip and returns the the amount of the tip based on the sale amount and the 
percentage of the tip, which were passed in as arguments. */
double calcTipAmt(double saleAmt, double tipPercent) {
    // Returns the calculated tip amount based on the tip percentage
    return saleAmt * (tipPercent / 100.0);
}

/* This function shows a menu with the default tip options (10%, 15%, and 20%)
based on the sale amount the user entered. It then asks the user to pick one 
of the options or enter a custom percentage or custom tip amount. The function 
returns the character that matches the user's choice. */
char getMenuItem(double saleAmt) {
    // Define variables
    char choice;
    
    // Output the menu of choices to the user with the value of the sale 
    // for the default percentages (10, 15, 20).
    cout << "\n\t\t\tTip Calculator\n\n";
    cout << fixed << setprecision(2);
    cout << "\tT - 10 percent tip of $" << calcTipAmt(saleAmt, 10) << endl;
    cout << "\tF - 15 percent tip of $" << calcTipAmt(saleAmt, 15) << endl; 
    cout << "\tW - 20 percent tip of $" << calcTipAmt(saleAmt, 20) << endl;
    cout << "\tP - Custom tip percentage " << endl;
    cout << "\tA - Custom tip amount " << endl;
    cout << "Enter your menu choice [T, F, W, P, A]:";
    
    // Get and return the choice of the user
    cin >> choice;
    return choice;
}

/* This function takes in the sale amount and the tip amount, adds them
together, and returns the total amount. */
double calcTotalSale(double saleAmt, double tipAmt) {
    // Add both of the values passed into the function and output them.
    return saleAmt + tipAmt;
}

/* This function is the additional function I have chosen which gets all of 
the values for the sale amount, the tip amount, and the total bill cost and 
outputs them. */
void displayResults(double saleAmt, double tipAmt, double total) {
    cout << fixed << setprecision(2);
    cout << "\nSales Amount: $" << saleAmt << endl;
    cout << "Tip Amount: $" << tipAmt << endl;
    cout << "Total Due: $" << total << endl;
}