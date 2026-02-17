/* This program gets the dividend and divisor from the user and 
divides the numbers and shows the quotients fromfor the numbers */
#include <iostream>
using namespace std;

int main() {
	int dividend, divisor;
	int singleDivQuotient;
	double doubleDivQuotient;

   // User inputs the dividend
	cout << "Enter a whole number that is the dividend: ";
	cin >> dividend;
	
   // User inputs the divisor	
	cout << "Enter a whole number that is the divisor: ";
	cin >> divisor;

   // Show what is being divided by what
	cout << endl << "We will divide " << dividend << " by " << divisor << endl;

   // Single Division Quotient
   singleDivQuotient = dividend / divisor;
    
   // Double Division Quotient
   doubleDivQuotient = static_cast <double>(dividend) / divisor; 
    
   // Output single division results
	cout << endl << "The quotient of the integer division is: " << singleDivQuotient << endl;
	
	// Output double division results
	cout << "The quotient of the double division is: " << doubleDivQuotient << endl;

	return 0;
}