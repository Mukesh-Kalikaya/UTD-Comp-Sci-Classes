/* This file implements the Date class for Lab #12. It stores month, day,
year, and hour, compares two dates chronologically, and prints the date in
the required format. */
#include "Date.h"

string Date::monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

/* This function sets the month, day, year, and hour of the Date object. */
void Date::set(int month_, int day_, int year_, int hour_) {
	month = month_;
	day = day_;
	year = year_;
	hour = hour_;
}

/* This overloaded operator returns true if the current date comes before
the right-hand-side date chronologically. */
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

/* This function prints the Date in the format Month dd, yyyy, hh:00. */
void Date::print() const {
	cout << monthName[month - 1] << " " << day << ", " << year << ", "
		 << hour << ":00";
}

/* This accessor returns the month value. */
int Date::getMonthFromDate() const {
	return month;
}

/* This accessor returns the day value. */
int Date::getDayFromDate() const {
	return day;
}

/* This accessor returns the year value. */
int Date::getYearFromDate() const {
	return year;
}

/* This accessor returns the hour value. */
int Date::getHourFromDate() const {
	return hour;
}
