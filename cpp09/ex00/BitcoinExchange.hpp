#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include "Date.hpp"

#define DATAFILE "data.csv"

class BitcoinExchange {

private:
	std::map<Date, float> database;

public:

	class CannotOpenDataFile: public std::exception {
		virtual const char* what() const throw() {
			return "Error: cannot open data file";
		}
	};
	class DateNotInDatabase: public std::exception {
		virtual const char* what() const throw() {
			return "Error: date not in database";
		}
	};

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& other);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const& rhs);
	float searchDate(Date d) const;
};

#endif
