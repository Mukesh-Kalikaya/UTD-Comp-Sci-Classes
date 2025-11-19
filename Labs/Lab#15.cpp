/* This program gets an unspecified number of words or phrases from the user 
and writes the ASCII codes for each phrase or word that is entered by the user
and outputs the ASCII codes into an output file using ofstream. */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Define variables
    string fileName, phrase;
    ofstream outFile;
    
    // Decide the name of the output file
    cout << "Enter the name of the output file." << endl;
    getline(cin, fileName);
    
    // Try to open the file
    outFile.open(fileName);
    
    // If the file opens, execute the loop.
    if (outFile) {
        // Ask the user for a word or phrase.
        cout << "\nEnter a word or phrase [enter 123 to end input]." << endl;
        getline(cin, phrase);
        
        // Run this loop as long as the phrase entered is not 123.
        while (phrase != "123") {
            for (int i = 0; i < phrase.length(); i++) {
                outFile << static_cast<int>(phrase[i]) << " ";
            }
            outFile << endl;
            
            cout << "Enter another word or phrase [enter 123 to end input]." 
                 << endl;
            getline(cin, phrase);
        }
        
        outFile.close();
    } else {
        // Output this if the file is not able to be opened.
        cout << "\nError, unable to open the output file." << endl;
    }
    
    return 0;
}