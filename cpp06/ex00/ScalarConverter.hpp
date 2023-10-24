#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>

class ScalarConverter {

public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const& other);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const& rhs);
	static void convert(char* str);
};

#endif
