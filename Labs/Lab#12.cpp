/* This program gets the date from the user and then displays which day of the 
year it is. This program uses three functions to do this: getValidDate,
isLeapYear, and getDayOfYear. Each function handles a key part of the program 
and makes the execution of the program easier.*/
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
bool getValidDate(int &month, int &day, int &year);
bool isLeapYear(int year);
int getDayOfYear(int month, int day, int year);

int main() {
    // Define variables
    int month, day, year;
    string monthName;
    int numberOfDays;
    
    // Check for a valid date
    bool valid = getValidDate(month, day, year);
    
    // If the date is valid, check which month it is and save it to
    // the variable monthName
    if (valid) {
        numberOfDays = getDayOfYear(month, day, year);
        
        if (month == 1) {
            monthName = "January";
        } else if (month == 2) {
            monthName = "February";
        } else if (month == 3) {
            monthName = "March";
        } else if (month == 4) {
            monthName = "April";
        } else if (month == 5) {
            monthName = "May";
        } else if (month == 6) {
            monthName = "June";
        } else if (month == 7) {
            monthName = "July";
        } else if (month == 8) {
            monthName = "August";
        } else if (month == 9) {
            monthName = "September";
        } else if (month == 10) {
            monthName = "October";
        } else if (month == 11) {
            monthName = "November";
        } else {
            monthName = "December";
        }
        
        // Output which day of the month the given day is
        cout << monthName << " " << day << " is day " << numberOfDays << " of " 
             << setfill('0') << setw(4) << year << "." << endl;
    }

    return 0;
}

/* This function checks whether the date entered is valid by checking for days, 
months and years not being less than 1 along with the days not being more than 
the maximum in that month like having 31 days in April when April only has 30
days. */
bool getValidDate(int &month, int &day, int &year) {
    // Define variables
    char slash1, slash2;
    int daysInMonth = 0;
    
    // Get the date from the user
    cout << "Enter a date [MM/DD/YYYY]: ";
    cin >> month >> slash1 >> day >> slash2 >> year;
    cout << endl;
    
    // Define how many days each month should have and if the month entered 
    // is over 12, output the error and end the program.
    if (month == 1 or month == 3 or month == 5 or
        month == 7 or month == 8 or month == 10 or month == 12) {
        daysInMonth = 31;
    } else if (month == 4 or month == 6 or month == 9 or month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {
        if (isLeapYear(year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else {
        cout << "Error: " 
             << setfill('0') << setw(2) << month << "/" 
             << setw(2) << day << "/" 
             << setw(4) << year 
             << " is not a valid date." << endl;
         
        return false;
    }
    
    // Verify the day entered is valid (is not less than 1 and is not greater 
    // than the days in that month).
    if (day < 1 || day > daysInMonth) {
        cout << "Error: " 
             << setfill('0') << setw(2) << month << "/" 
             << setw(2) << day << "/" 
             << setw(4) << year 
             << " is not a valid date." << endl;
         
        return false;
    }
        
    // Check if the year entered is valid
    if (year < 1) {
        cout << "Error: " 
             << setfill('0') << setw(2) << month << "/" 
             << setw(2) << day << "/" 
             << setw(4) << year 
             << " is not a valid date." << endl;
             
        return false;
    }
    
    return true;
}

/* This function checks if the given year is a leap year which then helps with 
the counting of which day it is in the year as leap years have an extra day.*/
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

/* This function calculates which day of the year the current day is by adding
30 or 31 days until the correct month and then returns the total days as the 
output for the function.*/
int getDayOfYear(int month, int day, int year) {
    // Define variables
    int totalDays = 0;
    
    // Add 30 or 31 days until the program reaches the required month
    if (month > 1) {
        totalDays += 31;
    } 
    if (month > 2) {
        if (isLeapYear(year)) {
            totalDays += 29;
        } else {
            totalDays += 28;
        }
    }
    if (month > 3) {
        totalDays += 31;
    } 
    if (month > 4) {
        totalDays += 30;
    } 
    if (month > 5) {
        totalDays += 31;
    } 
    if (month > 6) {
        totalDays += 30;
    } 
    if (month > 7) {
        totalDays += 31;
    } 
    if (month > 8) {
        totalDays += 31;
    } 
    if (month > 9) {
        totalDays += 30;
    } 
    if (month > 10) {
        totalDays += 31;
    } 
    if (month > 11) {
        totalDays += 30;
    } 
    if (month == 12) {
        totalDays += 31;
    }
    
    // Add the current day to the total days
    totalDays += day;
    
    return totalDays;
}