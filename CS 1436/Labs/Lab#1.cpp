/* A program that gets two whole numbers from the user and finds and displays the following:
   the difference between the first and second numbers entered, the quotient produced when
   the first number entered is divided by the second, and finally the
   remainder produced when the first number entered is divided by the second.
*/
#include <iostream>
using namespace std;

int main() {
    // Write a statement or statements below this comment to define three variables of data type int.
    int wholeNumberOne, wholeNumberTwo, x;
    
    // Write a statement below to get a whole number from the user and store it in one
    // of the variables defined above.

    cout << "Please enter a whole number: ";
    cin >> wholeNumberOne;

    // Write a statement below to get a second whole number from the user and store it in one of the
    // unused variables defined above.

    cout << "Please enter another whole number: ";
    cin >> wholeNumberTwo;

    // Write a statement below this comment to find the difference between the first whole number entered
    // and the second whole number entered and assign the result to the unused variable.

    x = wholeNumberOne - wholeNumberTwo;

    // Add a statement(s) to display the calculated difference after the message displayed below and then advance
    // to a new line of the computer screen.

    cout << "\nThe difference is: " << x;

    // Write statements below this comment to find the quotient produced when the first number entered is divided
    // by the second and assign the result to your third variable.

    x = wholeNumberOne / wholeNumberTwo;

    // Add a statement(s) to display the calculated quotient after the message displayed below and then advance
    // to a new line of the computer screen.

    cout << "\nThe quotient is: " << x;

    // Write a statement below this comment to find the remainder produced when the first number entered is divided
    // by the second and assign the result to your third variable.

    x = wholeNumberOne % wholeNumberTwo;

    // Add a statement(s) to display the calculated remainder after the message displayed below and then advance
    // to a new line of the computer screen.

    cout << "\nThe remainder of the division is: " << x << endl;

    return 0;
}