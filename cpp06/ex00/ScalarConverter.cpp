#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& other) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	(void) other;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

static void singleCharPrint(double c) {
	std::cout << "char: ";
	if (c <= 127 && c >= -128)
	{
		if (isprint(static_cast<char>(c)))
			std::cout << static_cast<char>(c) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else 
		std::cout << "impossible" << std::endl;
}

static void charPrinter(char c) {
	std::cout << "char: ";
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void intPrinter(int c) {
	singleCharPrint(c);
	std::cout << "int: " << c << std::endl;
	if (c < 1000000 && c > -1000000) {
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(c) << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
}

static void floatPrinter(float c) {
	singleCharPrint(c);
	std::cout << "int: ";
	if (c >= INT_MIN && c <= INT_MAX)
		std::cout << static_cast<int>(c) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: " << c;
	if (std::floor(c) == c && c < 1000000 && c > -1000000)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(c);
	if (std::floor(c) == c && c < 1000000 && c > -1000000)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void doublePrinter(double c) {
	singleCharPrint(c);
	std::cout << "int: ";
	if (c >= INT_MIN && c <= INT_MAX)
		std::cout << static_cast<int>(c) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "float: " << static_cast<float>(c);
	if (std::floor(c) == c && c < 1000000 && c > -1000000)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << c;
	if (std::floor(c) == c && c < 1000000 && c > -1000000)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static int chooseType(const std::string& str) {
	if (str.length() == 1 && !isdigit(static_cast<char>(str[0])))
		return 0;
	
	char *endptr;
	long res;
	res = strtol(str.c_str(), &endptr, 10);
	if (!*endptr && str.length() <= 11 && res <= INT_MAX && res >= INT_MIN)
		return 1;

	strtod(str.c_str(), &endptr);
	if (!*endptr)
		return 3;

	if (strcmp(endptr, "f") == 0)
		return 2;
	return -1;
}

void ScalarConverter::convert(char* str) {
	int which = chooseType(str);

	switch (which)
	{
	case 0:
		charPrinter(static_cast<char>(str[0]));
		break;
	case 1:
		intPrinter(atoi(str));
		break;
	case 2:
		floatPrinter(static_cast<float>(atof(str)));
		break;
	case 3:
		doublePrinter(atof(str));
		break;
	default:
		std::cerr << "impossible conversion" << std::endl;
		break;
	}
}
