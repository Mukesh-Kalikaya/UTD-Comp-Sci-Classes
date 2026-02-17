/* This program displays a menu containing different materials and calculates 
how long it takes for sound to travel through the materials given the distance 
input from the user */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Defines all variables
    unsigned int choice;
    double distance = 0, seconds = 0;
    const double wood = 12631.230;
    const double steel = 10614.815;
    const double water = 4714.572;
    const double air = 1125.334;
    
    // Shows the menu of choices to the user
    cout << "\tTime for Sound to Travel through a Medium given Distance" 
         << endl;
    cout << endl << "1 - Wood" << endl;
    cout << "2 - Steel" << endl;
    cout << "3 - Water" << endl;
    cout << "4 - Air" << endl;
    
    // Gets the medium (the choice) from the user
    cout << endl << "Enter the number of the medium: ";
    cin >> choice;
    
    // Checks for invalid medium values
    if (choice < 1 || choice > 4) {
        cout << "Error, invalid medium!" << endl;
        cout << "Please run the program again.";
        
        return 0;
    } else {
        cout << "Enter the distance to travel (in feet): ";
        cin >> distance;
    }
    
    // Checks for invalid distance
    if (distance > 0.0) {
        switch (choice) {
            case 1:
                seconds = distance / wood;
                cout << fixed << showpoint << setprecision(4);
                cout << endl << "In wood it will take " << seconds << " seconds to " 
                     << "travel " << setprecision (1) << distance << " feet." << endl;
                break;
            case 2:
                seconds = distance / steel;
                cout << fixed << showpoint << setprecision(4);
                cout << endl << "In steel it will take " << seconds << " seconds to "
                     << "travel " << setprecision(1) << distance << " feet." << endl;
                break;
            case 3:
                seconds = distance / water;
                cout << fixed << showpoint << setprecision(4);
                cout << endl << "In water it will take " << seconds << " seconds to "
                     << "travel " << setprecision (1) << distance << " feet." << endl;
                break;
            case 4:
                seconds = distance / air;
                cout << fixed << showpoint << setprecision(4);
                cout << endl << "In air it will take " << seconds << " seconds to "
                     << "travel " << setprecision(1) << distance << " feet." << endl;
                break;
        }
        
    } else {
        cout << "Input error! The distance must be greater than zero.";
    }

    
    return 0;
}