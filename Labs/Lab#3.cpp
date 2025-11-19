/* This program asks the user for the amount of seconds 
and converts that into hours, minutes, and seconds */
#include <iostream>
using namespace std;

int main() {
    // Define all of the variables
    int const SEC_PER_MIN = 60;
    int const SEC_PER_HOUR = 60 * SEC_PER_MIN;
    int secondsGiven, remainingSeconds;
    int convertedSeconds, convertedMinutes, convertedHours;
    
    // Output instructions and ask the user for the seconds.
    cout << "This program converts a time entered in seconds to" 
         << " hours, minutes, and seconds." << endl;
    cout << "Please enter a time in seconds: ";
    cin >> secondsGiven;
    
    // Convert the seconds to hours
    convertedHours = secondsGiven / SEC_PER_HOUR;
    remainingSeconds = secondsGiven % SEC_PER_HOUR;
    
    // Convert the remaining seconds to minutes
    convertedMinutes = remainingSeconds / SEC_PER_MIN;
    
    // Assign the leftover seconds to seconds
    convertedSeconds = remainingSeconds % SEC_PER_MIN;
    
    // Output the converted time
    cout << endl << secondsGiven << " seconds is:" << endl;
    cout << "\t" << convertedHours << " hours" << endl;
    cout << "\t" << convertedMinutes << " minutes" << endl;
    cout << "\t" << convertedSeconds << " seconds" << endl;
    
    return 0;
}