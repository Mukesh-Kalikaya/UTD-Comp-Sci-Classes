/* This program gets initials from the user, shows their ASCII code values, 
adds one and then displays the new values */
#include <iostream>
using namespace std;

int main() {
    char firstInitial, secondInitial;
    int firstInitialValue, secondInitialValue;
    int newFirstInitialValue, newSecondInitialValue;
    char newFirstInitial, newSecondInitial;
    
    // Get the user input for the initials
    cout << "Enter your first initial: ";
    cin >> firstInitial;
    cout << "Enter your last initial: ";
    cin >> secondInitial;
    
    // Convert char to the relative code
    firstInitialValue = static_cast <int>(firstInitial);
    secondInitialValue = static_cast <int>(secondInitial);
    
    // Add 1 to the code
    newFirstInitialValue = firstInitialValue + 1;
    newSecondInitialValue = secondInitialValue + 1;
    
    // Convert the new value to its respective char
    newFirstInitial = static_cast <char>(newFirstInitialValue);
    newSecondInitial = static_cast <char>(newSecondInitialValue);
    
    // Display the new first initial
    cout << endl << firstInitial << " has code " << firstInitialValue << endl;
    cout << firstInitialValue << " plus one is " << newFirstInitialValue;
    cout << " which is the character " << newFirstInitial << endl;
    
    // Display the new second Initial
    cout << endl << secondInitial << " has code " << secondInitialValue << endl;
    cout << secondInitialValue << " plus one is " << newSecondInitialValue;
    cout << " which is the character " << newSecondInitial << endl;
    
    return 0;
}