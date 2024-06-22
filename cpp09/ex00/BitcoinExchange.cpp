#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {
	std::ifstream	file(DATAFILE);
	std::string		line;
	Date			auxDate;
	std::string		value;
	float			auxValue;

	if (!file.is_open())
		throw CannotOpenDataFile();

	std::getline(file, line);
	while (!file.eof()) {
		std::getline(file, line);
		if (line == "")
			break ;
		auxDate = Date(line.substr(0, line.find_first_of(',')));
		value = line.substr(line.find_first_of(',') + 1);
		auxValue = atof(value.c_str());
		database[auxDate] = auxValue;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
	database = rhs.database;
	return (*this);
}

float BitcoinExchange::searchDate(Date d) const {
	return (database.lower_bound(d))->second;
}
