/* This program demonstrates a Product class by reading grocery product
records from a file into a dynamically allocated object array. It prints all
products, allows the user to add or subtract inventory by PLU through a menu,
and displays up to the 5 most recent successful transactions on exit. */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Product.h"
using namespace std;

// Structure used to store each successful inventory transaction.
struct Transaction {
	int number;
	string plu;
	string type;
	int amount;
};

// Function prototypes
int countRecordsInFile(ifstream &inFile);
void loadProducts(ifstream &inFile, Product products[], int size);
void printProducts(Product products[], int size, string title);
void printMenu();
int findProductByPLU(Product products[], int size, string plu);
void printTransactionHistory(Transaction history[], int count);

int main() {
    // File handling
	string fileName;
	ifstream inFile;

	cout << "Enter the file name: ";
	cin >> fileName;

	inFile.open(fileName);

	if (!inFile) {
		cout << "Error: Could not open file" << endl;
		return 0;
	}

	int numRecords = countRecordsInFile(inFile);
	inFile.close();

	cout << "There are " << numRecords << " records in the file" << endl;
	cout << endl;

	Product *products = new Product[numRecords];

	inFile.open(fileName);
	loadProducts(inFile, products, numRecords);
	inFile.close();

	printProducts(products, numRecords, "Content of object array");

    // Define variables
	const int MAX_TRANSACTIONS = 1000;
	Transaction history[MAX_TRANSACTIONS];
	int transactionCount = 0;
	int transactionNumber = 0;

	int choice;

	do {
		cout << endl;
		printMenu();
		cin >> choice;

		if (choice == 1) {
			string plu;
			int amount;

			cout << "Enter the PLU: ";
			cin >> plu;

			int index = findProductByPLU(products, numRecords, plu);
			if (index == -1) {
				cout << "PLU not found" << endl;
			}
			else {
				cout << "Enter amount to add: ";
				cin >> amount;

				if (amount <= 0) {
					cout << "Amount must be > 0" << endl;
				}
				else {
					int newInventory = products[index].getInventory() + amount;
					products[index].setInventory(newInventory);

					if (transactionCount < MAX_TRANSACTIONS) {
						transactionNumber++;
						history[transactionCount].number = transactionNumber;
						history[transactionCount].plu = plu;
						history[transactionCount].type = "Add to inventory";
						history[transactionCount].amount = amount;
						transactionCount++;
					}
				}
			}
		}
		else if (choice == 2) {
			string plu;
			int amount;

			cout << "Enter the PLU: ";
			cin >> plu;

			int index = findProductByPLU(products, numRecords, plu);
			if (index == -1) {
				cout << "PLU not found" << endl;
			}
			else {
				cout << "Enter amount to subtract: ";
				cin >> amount;

				if (amount <= 0) {
					cout << "Amount must be > 0" << endl;
				}
				else {
					int currentInventory = products[index].getInventory();
					int actualSubtracted = amount;

					if (actualSubtracted > currentInventory) {
						actualSubtracted = currentInventory;
					}

					products[index].setInventory(currentInventory - actualSubtracted);

					if (transactionCount < MAX_TRANSACTIONS) {
						transactionNumber++;
						history[transactionCount].number = transactionNumber;
						history[transactionCount].plu = plu;
						history[transactionCount].type = "Subtract from inventory";
						history[transactionCount].amount = actualSubtracted;
						transactionCount++;
					}
				}
			}
		}
		else if (choice == 3) {
			cout << endl;
			printProducts(products, numRecords, "Current inventory");
		}
	} while (choice != 4);

	cout << endl;
	printTransactionHistory(history, transactionCount);

	delete [] products;
	return 0;
}

/* This function reads product records from an open file stream and counts how
many records are in the file. It takes an input file stream by reference and
returns the number of complete product records read from that stream. */
int countRecordsInFile(ifstream &inFile) {
    // Define variables
	string plu;
	string name;
	int type;
	double price;
	int inventory;
	int count = 0;

    // Reads all records in the files
	while (inFile >> plu >> name >> type >> price >> inventory) {
		count++;
	}

	return count;
}

/* This function reads product records from an open file stream and stores the
record values into an array of Product objects. It takes an input file stream,
the Product array, and the number of records to read, and uses the class
mutator to set each object's attributes. */
void loadProducts(ifstream &inFile, Product products[], int size) {
    // Define variables
	string plu;
	string name;
	int type;
	double price;
	int inventory;

    // Loads all records from the files 
	for (int i = 0; i < size; i++) {
		inFile >> plu >> name >> type >> price >> inventory;
		products[i].setProductAttributes(plu, name, type, price, inventory);
	}
}

/* This function prints all products in the object array using the required
output format. It takes the Product array, its size, and a section title. The
title is printed with an underline, the name is left-justified with width 17,
and the other fields are printed right-justified. */
void printProducts(Product products[], int size, string title) {
	cout << title << endl;
	for (int i = 0; i < title.length(); i++) {
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << "PLU: " << products[i].getPLU() << ", ";
		cout << left << setw(17) << products[i].getName();
		cout << right;
		cout << ", type: " << products[i].getType();
		cout << ", unit price: " << setw(5) << products[i].getPrice();
		cout << ", inventory: " << products[i].getInventory() << endl;
	}
}

/* This function displays the menu of choices for inventory transactions and
other program actions. */
void printMenu() {
    // Prints the menu in this format for the user to make transactions
	cout << "Menu" << endl;
	cout << "----" << endl;
	cout << "1->Add to inventory           , 2->Subtract from inventory" << endl;
	cout << "3->Print info for all products, 4->Exit" << endl;
}

/* This function performs a linear search on the Product array for a given
PLU code. It takes the Product array, the number of elements, and the PLU to
search for. The function returns the index where the PLU is found, or -1 if
the PLU does not exist in the array. */
int findProductByPLU(Product products[], int size, string plu) {
	for (int i = 0; i < size; i++) {
		if (products[i].getPLU() == plu) {
			return i;
		}
	}

	return -1;
}

/* This function prints the transaction history for successful inventory
updates. It takes the transaction array and the number of successful
transactions, then prints up to the 5 most recent transactions from most
recent to least recent. */
void printTransactionHistory(Transaction history[], int count) {
	cout << "History of transactions" << endl;
	cout << "-----------------------" << endl;

	int printed = 0;

    // Prints the transaction history for the user to see the 5 latest
    // transactions
	for (int i = count - 1; i >= 0 && printed < 5; i--) {
		cout << "Transaction #: " << history[i].number
			 << ", PLU: " << history[i].plu
			 << ", type: " << history[i].type
			 << ", amount: " << history[i].amount << endl;
		printed++;
	}
}