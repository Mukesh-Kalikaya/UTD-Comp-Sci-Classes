/* This program is used to convert a compass heading into a conventional 
bearing which has three components: the direction you face which 
corresponds to North or South, an angle from 0 to 90 degrees, and
the direction you wallk which corresponds to East or West. The 
function takes in a heading angle and then uses two functions to 
validate and convert the heading into conventional bearing format. 
The user inputs a degree from 0 to 360, the program then validates
the input to check if its within 0 to 360 and it then converts
the heading into a conventional bearing and then outputs that to 
the user using the function getBearing(). */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function Prototypes
void getBearing(double heading, string &facingDirection, double &angle, 
                string &walkingDirection);
double getValidHeading();

int main() {
    // Define variables
    double heading = getValidHeading(), angle;
    string faceDirection, walkDirection;

    // Converts the heading into a conventional bearing
    getBearing(heading, faceDirection, angle, walkDirection);

    // Output the conventional bearing to the user with one decimal place
    cout << fixed << setprecision(1);
    cout << faceDirection << " " << angle << " degrees " << walkDirection 
         << endl;

    return 0;
}

/* This function asks the user for a heading between values 0 to 360, including 
these values, checks to see if the input is valid and then asks the user 
repeatedly to enter a valid degree if the intiial value is invalid. It then
returns the heading that the user enters.*/
double getValidHeading() {
    // Define variables
    double heading;

    // Get the heading from the user
    cout << "Enter a compass heading [0-360 degrees]: ";
    cin >> heading;

    // Validates the heading and either returns the heading or 
    // keeps the loop running until a valid heading is entered
    while (heading < 0 || heading > 360) {
        cout << "\nError invalid heading entered." << endl;
        cout << "Enter a compass heading [0-360 degrees]: ";
        cin >> heading;
    }

    return heading;
}

/* This function takes in 4 arguments which are used to convert the heading 
into a conventional bearing. One is the heading, 2nd one is a pass-by-reference 
value to the facing direction variable which corresponds to the North or South 
direction. The 3rd variable is also a pass-by-reference to the walking direction 
which corresponds to either East or West of the bearing. The last variable is 
another pass-by-reference variable to the angle. All 3 of these references are 
updated based on the heading.*/
void getBearing(double heading, string &facingDirection, double &angle, 
                string &walkingDirection) {
    // If heading is equal to 360 degrees, convert it to 0 degrees
    if (heading == 360) {
        facingDirection = "North";
        angle = 0.0;
        walkingDirection = "West";
        return;
    }

    // Converts the heading to a conventional bearing based on the constraints 
    // and updates the variables based on the quadrant in which the heading is in
    if (heading >= 0 && heading <= 90) {
        facingDirection = "North";
        angle = heading;
        walkingDirection = "East";
    } else if (heading > 90 && heading <= 180) {
        facingDirection = "South";
        angle = 180 - heading;
        walkingDirection = "East";
    } else if (heading > 180 && heading < 270) {
        facingDirection = "South";
        angle = heading - 180;
        walkingDirection = "West";
    } else {
        facingDirection = "North";
        angle = 360 - heading;
        walkingDirection = "West";
    }
}