/* This program reads numbers from a file that the user has specified and then
scans for valid numbers (values ranging from 18 to 60, including both) and 
then the program displays the total number of values read from the file, how 
many of those values are valid/invalid and then the average of the valid 
values. */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Define variables
    string fileName;
    ifstream inputFile;
    ofstream badFile;
    int totalCount = 0, validCount = 0, invalidCount = 0;
    double value, validSum = 0.0, average = 0.0;
    
    // Get the file name from the user
    cout << "Enter the input file name." << endl;
    getline(cin, fileName);
    
    // Open the file
    inputFile.open(fileName);
    
    // Check to see if the file can be opened
    if (!inputFile.is_open()) {
        cout << endl;
        cout << "Error, the file \"" << fileName << "\" could not be opened."
             << endl;
             
        return 0;
    }

    // Open the file for writing the bad values
    badFile.open("badvalues.txt");
    
    // Go through each value in the file and see if the value is valid 
    // or invalid
    while (inputFile >> value) {
        totalCount++;
        
        if (value >= 18 && value <= 60) {
            validCount++;
            validSum += value;
        } else {
            invalidCount++;
            badFile << fixed << setprecision(3) << value << endl;        }
    }
    
    // Close both files
    inputFile.close();
    badFile.close();
    
    // Output the total number of values read, the number of valid and also
    // the number of invalid values that were read in the file.
    cout << endl;
    cout << "Total number of values read: " << totalCount << endl;
    cout << "Valid values read: " << validCount << endl;
    cout << "Invalid values read: " << invalidCount << endl;
    
    // Output the average value of the values that were valid if any present
    // otherwise output a comment saying there were no valid values.
    if (validCount == 0) {
        cout << "The file did not contain any valid values." << endl;
    } else {
        average = validSum / validCount;
        cout << "The average of the valid numbers read is " << fixed
             << setprecision(1) << average << "." << endl;
    }

    return 0;
}