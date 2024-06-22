#include "BitcoinExchange.hpp"

void	discardFirstLine(std::ifstream& in) {
	std::string dummie;

	std::getline(in, dummie);
}

int		countOcurrences(std::string& str, char c) {
	int cnt = 0;

	for (long unsigned i = 0; i < str.length(); i++)
		if (str[i] == c)
			cnt++;
	return cnt;
}

float	parseNumber(std::string& strnum) {
	float ret;

	if (countOcurrences(strnum, '.') > 1)
		throw std::exception();
	for (long unsigned i = 0; i < strnum.length(); i++)
		if (!std::isdigit(strnum[i]) && strnum[i] != '.')
			throw std::exception();
	if (strnum[0] == '.' || strnum.substr(0, strnum.find_first_of('.')).length() > 4)
		throw std::exception();
	ret = std::atof(strnum.c_str());
	if (ret > 1000)
		throw std::exception();
	return ret;
}

bool	solveLine(std::ifstream& in, BitcoinExchange& exchange) {
	std::string line;
	std::string strdate;
	std::string	stramount;
	Date		date;
	float		amount;
	float		value;

	std::getline(in, line);
	if (line == "")
		return false;
	if (line.length() <= 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
		std::cerr << "Error: bad input => " << line << std::endl;
		return true; 
	}
	
	strdate = line.substr(0, line.find_first_of('|') - 1);
	try {
		date = Date(strdate);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: bad date => " << strdate << std::endl;
		return true;
	}

	stramount = line.substr(line.find_first_of('|') + 2);
	try {
		amount = parseNumber(stramount);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: bad amount => " << stramount << std::endl;
		return true;
	}
	
	try {
		value = exchange.searchDate(date);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << ": "<< strdate << std::endl;
		return true;
	}
	std::cout << strdate << " => " << amount << " = " << value * amount << std::endl;
	return true;
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "usage: ./btc FILE" << std::endl;
		return 1;
	}
	
	std::ifstream	in(argv[1]);
	if (!in.is_open()) {
		std::cerr << "Error: infile couldnt be opened" << std::endl;
		return 1;
	}
		
	discardFirstLine(in);
	try {
		BitcoinExchange exchange;
		while (solveLine(in, exchange)) ;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}