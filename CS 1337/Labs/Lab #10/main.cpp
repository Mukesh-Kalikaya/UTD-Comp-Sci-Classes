/* This program demonstrates an Account class using a menu-driven bank
account manager. It stores dynamically allocated Account objects in a global
array of pointers, supports account create/deposit/withdraw/display, and
includes extra credit options for owner/account deletion and owner addition. */
#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;

const int MAX_NUM_ACCOUNTS = 4;
Account * accountArray[MAX_NUM_ACCOUNTS];

// Function prototypes
int findAccountIndex(int accountNumber);
int findFirstAvailableIndex();
void displayMenu();
Person readPersonInfo();
void displayAllAccounts();

/* This function performs a linear search on accountArray for a given account
number. It returns the matching index or -1 if no match is found. */
int findAccountIndex(int accountNumber) {
	for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
		if (accountArray[i] != nullptr && accountArray[i]->getAccountNumber() == accountNumber) {
			return i;
		}
	}
	return -1;
}

/* This function returns the first available index in accountArray that
contains nullptr. It returns -1 if the array is full. */
int findFirstAvailableIndex() {
	for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
		if (accountArray[i] == nullptr) {
			return i;
		}
	}
	return -1;
}

/* This function prints the required menu format. */
void displayMenu() {
	cout << "Menu" << endl;
	cout << "----" << endl;
	cout << "1->Create account 2->Deposit   3->Withdraw     4->Display " << endl;
	cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit    " << endl;
}

/* This function reads one owner's information from the user and returns a
Person structure containing name, DOB, and address. */
Person readPersonInfo() {
	Person p;

	cout << "Enter owner's name: ";
	getline(cin >> ws, p.name);

	cout << "Enter owner's DOB, month, day then year: ";
	cin >> p.DOB.month >> p.DOB.day >> p.DOB.year;

	cout << "Enter owner's address: ";
	getline(cin >> ws, p.address);

	return p;
}

/* This function displays all active accounts with their owners and balances
using the required output format. */
void displayAllAccounts() {
	cout << fixed << setprecision(2);

	for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
		if (accountArray[i] != nullptr) {
			Account * current = accountArray[i];
			cout << "Account Number: " << current->getAccountNumber() << endl;
			cout << "--------------" << endl;

			for (int ownerIndex = 0; ownerIndex < current->getNumOwners(); ownerIndex++) {
				Person owner = current->getOwner(ownerIndex);
				cout << "*Name: " << owner.name << ", DOB: "
					 << owner.DOB.month << "/" << owner.DOB.day << "/" << owner.DOB.year << endl;
				cout << "Address: " << owner.address << endl;
			}

			cout << "*Balance: $" << current->getBalance() << " " << endl;
		}
	}
}

int main() {
	// Initialize all account pointers to nullptr.
	for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
		accountArray[i] = nullptr;
	}

	int choice = 0;

	do {
		displayMenu();
		cin >> choice;

		if (choice == 1) {
			// Create account if there is available space in accountArray.
			int openIndex = findFirstAvailableIndex();
			if (openIndex == -1) {
				cout << "Max number of accounts reached, cannot add a new account" << endl;
				continue;
			}

			int numberOwners;
			double amount;

			// Read account creation data and allocate dynamically.
			cout << "Enter number of owners: ";
			cin >> numberOwners;
			cout << "Enter amount: ";
			cin >> amount;

			accountArray[openIndex] = new Account(numberOwners, amount);

			for (int ownerIndex = 0; ownerIndex < numberOwners; ownerIndex++) {
				Person p = readPersonInfo();
				accountArray[openIndex]->setOwner(ownerIndex, p);
			}

			cout << "Account #" << accountArray[openIndex]->getAccountNumber() << " created" << endl;
		}
		else if (choice == 2) {
			// Deposit to an existing account after account number validation.
			int accountNumber;
			double amount;

			cout << "Enter account number: ";
			cin >> accountNumber;

			int foundIndex = findAccountIndex(accountNumber);
			if (foundIndex == -1) {
				cout << "No such account" << endl;
				continue;
			}

			cout << "Enter amount: ";
			cin >> amount;

			int result = accountArray[foundIndex]->deposit(amount);
			if (result == 1) {
				cout << "Amount cannot be negative, deposit not executed" << endl;
			} else {
				cout << fixed << setprecision(2);
				cout << "New balance is $" << accountArray[foundIndex]->getBalance() << endl;
			}
		}
		else if (choice == 3) {
			// Withdraw from an existing account after account number validation.
			int accountNumber;
			double amount;

			cout << "Enter account number: ";
			cin >> accountNumber;

			int foundIndex = findAccountIndex(accountNumber);
			if (foundIndex == -1) {
				cout << "No such account" << endl;
				continue;
			}

			cout << "Enter amount: ";
			cin >> amount;

			int result = accountArray[foundIndex]->withdraw(amount);
			if (result == 2) {
				cout << "Amount cannot be negative, withdrawal not executed" << endl;
			} else if (result == 1) {
				cout << "Insufficient balance, withdrawal not executed" << endl;
			} else {
				cout << fixed << setprecision(2);
				cout << "New balance is $" << accountArray[foundIndex]->getBalance() << endl;
			}
		} else if (choice == 4) {
			// Display all non-null accounts.
			displayAllAccounts();
		} else if (choice == 5) {
			// Extra credit: delete owner from an existing account.
			int accountNumber;
			cout << "Enter account number: ";
			cin >> accountNumber;

			int foundIndex = findAccountIndex(accountNumber);
			if (foundIndex == -1) {
				cout << "No such account" << endl;
				continue;
			}

			Person p = readPersonInfo();
			int result = accountArray[foundIndex]->delOwner(p);
			if (result == 2) {
				cout << "Cannot delete owner" << endl;
			} else if (result == 1) {
				cout << "Owner not found" << endl;
			} else {
				cout << "Owner deleted" << endl;
			} 
        } else if (choice == 6) {
			// Extra credit: add owner to an existing account.
			int accountNumber;
			cout << "Enter account number: ";
			cin >> accountNumber;

			int foundIndex = findAccountIndex(accountNumber);
			if (foundIndex == -1) {
				cout << "No such account" << endl;
				continue;
			}

			Person p = readPersonInfo();
			accountArray[foundIndex]->addOwner(p);
			cout << "Owner added" << endl;
		} else if (choice == 7) {
			// Extra credit: delete account and shift left to avoid gaps.
			int accountNumber;
			cout << "Enter account number: ";
			cin >> accountNumber;

			int foundIndex = findAccountIndex(accountNumber);
			if (foundIndex == -1) {
				cout << "No such account" << endl;
				continue;
			}

			delete accountArray[foundIndex];

			for (int i = foundIndex; i < MAX_NUM_ACCOUNTS - 1; i++) {
				accountArray[i] = accountArray[i + 1];
			}
			accountArray[MAX_NUM_ACCOUNTS - 1] = nullptr;
			cout << "Account deleted" << endl;
		}
	} while (choice != 8);

	// Release all remaining dynamically allocated Account objects before exit.
	for (int i = 0; i < MAX_NUM_ACCOUNTS; i++) {
		if (accountArray[i] != nullptr) {
			delete accountArray[i];
			accountArray[i] = nullptr;
		}
	}

	return 0;
}
