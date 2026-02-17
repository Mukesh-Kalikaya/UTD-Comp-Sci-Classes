/* This is a modular program that creates a file containing the Morse Code of
the text which is given using the input file. The program uses a pre-generated
file which contains all of the Morse Codes for each letter. The program uses 
the functions loadMorseArray() and genMorse() to convert text from the input
file into Morse Code. The function loadMorseArray() takes the Morse Codes 
that were generated and puts them in an array and the function genMorse()
converts each line from the input file and stores it in an array. This function 
uses the array that was created by loadMorseArray() to convert the letters
into Morse Code.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes
bool loadMorseArray(string[], ifstream&);
void genMorse(string&, const string, const string[]);

int main() {
    // Define variables
    string inputFileName, outputFileName;
    string morse[26];
    bool valid = true;
    int lineCount = 0;

    // Get the name of the input file
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;

    // Get the name of the output file
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    // Opens the files containing the Morse Codes, the input file,
    // and output file
    ifstream morseFile("morseLetters.txt");
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Checks to see if the Morse code file opened correctly
    if (!morseFile) {
        cout << "Error, unable to open file morseLetters.txt" << endl;
        valid = false;
    }

    // Checks to see if the input file opened correctly
    if (valid && !inputFile) {
        cout << "Error, unable to open file " << inputFileName << "." << endl;
        valid = false;
    }

    // If the files have opened properly, load the Morse Code into 
    // the array
    if (valid) {
        valid = loadMorseArray(morse, morseFile);
    }

    // Start the translation of the file
    if (valid) {
        // Define variables
        string line;
        string morseLine;

        // Read each line, convert the line to Morse code,
        // output the Morse Code to the output file and 
        // increment the number of translated lines to 
        // output to the user in the end.
        while (getline(inputFile, line)) {
            genMorse(morseLine, line, morse);
            outputFile << morseLine << endl;
            lineCount++;
        }
    }

    // Display the completion message and number of lines translated to the user.
    if (valid && lineCount > 0) {
        cout << "Translation complete. " << lineCount
             << " lines translated." << endl;
    }

    return 0;
}

/* This function reads Morse code from the file and then stores them 
in an array. The function takes in two arguments: an array of strings
which will hold the codes for all 26 letters of the alphabet and then 
a reference to the ifstream which is linked to the Morse Code file. */
bool loadMorseArray(string morse[], ifstream& inFile) {
    // Define variables
    char letter;
    string code;
    int count = 0;

    // Read each row of the Morse Code file and store them in the array
    while (count < 26 && inFile >> letter >> code) {
        morse[count] = code;
        count++;
    }

    return true;
}

/* This function converts a line of text from the input file and then converts
it into Morse Code. This function takes in three arguments: a reference to a
string that will hold the Morse Code, a string that holds a line of text from the 
input file if multiple exist, and then an array which contains the Morse Code for 
each letter which was created using the function loadMorseArray().*/
void genMorse(string& morseLine, const string line, const string morse[]) {
    morseLine = "";

    // Loop through each character in the input line from the input file
    for (unsigned int i = 0; i < line.length(); i++) {
        // Stores the character
        char ch = line[i];

        // Converts the letters/spaces/periods into Morse Code
        if (ch >= 'A' && ch <= 'Z') {
            morseLine += morse[ch % 'A'];
            morseLine += " ";
        } else if (ch == ' ' || ch == '.') {
            morseLine += ch;
        }
    }
}