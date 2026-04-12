/* This file implements all Account class member functions. It handles
dynamic owner storage, account creation and numbering, deposit and withdrawal
operations, and extra credit owner add/delete behavior. */
#include "Account.h"

// Static account number generator starts at 1000.
int Account::accountCounter = 1000;

/* This constructor initializes a new account. It assigns the account number
from the static counter, stores the number of owners, allocates the owner
array dynamically, initializes the balance, and increments the counter. */
Account::Account(int numberOwners, double amount) {
	accountNumber = accountCounter;
	numOwners = numberOwners;
	ownerPtr = new Person[numOwners];
	balance = amount;
	accountCounter++;
}

/* This destructor releases the dynamically allocated owner array. */
Account::~Account() {
	delete [] ownerPtr;
}

/* This function withdraws money from the account if the amount is valid and
there is enough balance. Return values are 0 for success, 1 for insufficient
balance, and 2 for invalid amount. */
int Account::withdraw(double amnt) {
	if (amnt <= 0) {
		return 2;
	}
	if (amnt > balance) {
		return 1;
	}

	balance -= amnt;
	return 0;
}

/* This function deposits money into the account if the amount is valid.
Return values are 0 for success and 1 for invalid amount. */
int Account::deposit(double amnt) {
	if (amnt <= 0) {
		return 1;
	}

	balance += amnt;
	return 0;
}

/* This function sets the owner information at the given index in the owner
array. If the index is invalid, no update is done. */
void Account::setOwner(int ind, Person p) {
	if (ind >= 0 && ind < numOwners) {
		ownerPtr[ind] = p;
	}
}

/* This function returns the owner at the given index. If the index is out
of range, it returns an empty Person structure. */
Person Account::getOwner(int ind) const {
	if (ind >= 0 && ind < numOwners) {
		return ownerPtr[ind];
	}

	Person emptyPerson;
	emptyPerson.name = "";
	emptyPerson.address = "";
	emptyPerson.DOB.month = 0;
	emptyPerson.DOB.day = 0;
	emptyPerson.DOB.year = 0;
	return emptyPerson;
}

/* This function returns the account number. */
int Account::getAccountNumber() const {
	return accountNumber;
}

/* This function returns the current account balance. */
double Account::getBalance() const {
	return balance;
}

/* This function returns the number of owners of the account. */
int Account::getNumOwners() const {
	return numOwners;
}

/* This function adds a new owner at the end of the owner list. It allocates
a new owner array of the right size, copies all current owners, appends the
new owner, then replaces the old owner array. */
void Account::addOwner(Person p) {
	Person *newOwners = new Person[numOwners + 1];

	for (int i = 0; i < numOwners; i++) {
		newOwners[i] = ownerPtr[i];
	}
	newOwners[numOwners] = p;

	delete [] ownerPtr;
	ownerPtr = newOwners;
	numOwners++;
}

/* This function removes a matching owner from the owner list while keeping
relative order. Return values are 0 for success, 1 if owner is not found,
and 2 if delete cannot be performed because only one owner remains. */
int Account::delOwner(Person p) {
	if (numOwners <= 1) {
		return 2;
	}

	int deleteIndex = -1;
	for (int i = 0; i < numOwners; i++) {
		bool sameDOB = ownerPtr[i].DOB.month == p.DOB.month
					   && ownerPtr[i].DOB.day == p.DOB.day
					   && ownerPtr[i].DOB.year == p.DOB.year;

		if (ownerPtr[i].name == p.name
				&& ownerPtr[i].address == p.address
				&& sameDOB) {
			deleteIndex = i;
			break;
		}
	}

	if (deleteIndex == -1) {
		return 1;
	}

	Person *newOwners = new Person[numOwners - 1];
	int j = 0;
	for (int i = 0; i < numOwners; i++) {
		if (i != deleteIndex) {
			newOwners[j] = ownerPtr[i];
			j++;
		}
	}

	delete [] ownerPtr;
	ownerPtr = newOwners;
	numOwners--;
	return 0;
}
