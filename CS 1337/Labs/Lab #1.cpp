/* This program runs and tests to see if a word is a Palindrome. Initially,
this program accepts an input of a word and then uses the function 
isPalindrome which accepts a string parameter, which in this case is the word 
that the user has entered. The function then checks to see if the string is a 
palindrome and returns a boolean value of true or false based on the word. */
#include <iostream>
#include <string>
using namespace std;

// Function Prototype
bool isPalindrome(string word);

int main() {
    // Define variables
    string word;
    
    // Gets the word from the user
    cin >> word;
    
    // Calls the isPalindrome function and checks the boolean value that it
    // returns
    if (isPalindrome(word)) {
        // This is shown to the user if the function returns true and the word
        // is a palindrome.
        cout << "The given string is a palindrome." << endl;
    } else {
        // This is shown to the user if the function returns false and the word
        // is not a palindrome.
        cout << "The given string is not a palindrome." << endl;
    }
    
    // End of the program
    return 0;
}

/* This function is used to compare the characters of the word that was entered
by the user and then determines whether the word is a palindrome or not */
bool isPalindrome(string word) {
    // Define the variable to store the length of the word
    int length = word.length();
    
    // Loops through only half of the string/word since each interation/run
    // through the loop compares two characters (one from each end of the word)
    for (int i = 0; i < length / 2; i++) {
        // Compares the character at position i with the equivalent character
        // from the other end of the string
        if (word[i] != word[length - i - 1]) {
            // If any of the characters don't match, the word is not a 
            // palindrome and therefore the function returns false
            return false;
        }
    }
    
    // If the loop has finished successfully and all of the characters match,
    // the function then returns true
    return true;
}