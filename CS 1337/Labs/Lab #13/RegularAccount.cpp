/* This file implements the member functions of the RegularAccount class,
which is derived from the Account base class. It passes the constructor
arguments to the base class and overrides the print function to display
the account type before printing the account details. */
#include "RegularAccount.h"
#include <iostream>
using namespace std;

/* This constructor passes the owner name, balance, and date arguments
directly to the Account base class constructor to initialize the
account's member variables. */
RegularAccount::RegularAccount(string nam, double amnt, Date d)
    : Account(nam, amnt, d) {
}

/* This function prints "Regular account" followed by the account number,
owner name, and balance by calling the print function of the Account
base class. */
void RegularAccount::print() const {
    cout << "Regular account, ";
    this->Account::print();
}