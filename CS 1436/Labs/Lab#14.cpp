/* This program will get a line from the user and initially check to see if
the string that was entered is valid and if so, it then proceeds to count the 
amount of spaces and commas that were entered into the function. After 
calculating the amount of spaces and commas, the program then outputs the 
result to the */
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
string getString(string text);
bool isCommaOrSpace(char ch);

int main() {
    // Define variables
    string text;
    unsigned int count = 0;
    unsigned int i = 0;
    
    // Ask the user for input and get the input through the function.
    text = getString("Please enter a line of text.");
    
    // Count the amount of spaces and commas there are in the sentence.
    while (i < text.length()) {
        if (isCommaOrSpace(text.at(i))) {
            count++;
        }
        i++;
    }
    
    // Output the calculated amount of spaces and commas to the user.
    cout << endl << "The entered text contains " << count 
         << " commas and space characters." << endl;
    
    return 0;
}

/* This function gets the string from the user and then checks to see if the 
string that the user typed in is empty and if it is, output an error message 
and ask the user again until they enter a string with characters. */
string getString(string text) {
    // Define variables
    string userInput;
    
    // A do-while loop that keeps running until the user enters a valid string
    // as their input.
    do {
        cout << text << endl;
        getline(cin, userInput);
        
        if (userInput == "") {
            cout << endl << "Error, empty string received." << endl;
        }
    } while (userInput == "");
    
    // Return the user input
    return userInput;
}

/* This function checks to see if the character that is inputted into the 
function is either a comma or a space and returns a true if the character is 
either and false if the character is neither.*/
bool isCommaOrSpace(char ch) {
    if (ch == ',' || ch == ' ') {
        return true;
    } else {
        return false;
    }
}