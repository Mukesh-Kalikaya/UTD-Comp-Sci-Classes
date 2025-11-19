/* This program gets the two sides of a triangle from the user and finds 
the third side, the Hypotenuse, using the Pythagorean theorem and outputs
the Hypotenuse. */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Define all of the variables
    double firstSide, secondSide, hypotenuse;
    int x, y;
    
    // Ask the user to input the first side
    cout << "Enter first triangle side: ";
    cin >> firstSide;
    
    // Ask the user to input the second side
    cout << "Enter second triangle side: ";
    cin >> secondSide;
    
    // Apply Pythagorean theorem
    hypotenuse = sqrt(pow(firstSide, 2) + pow(secondSide, 2));
    
    // Output the Hypotenuse
    cout << fixed << setprecision(2);
    cout << "Hypotenuse: " << hypotenuse << endl;
    
    return 0;
}