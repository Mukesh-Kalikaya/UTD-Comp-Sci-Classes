/* This file implements the Account class member functions. It stores account
owners and transactions using dynamic arrays as required by the lab. */
#include "Account.h"

/* Default constructor: set numeric values to 0 and pointers to nullptr. */
Account::Account() {
	accountNumber = 0;
	numOwners = 0;
	ownerPtr = nullptr;
	balance = 0;
	numTransactions = 0;
	transacPtr = nullptr;
}

/* Destructor frees dynamic owner and transaction arrays. */
Account::~Account() {
	delete [] ownerPtr;
	delete [] transacPtr;
}

/* This function sets account number and owners count, allocates owner array,
and initializes balance to zero. */
void Account::setAccount(int accountNumber_, int numOwners_) {
	accountNumber = accountNumber_;
	numOwners = numOwners_;
	balance = 0;

	if (ownerPtr != nullptr) {
		delete [] ownerPtr;
	}
	ownerPtr = new Person[numOwners];
}

/* This function sets the owner at the given index. */
void Account::setOwner(int ind, Person p) {
	ownerPtr[ind] = p;
}

/* This accessor returns the owner at index ind. */
Person Account::getOwner(int ind) const {
	return ownerPtr[ind];
}

/* This accessor returns account number. */
int Account::getAccountNumber() const {
	return accountNumber;
}

/* This accessor returns number of owners. */
int Account::getNumOwners() const {
	return numOwners;
}

/* This mutator stores the transaction array pointer. */
void Account::setTransacPtr(Transaction * transacPtr_) {
	transacPtr = transacPtr_;
}

/* This accessor returns number of transactions. */
int Account::getNumTransactions() const {
	return numTransactions;
}

/* This mutator sets number of transactions. */
void Account::setNumTransactions(int numTransactions_) {
	numTransactions = numTransactions_;
}

/* This accessor returns transaction at index ind. */
Transaction Account::getTransaction(int ind) const {
	return transacPtr[ind];
}
