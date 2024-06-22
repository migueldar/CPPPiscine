#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

class Date {

private:
	int day;
	int month;
	int year;
	const static int dayspermonth[12];


public:

	class InvalidDate: public std::exception {
		virtual const char* what() const throw() {
			return "Error: invalid date";
		}
	};

	Date();
	Date(const std::string& date);
	Date(Date const& other);
	~Date();
	Date &operator=(Date const& rhs);
	bool operator<(Date const& rhs) const;
	bool operator==(Date const& rhs) const;
	bool validDate() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
};

std::ostream &operator<<(std::ostream &o, Date const &prt);

#endif
