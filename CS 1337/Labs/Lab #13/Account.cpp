/* This file implements the member functions of the Account base class. It
handles the creation of accounts by assigning a unique account number,
and provides functions to deposit and withdraw funds while checking that
the amounts are valid before processing any transaction. */
#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Initialize the static member variable that tracks the total number of accounts
int Account::numberAccounts = 0;

/* This constructor initializes the ownerName and balance member variables
using the values passed in as parameters. The account number is set to
numberAccounts plus 1000, and then numberAccounts is incremented. The
transactionHistory pointer is set to nullptr and numberTransactions is
set to zero. The date parameter is a placeholder for the extra credit
version and is not used in the basic version. */
Account::Account(string nam, double bal, Date d) {
    ownerName = nam;
    balance = bal;
    accountNumber = numberAccounts + 1000;
    numberAccounts++;
    transactionHistory = nullptr;
    numberTransactions = 0;

#ifdef EXTRA_CREDIT
    Transaction t;
    t.date = d;
    t.transactionType = 0;
    t.amount = bal;
    recordTransaction(t);
#else
    (void)d; // date is a placeholder for the basic version
#endif
}

/* This function checks if there is enough balance to cover the withdrawal
amount. If the balance is sufficient, the amount is deducted from the
balance and the function returns true. If the balance is not sufficient,
no withdrawal is made and the function returns false. The date parameter
is a placeholder for the extra credit version and is not used here. */
bool Account::withdraw(double amount, Date d) {
    // Check if the balance is enough to cover the withdrawal
    if (balance >= amount) {
        balance -= amount;
#ifdef EXTRA_CREDIT
        Transaction t;
        t.date = d;
        t.transactionType = 2;
        t.amount = amount;
        recordTransaction(t);
#else
        (void)d;
#endif
        return true;
    }
#ifndef EXTRA_CREDIT
    (void)d;
#endif
    return false;
}

/* This function checks if the deposit amount is greater than zero. If it
is positive, the amount is added to the balance and the function returns
true. If the amount is not positive, no deposit is made and the function
returns false. The date parameter is a placeholder for the extra credit
version and is not used here. */
bool Account::deposit(double amount, Date d) {
    // Check if the deposit amount is a positive value
    if (amount > 0) {
        balance += amount;
#ifdef EXTRA_CREDIT
        Transaction t;
        t.date = d;
        t.transactionType = 1;
        t.amount = amount;
        recordTransaction(t);
#else
        (void)d;
#endif
        return true;
    }
#ifndef EXTRA_CREDIT
    (void)d;
#endif
    return false;
}

/* This accessor function returns the account number of the account. */
int Account::getAccountNumber() const {
    return accountNumber;
}

/* This accessor function returns the current balance of the account. */
double Account::getBalance() const {
    return balance;
}

/* This static member function returns the total number of accounts that
have been created so far. */
int Account::getNumberAccounts() {
    return numberAccounts;
}

/* This function prints the account number, owner name, and balance of the
account in the required format with two decimal places. */
void Account::print() const {
    cout << fixed << setprecision(2);
    cout << "#: " << accountNumber
         << ", Name: " << ownerName
         << ", Balance: " << balance << " Galactic units" << endl;
}

#ifdef EXTRA_CREDIT
void Account::recordTransaction(Transaction t) {
    Transaction *newHistory = new Transaction[numberTransactions + 1];

    for (int i = 0; i < numberTransactions; i++) {
        newHistory[i] = transactionHistory[i];
    }

    newHistory[numberTransactions] = t;

    delete [] transactionHistory;
    transactionHistory = newHistory;
    numberTransactions++;
}

void Account::printTransactions() const {
    static const string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    cout << "Transaction history:" << endl;
    cout << "-------------------" << endl;

    double runningBalance = 0.0;
    cout << fixed << setprecision(2);
    for (int i = 0; i < numberTransactions; i++) {
        const Transaction &t = transactionHistory[i];

        if (t.transactionType == 2) {
            runningBalance -= t.amount;
        }
        else {
            runningBalance += t.amount;
        }

        cout << "Date: "
             << monthNames[t.date.getMonth()] << " "
             << t.date.getDay() << ", "
             << t.date.getYear() << ", "
             << t.date.getHour() << ":00"
             << ", Amount: " << t.amount
             << ", type: ";

        if (t.transactionType == 0) {
            cout << "Creation";
        }
        else if (t.transactionType == 1) {
            cout << "Deposit";
        }
        else {
            cout << "Withdrawal";
        }

        cout << ", New balance: " << runningBalance << endl;
    }
}
#endif