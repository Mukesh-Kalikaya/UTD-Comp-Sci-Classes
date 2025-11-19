/* This function reads a file that is given by the user which contains sales 
data from a chain of stores. It then outputs a chart which contains the store
number, the sales amount, and then the symbol '$' which corresponds to the 
sales amount in thousands. The program uses 3 functions: one to check if the 
file can be opened (openFile) which returns a boolean value, one to process the 
sales amount and output the chart (processSales) and one to display the '$' 
based on the sale amount.*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
bool openFile(ifstream &inputFile, string &fileName);
bool processSales(ifstream &inputFile);
void displayBar(double sales);

int main() {
    // Define variables
    ifstream inputFile;
    string fileName;
    
    // Get the name of the file from the user
    cout << "Enter the name of the file that contains the sales data." 
         << endl;
    getline(cin, fileName);
    
    // Check to see if the file can be opened
    if (!openFile(inputFile, fileName)) {
        cout << "\nError, unable to open the input file." << endl;
        
        return 0;
    }
    
    // Title of the output
    cout << "\n\n\tSALES BARCHART - Each $ represents $1,000 in sales.\n\n";
    
    // Checks to see the files 
    if(!processSales(inputFile)) {
        cout << "\nUnable to read sales record from the file." << endl;
    }
    
    return 0;
}

/* This function checks to see if the file can be opened or not and then 
returns a boolean value of true or false based on the file. It has two 
parameters that need to be entered and it outputs a boolean value as mentioned 
above. */
bool openFile(ifstream &inputFile, string &fileName) {
    // Tries to open the file
    inputFile.open(fileName);
    
    // Returns true or false if the file is open or closed respectively
    if (inputFile) {
        return true;
    } else {
        return false;
    }
}

/* This function reads the values from the input file which contain the store 
numbers and the same amounts. It takes in an ifstream preference as its 
parameter. For aech record found, it prints the store information and calls
the function displayBaar to show the amount of '$' signs which corresponds to 
the sales of that store (each $ represents $1000).*/
bool processSales(ifstream &inputFile) {
    // Define variables
    unsigned int storeNumber;
    double sales;
    bool dataPresent = false;
    
    
    while (inputFile >> storeNumber >> sales) {
        dataPresent = true;
        
        // Outputs store data
        cout << "Store Number:"<< right << setw(5) << storeNumber;
        cout << "\tSales:" << right << setw(10) << fixed << setprecision(2) 
             << sales << "\t";
        displayBar(sales);
        cout << endl;
    }
    
    // Close the file
    inputFile.close();
    
    // After displaying all of the data, return true or false if data is present
    // or not
    return dataPresent;
}

/* This function prints the '$' symbol representing the sale amount with each 
symbol representing $1000. It takes the sales value as a parameter and displays
the bar. It does not return anything.*/
void displayBar(double sales) {
    // Define variable
    int length = static_cast<int>(sales / 1000.0);
    
    // For loop to output the '$' symbol
    for (int i = 0; i < length; i++) {
        cout << "$";
    }
}