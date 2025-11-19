/* This program will get the radius from the user and calculates the volume 
and the surface area of the sphere using the radius that was given. This 
program utilizes two functions to calculate the volume and surface area. */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function Prototype ()
double findVolume(double radius);
double findSurfaceArea(double radius);

// Global declaration of PI for easier access in all functions
const double pi = acos(-1);

int main() {
    // Define variables
    double radius;
    
    // Get the radius from the user
    cout << "\t\tSphere Calculator" << endl << endl;
    cout << "Please enter the radius of a sphere: ";
    cin >> radius;
    
    // Verify if the radius is greater than 0 and either display the error
    // message or display the calculated volume or surface area
    if (radius > 0) {
        double volume = findVolume(radius);
        double surfaceArea = findSurfaceArea(radius);
        
        cout << fixed << showpoint << setprecision(3);
        cout << endl << "A sphere with a radius of " << radius << " has:" 
             << endl;
        cout << "\tVolume = " << volume << " cubic units." << endl;
        cout << "\tSurface area = " << surfaceArea << " square units." << endl;
        
    } else {
        cout << endl << "Error, the radius must be greater than 0!" << endl;
    }
    
    return 0;
}

// Calculates the volume of the sphere with the input of the radius
double findVolume(double radius) {
    double volume = (4.0 / 3.0) * pi * pow(radius, 3);
    
    return volume;
}

// Calculates the surface area of the sphere with the input of the radius
double findSurfaceArea(double radius) {
    double surfaceArea = (4.0) * pi * pow(radius, 2);
    
    return surfaceArea;
}