/* This function gets an angle from the user and then converts it into 
radians and then proceeds to find the cosine, sine, and tangent values of 
the angle using the converted radian value */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Define variables
    double angle;
    double radians, cosine, sine, tangent, PI;
    
    // Ask the user for the angle input
    cout << "Enter an angle in degrees (between 0 and 90): ";
    cin >> angle;
    cout << endl;
    
    // Compute PI
    PI = acos(-1);
    
    // Compute Cosine, Sine, and the Tangent values
    radians = angle * (PI / 180);
    cosine = cos(radians);
    sine = sin(radians);
    tangent = tan(radians);

    // Output top line of the table
    cout << setw(11) << "Angle|" << setw(11) << "Angle|" << endl;
    
    // Output the middle line of the table
    cout << setw(11) << "Degrees|" << setw(11) << "Radians|" << setw(11)
         << "Cosine|" << setw(11) << "Sine|" << setw(10) << "Tangent" << endl;
         
    // Output the final line of the table which contains the values
    cout << right << setw(10) << angle << "|";
    cout << right << setw(10) << radians << "|";

    cout << fixed << setprecision(4);
    cout << right << setw(10) << cosine << "|";
    cout << right << setw(10) << sine << "|";
    cout << right << setw(10) << tangent << endl;
    
    return 0;
}