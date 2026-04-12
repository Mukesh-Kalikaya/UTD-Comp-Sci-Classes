#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

/* This header defines the Date and Person structures and the Account class
used by the bank account program. */
#include <string>
using namespace std;

struct Date
{
    int month;
    int day;
    int year;
};

struct Person
{
    string name;
    Date DOB;
    string address;
};

class Account
{
private:
    // Definition of Account member variables
    static int accountCounter;
    int accountNumber;
    int numOwners;
    Person *ownerPtr;
    double balance;

public:
    Account(int, double);
    ~Account();
    int withdraw(double amnt);
    int deposit(double amnt);
    void setOwner(int, Person);
    Person getOwner(int) const;
    int getAccountNumber() const;
    double getBalance() const;
    int getNumOwners() const;
    void addOwner(Person);
    int delOwner(Person);
};

#endif // ACCOUNT_H_INCLUDED