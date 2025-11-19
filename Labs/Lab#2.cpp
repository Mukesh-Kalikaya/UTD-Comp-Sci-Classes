/* This program asks the user to input the time to complete a task 
in hours, minutes, and seconds and then converts the time to seconds */
#include <iostream>
using namespace std;

int main() {
    // Define the variables
    int hours, minutes, seconds, duration;
    
    // Output the text and get user input
    cout << "Enter the time to complete the task";
    cout << " in hours, minutes, and seconds." << endl;

    // Gets hours from user input
    cout << "Enter the hours: ";
    cin >> hours;

    // Gets minutes from user input
    cout << "Enter the minutes: ";
    cin >> minutes;

    // Gets seconds from user input
    cout << "Enter the seconds: ";
    cin >> seconds;
    
    // Convert the duration to seconds
    duration = (hours * 3600) + (minutes * 60) + seconds;
    
    // Output the duration in seconds
    cout << endl << "The duration in seconds is " << duration 
         << "." << endl;
    
    return 0;
}