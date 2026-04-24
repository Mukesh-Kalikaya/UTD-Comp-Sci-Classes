/* This program reads account records from a file, dynamically creates an
array of Account objects, fills each account with owners and transactions,
then displays all data in the required format. */
#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"
using namespace std;

// Function prototypes
int getMonthFromString(string d);
int getDayFromString(string d);
int getYearFromString(string d);
int getHourFromString(string d);
bool readAccounts(string fname, Account accntPtr[], int numAccnts);
int countAccountsInFile(string fname);
void sortTransactions(Transaction tArray[], int size);
string getTypeAsString(int type);

/* This function takes a date string in mm/dd/yyyy/hh format and returns
the month value as int. */
int getMonthFromString(string d) {
	return stoi(d.substr(0, 2));
}

/* This function takes a date string in mm/dd/yyyy/hh format and returns
the day value as int. */
int getDayFromString(string d) {
	return stoi(d.substr(3, 2));
}

/* This function takes a date string in mm/dd/yyyy/hh format and returns
the year value as int. */
int getYearFromString(string d) {
	return stoi(d.substr(6, 4));
}

/* This function takes a date string in mm/dd/yyyy/hh format and returns
the hour value as int. */
int getHourFromString(string d) {
	return stoi(d.substr(11, 2));
}

/* This function counts how many account records are in the file by counting
the delimiter token #. */
int countAccountsInFile(string fname) {
	ifstream inFile(fname);
	if (!inFile) {
		return -1;
	}

	int count = 0;
	string token;
	while (inFile >> token) {
		if (token == "#") {
			count++;
		}
	}

	inFile.close();
	return count;
}

/* This function sorts a Transaction array by transaction date from oldest
to newest using simple bubble sort. */
void sortTransactions(Transaction tArray[], int size) {
	for (int pass = 0; pass < size - 1; pass++) {
		for (int i = 0; i < size - 1 - pass; i++) {
			if (tArray[i + 1].transactionDate < tArray[i].transactionDate) {
				Transaction temp = tArray[i];
				tArray[i] = tArray[i + 1];
				tArray[i + 1] = temp;
			}
		}
	}
}

/* This function converts the transaction type number to readable text. */
string getTypeAsString(int type) {
	if (type == 1) {
		return "account creation";
	}
	if (type == 2) {
		return "deposit";
	}
	return "withdrawal";
}

/* This function reads account records from file and populates the Account
array with owners and transactions data. */
bool readAccounts(string fname, Account accntPtr[], int numAccnts) {
	ifstream inFile(fname);
	if (!inFile) {
		return false;
	}

	for (int accntIndex = 0; accntIndex < numAccnts; accntIndex++) {
		string delimiter;
		int accountNumber;
		int numOwners;

		inFile >> delimiter;
		inFile >> accountNumber;
		inFile >> numOwners;

		accntPtr[accntIndex].setAccount(accountNumber, numOwners);

		for (int ownerIndex = 0; ownerIndex < numOwners; ownerIndex++) {
			Person p;
			string dateString;

			inFile >> p.name;
			inFile >> dateString;
			inFile >> p.address;

			int month = getMonthFromString(dateString);
			int day = getDayFromString(dateString);
			int year = getYearFromString(dateString);
			int hour = getHourFromString(dateString);
			p.DOB.set(month, day, year, hour);

			accntPtr[accntIndex].setOwner(ownerIndex, p);
		}

		int numTransactions;
		inFile >> numTransactions;
		accntPtr[accntIndex].setNumTransactions(numTransactions);

		Transaction *transactionPtr = new Transaction[numTransactions];

		for (int transac = 0; transac < numTransactions; transac++) {
			string dateString;
			inFile >> dateString >> transactionPtr[transac].type
				   >> transactionPtr[transac].amount;

			int month = getMonthFromString(dateString);
			int day = getDayFromString(dateString);
			int year = getYearFromString(dateString);
			int hour = getHourFromString(dateString);
			transactionPtr[transac].transactionDate.set(month, day, year, hour);
		}

		accntPtr[accntIndex].setTransacPtr(transactionPtr);
	}

	inFile.close();
	return true;
}

int main() {
	string fileName;

	cout << "Enter the account file name: ";
	cin >> fileName;

	int numAccounts = countAccountsInFile(fileName);
	if (numAccounts < 0) {
		cout << "File open failed" << endl;
		return 0;
	}

	cout << "There are " << numAccounts << " accounts in the file" << endl;
	cout << endl;
	cout << endl;

	Account *accountArray = new Account[numAccounts];

	if (!readAccounts(fileName, accountArray, numAccounts)) {
		cout << "File open failed" << endl;
		delete [] accountArray;
		return 0;
	}

	for (int i = 0; i < numAccounts; i++) {
		cout << "Account Number: " << accountArray[i].getAccountNumber() << endl;
		cout << "===============" << endl;

		for (int j = 0; j < accountArray[i].getNumOwners(); j++) {
			Person p = accountArray[i].getOwner(j);
			cout << "Name: " << p.name << ", DOB: ";
			p.DOB.print();
			cout << ", Address: " << p.address << endl;
			cout << endl;
		}

		cout << "Transaction history:" << endl;
		cout << "--------------------" << endl;

		double runningBalance = 0;
		for (int t = 0; t < accountArray[i].getNumTransactions(); t++) {
			Transaction trans = accountArray[i].getTransaction(t);

			if (trans.type == 1 || trans.type == 2) {
				runningBalance += trans.amount;
			} else {
				runningBalance -= trans.amount;
			}

			cout << "Transaction #" << t + 1 << endl;
			cout << "Date: ";
			trans.transactionDate.print();
			cout << ", type: " << getTypeAsString(trans.type)
				 << ", amount: " << trans.amount
				 << ", new balance: " << runningBalance << endl;
			cout << endl;
		}
	}

	delete [] accountArray;
	return 0;
}
