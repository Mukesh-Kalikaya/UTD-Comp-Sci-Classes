/*This program gets two words or phrases as input from the user,
finds the first character of each phrase or word, concatenates
them together and then also finds the middle character of the
concatenated string. */
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Define all of the variables.
    string firstWord, secondWord;
    char firstChar, secondChar;
    string firstCombined, secondCombined;
    int firstLength, secondLength;
    char firstMiddle, secondMiddle;
    
    // Get the first phrase from the user
    cout << "Please enter a word or phrase." << endl;
    getline(cin, firstWord);
    
    // Get the second phrase from the user
    cout << "Enter a second word or phrase." << endl;
    getline(cin, secondWord);
    
    // Find the first character of each phrase or word
    firstChar = firstWord.at(0);
    secondChar = secondWord.at(0);
    
    // Combine the two words or phrases
    firstCombined = firstWord + secondWord;
    secondCombined = secondWord + firstWord;
    
    // Get the location of the middle character
    firstLength = (firstCombined.length()) / 2;
    secondLength = (firstCombined.length()) / 2;
    
    // Find the middle character of the concatenated
    // strings
    firstMiddle = firstCombined.at(firstLength);
    secondMiddle = secondCombined.at(secondLength);
    
    // Output the first character of each word or phrase
    cout << endl << "The first character of \"" << firstWord 
         << "\" is: " << firstChar << endl;
    cout << "The first character of \"" << secondWord 
         << "\" is: " << secondChar << endl;
    
    // Output the first concatenated string and it's middle character
    cout << endl << "The second string concatenated after the last ";
    cout << "character of the first string is:" << endl;
    cout << "\t" << firstCombined << endl;
    cout << "\tThe middle character of this string is: " << firstMiddle 
         << endl;
    
    // Output the second concatenated string and it's middle character
    cout << "The first string concatenated after the last character ";
    cout << "of second string is:" << endl;
    cout << "\t" << secondCombined << endl;
    cout << "\tThe middle character of this string is: " << secondMiddle 
         << endl;
    
    return 0;
}