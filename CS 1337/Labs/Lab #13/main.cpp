/* This program manages a bank account system that allows the user to create
regular and premium accounts, deposit and withdraw funds, and print info
for all accounts. It uses an array of base class pointers to dynamically
create and manage both account types through a menu-driven loop. */
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "RegularAccount.h"
#include "PremiumAccount.h"
using namespace std;

int main() {
    const int MAX_NUM_ACCOUNTS = 5;

    // Array of base class pointers to hold regular and premium accounts
    Account* accountArray[MAX_NUM_ACCOUNTS];

    // Initialize all pointers to nullptr so we can track which slots are open
    for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
        accountArray[i] = nullptr;
    }

    int choice;

    // Keep displaying the menu until the user chooses to quit
    do {
        cout << "1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt" << endl;
        cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit" << endl;
        cin >> choice;

        if (choice == 1) {
            // Check if the maximum number of accounts has already been reached
            if (Account::getNumberAccounts() >= MAX_NUM_ACCOUNTS) {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
            }
            else {
                string name;
                double amount;
                int mo, dy, yr, hr;
                char slash;
                Date d;

                cout << "Enter owner's name: ";
                cin >> name;
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> mo >> slash >> dy >> slash >> yr >> slash >> hr;
                d.set(mo, dy, yr, hr);
                cout << "Enter amount: ";
                cin >> amount;

                // Show an error and do not create the account if the amount is not positive
                if (amount <= 0) {
                    cout << "Amount cannot be negative, account creation not executed" << endl;
                }
                else {
                    // Find the first available slot in the account array
                    for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                        if (accountArray[i] == nullptr) {
                            accountArray[i] = new RegularAccount(name, amount, d);
                            cout << "Account created: " << endl;
                            accountArray[i]->print();
                            break;
                        }
                    }
                }
            }
        }
        else if (choice == 2) {
            // Check if the maximum number of accounts has already been reached
            if (Account::getNumberAccounts() >= MAX_NUM_ACCOUNTS) {
                cout << "Max number of accounts reached, cannot add a new account" << endl;
            }
            else {
                string name;
                double amount;
                int mo, dy, yr, hr;
                char slash;
                Date d;

                cout << "Enter owner's name: ";
                cin >> name;
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> mo >> slash >> dy >> slash >> yr >> slash >> hr;
                d.set(mo, dy, yr, hr);
                cout << "Enter amount: ";
                cin >> amount;

                // Show an error if the amount is less than the minimum required balance
                if (amount < PremiumAccount::getMinBalance()) {
                    cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account" << endl;
                }
                else {
                    // Find the first available slot in the account array
                    for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                        if (accountArray[i] == nullptr) {
                            accountArray[i] = new PremiumAccount(name, amount, d);
                            cout << "Account created: " << endl;
                            accountArray[i]->print();
                            break;
                        }
                    }
                }
            }
        }
        else if (choice == 3) {
            int accNum;
            double amount;
            int mo, dy, yr, hr;
            char slash;
            Date d;

            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> mo >> slash >> dy >> slash >> yr >> slash >> hr;
            d.set(mo, dy, yr, hr);
            cout << "Enter amount: ";
            cin >> amount;

            // Show an error if the deposit amount is not greater than zero
            if (amount <= 0) {
                cout << "Amount cannot be negative, deposit not executed" << endl;
            }
            else {
                // Search the array for an account that matches the given account number
                bool found = false;
                for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                    if (accountArray[i] != nullptr &&
                        accountArray[i]->getAccountNumber() == accNum) {
                        accountArray[i]->deposit(amount, d);
                        cout << "Deposit executed: " << endl;
                        accountArray[i]->print();
                        found = true;
                        break;
                    }
                }

                // If no matching account was found, show an error message
                if (!found) {
                    cout << "No such account" << endl;
                }
            }
        }
        else if (choice == 4) {
            int accNum;
            double amount;
            int mo, dy, yr, hr;
            char slash;
            Date d;

            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> mo >> slash >> dy >> slash >> yr >> slash >> hr;
            d.set(mo, dy, yr, hr);
            cout << "Enter amount: ";
            cin >> amount;

            // Show an error if the withdrawal amount is not greater than zero
            if (amount <= 0) {
                cout << "Amount cannot be negative, withdraw not executed" << endl;
            }
            else {
                // Search the array for an account that matches the given account number
                bool found = false;
                for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                    if (accountArray[i] != nullptr &&
                        accountArray[i]->getAccountNumber() == accNum) {
                        found = true;

                        // Attempt the withdrawal and show an error if it fails
                        if (accountArray[i]->withdraw(amount, d)) {
                            cout << "Withdraw executed: " << endl;
                            accountArray[i]->print();
                        }
                        else {
                            cout << "Insufficient balance, withdrawal not executed" << endl;
                        }
                        break;
                    }
                }

                // If no matching account was found, show an error message
                if (!found) {
                    cout << "No such account" << endl;
                }
            }
        }
        else if (choice == 5) {
            // Print information for every account that has been created
            for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
                if (accountArray[i] != nullptr) {
                    accountArray[i]->print();
                }
            }
        }

    } while (choice != 6);

    // Release the dynamically allocated memory for each account
    for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
        if (accountArray[i] != nullptr) {
            delete accountArray[i];
        }
    }

    return 0;
}