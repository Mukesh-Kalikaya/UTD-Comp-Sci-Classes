/* This program is an ATM simulator where it offers three types of 
transaction services: check your current balance, deposit, and withdraw money.
This program utilizes two functions, deposit and withdrawal, respectively to 
perform the actions mentioned in the name and to handle those processes
accordingly.*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Function prototypes
double deposit(double balance);
double withdrawal(double balance);

int main() {
    // Randomize the seed for the balance
    unsigned int seed;
    cin >> seed;
    srand(seed);
    
    // Define balance and assign the randomized value
    double balance = rand() % 10001;
    
    // Define other variables
    char choice;
    
    // Output the options to the user
    cout << fixed << setprecision(2);
    cout << "\tATM Menu" << endl;
    
    cout << endl << "B - Check account balance" << endl;
    cout << "D - Deposit money" << endl;
    cout << "W - Withdraw money" << endl;
    
    // Ask for the transaction choice from the user
    cout << "\nEnter the letter of your desired transaction: ";
    cin >> choice;
    
    // Perform the requested transaction along with checking for other
    // non offered choices.
    if (choice == 'B' || choice == 'b') {
        cout << endl << "Your balance is $" << balance << "." << endl;
    } else if (choice == 'D' || choice == 'd') {
        balance = deposit(balance);
        cout << endl << "Your balance is $" << balance << "." << endl;
    } else if (choice == 'W' || choice == 'w') {
        balance = withdrawal(balance);
        cout << endl << "Your balance is $" << balance << "." << endl;
    } else {
        cout << endl << "Invalid transaction choice." << endl;
    }

    return 0;
} 

/* This function handldes the depositing part of the ATM. It gets the 
deposit amount from the user and if the amount is valid, it then adds that 
value to the current balance and then returns the new balance to output to
the user.*/ 
double deposit(double balance) {
    double depositAmount;
    
    cout << "Enter your deposit amount: ";
    cin >> depositAmount;
    
    if (depositAmount > 0.00) {
        balance += depositAmount;
    } else {
        cout << endl << "Invalid deposit amount." << endl;
    }
    
    return balance;
}

/* This function handles the withdrawal part of the ATM. It gets the 
withdrawal amount from the user and if the amount is valid (greater than 0 
and less than the existing balance), it then subtracts that value from the 
current balance and then returns that new balance to output to the user.*/
double withdrawal(double balance) {
    double withdrawalAmount;
    
    cout << "Enter your withdrawal amount: ";
    cin >> withdrawalAmount;
    
    if (withdrawalAmount <= 0.00) {
        cout << endl << "Invalid withdrawal amount." << endl;
    } else if (withdrawalAmount > balance) {
        cout << endl << "You do not have sufficient funds for this"
             << " withdrawal." << endl;
    } else {
        balance -= withdrawalAmount;
    }
    
    return balance;
}