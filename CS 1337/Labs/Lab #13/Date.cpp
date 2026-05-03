/* This file implements the member functions of the Date class. It provides
a way to set and retrieve the date fields, and to print the date in a
formatted string that shows the full month name, day, year, and hour. */
#include "Date.h"
#include <iomanip>
using namespace std;

/* This function sets the month, day, year, and hour member variables
to the values that are passed in as parameters. */
void Date::set(int month_, int day_, int year_, int hour_) {
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;
}

/* This function prints the date in the format "Month dd, yyyy, hh:00".
It uses an array of month name strings to convert the integer month
value into its corresponding full month name. */
void Date::print() const {
    // Array of month names used to convert the integer month to a string
    string monthNames[] = { "", "January", "February", "March", "April",
                            "May", "June", "July", "August", "September",
                            "October", "November", "December" };

    cout << monthNames[month] << " " << setfill('0') << setw(2) << day
         << ", " << year << ", " << setw(2) << hour << ":00";

    // Reset fill character to avoid impacting subsequent output.
    cout << setfill(' ');
}

/* This accessor function returns the value stored in the month variable. */
int Date::getMonth() const {
    return month;
}

/* This accessor function returns the value stored in the day variable. */
int Date::getDay() const {
    return day;
}

/* This accessor function returns the value stored in the year variable. */
int Date::getYear() const {
    return year;
}

/* This accessor function returns the value stored in the hour variable. */
int Date::getHour() const {
    return hour;
}