#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>

class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& other);

public:
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const& rhs);
	static void convert(char* str);
};

#endif
