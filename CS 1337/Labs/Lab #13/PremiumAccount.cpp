/* This file implements the member functions of the PremiumAccount class,
which is derived from the Account base class. It overrides the withdraw
function to enforce a minimum balance requirement, and overrides the
print function to display the account type before printing the details. */
#include "PremiumAccount.h"
#include <iostream>
using namespace std;

// Initialize the static minimum balance requirement for premium accounts
const double PremiumAccount::MIN_BALANCE = 1000.0;

/* This constructor passes the owner name, balance, and date arguments
directly to the Account base class constructor to initialize the
account's member variables. */
PremiumAccount::PremiumAccount(string nam, double amnt, Date d)
    : Account(nam, amnt, d) {
}

/* This function checks if the existing balance is greater than or equal
to the withdrawal amount plus the minimum required balance. If the
condition is met, the withdrawal is processed and the function returns
true. If the condition is not met, no withdrawal is made and the
function returns false. The date parameter is a placeholder for the
extra credit version and is not used here. */
bool PremiumAccount::withdraw(double amnt, Date d) {
    // Check if the balance will remain at or above the minimum after withdrawal
    if (balance >= amnt + MIN_BALANCE) {
        balance -= amnt;
#ifdef EXTRA_CREDIT
        Transaction t;
        t.date = d;
        t.transactionType = 2;
        t.amount = amnt;
        recordTransaction(t);
#endif
        return true;
    }
    return false;
}

/* This static member function returns the minimum balance that is
required to be maintained in a premium account. */
double PremiumAccount::getMinBalance() {
    return MIN_BALANCE;
}

/* This function prints "Premium account" followed by the account number,
owner name, and balance by calling the print function of the Account
base class. */
void PremiumAccount::print() const {
    cout << "Premium account, ";
    this->Account::print();
}