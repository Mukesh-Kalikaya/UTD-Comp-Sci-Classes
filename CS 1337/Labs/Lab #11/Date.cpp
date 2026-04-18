/* This file implements the Date class. It stores a month, day, year, and
hour, compares dates chronologically, subtracts dates in hours, and prints a
date in a readable format. */
#include <iostream>
#include "Date.h"
using namespace std;

// Function prototypes
bool isLeapYear(int year);
int daysBeforeMonth(int month, int year);
int leapYearsBeforeYear(int year);

/* This function sets the month, day, year, and hour values of the Date
object. */
void Date::set(int month_, int day_, int year_, int hour_) {
	month = month_;
	day = day_;
	year = year_;
	hour = hour_;
}

/* This function returns true if two Date objects have the same month, day,
year, and hour values. */
bool Date::operator==(const Date & rhs) {
	return month == rhs.month && day == rhs.day && year == rhs.year
		   && hour == rhs.hour;
}

/* This function returns true if the current Date object comes before the
right-hand-side Date object chronologically. */
bool Date::operator<(const Date & rhs) {
	if (year != rhs.year) {
		return year < rhs.year;
	}
	if (month != rhs.month) {
		return month < rhs.month;
	}
	if (day != rhs.day) {
		return day < rhs.day;
	}
	return hour < rhs.hour;
}

/* This function returns true if the current Date object is less than or equal
to the right-hand-side Date object. */
bool Date::operator<=(const Date & rhs) {
	return *this == rhs || *this < rhs;
}

/* This function returns the number of hours between two dates. If the current
date is later than the right-hand-side date, the result is negative. */
int Date::operator-(const Date & rhs) {
	return calcElapsedTime(*this) - calcElapsedTime(rhs);
}

/* This function prints the date in the format Month dd, yyyy, hh:00. */
void Date::print() {
	string monthName[13] = {"", "January", "February", "March", "April",
							 "May", "June", "July", "August", "September",
							 "October", "November", "December"};

	cout << monthName[month] << " " << day << ", " << year << ", "
		 << hour << ":00";
}

/* This function returns true if the given year is a leap year. */
bool isLeapYear(int year) {
	if (year % 400 == 0) {
		return true;
	}
	if (year % 100 == 0) {
		return false;
	}
	return year % 4 == 0;
}

/* This function returns the number of days before the given month in the
specified year. */
int daysBeforeMonth(int month, int year) {
	int days[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

	if (month > 2 && isLeapYear(year)) {
		return days[month] + 1;
	}

	return days[month];
}

/* This function returns the number of leap years before the given year. */
int leapYearsBeforeYear(int year) {
	int previousYear = year - 1;
	return previousYear / 4 - previousYear / 100 + previousYear / 400;
}

/* This function converts a Date object into the total number of elapsed hours
from 01/01/0001/00. */
int Date::calcElapsedTime(Date d) {
	int days = 365 * (d.year - 1) + leapYearsBeforeYear(d.year)
			   + daysBeforeMonth(d.month, d.year) + (d.day - 1);

	return days * 24 + d.hour;
}
