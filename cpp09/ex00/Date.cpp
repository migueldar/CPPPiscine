#include "Date.hpp"
#include <string>

const int Date::dayspermonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(): day(0), month(0), year(0) {}

Date::Date(const std::string& date) {
	std::string sday, smonth, syear;

	if (date.length() != 10)
		throw InvalidDate();
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-')
				throw InvalidDate();
		}
		else if (!isdigit(date[i]))
			throw InvalidDate();
	}

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());

	if (!validDate())
		throw InvalidDate();
}

Date::Date(Date const& other) {
	*this = other;
}

Date::~Date() {}

Date& Date::operator=(Date const& rhs) {
	day = rhs.day;
	month = rhs.month;
	year = rhs.year;

	return (*this);
}

//the days are ordered the opposite way, needed for the map
bool Date::operator<(Date const& rhs) const {
	if (year > rhs.year)
		return true;
	if (year < rhs.year)
		return false;
	if (month > rhs.month)
		return true;
	if (month < rhs.month)
		return false;
	if (day > rhs.day)
		return true;
	return false;
}

bool Date::operator==(Date const& rhs) const {
	return (day == rhs.day && month == rhs.month && year == rhs.year);
}

bool Date::validDate() const {
	if (month == 0 || month > 12 || day == 0)
		return false;
	if (month == 2 && year % 4 == 0) {
		if (day > 29)
			return false;
		else
			return true;
	}
	if (dayspermonth[month - 1] < day)
		return false;
	return true;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

std::ostream& operator<<(std::ostream& o, Date const& prt) {
	o << prt.getDay() << '-' << prt.getMonth() << '-' << prt.getYear();
	return (o);
}
