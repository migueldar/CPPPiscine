#include "ScalarConverter.hpp"
#include <cmath>

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
	std::cout << "char: ";
	if (isprint(static_cast<char>(c)))
		std::cout << static_cast<char>(c) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << c << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void floatPrinter(float c) {
	std::cout << "char: ";
	if (isprint(static_cast<char>(c)))
		std::cout << static_cast<char>(c) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << c;
	if (std::floor(c) == c)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(c);
	if (std::floor(c) == c)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void doublePrinter(double c) {
	std::cout << "char: ";
	if (isprint(static_cast<char>(c)))
		std::cout << static_cast<char>(c) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c);
	if (std::floor(c) == c)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << c;
	if (std::floor(c) == c)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

static void elsePrinter(const std::string& nbr) {
	std::string toPrint;

	if (nbr == "nan" || nbr == "nanf")
		toPrint = "nan";
	else if (nbr == "+inf" || nbr == "+inff")
		toPrint = "+inf";
	else if (nbr == "-inf" || nbr == "-inff")
		toPrint = "-inf";
	else {
		std::cerr << "impossible conversion" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << toPrint << 'f' << std::endl;
	std::cout << "double: " << toPrint << std::endl;
}

//delete else printer and add nan... here, bc they shoudl be recognised as their type
static int chooseType(const std::string& str) {
	if (str.length() == 1 && !isnumber(static_cast<char>(str[0])))
		return 0;
	std::cout << std::atoi("100000000000000000");
	std::cout << std::atof("1fsdlkfdshfdjshfjsdhsfsdjkhfsdijhj");
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
		intPrinter(std::atoi(str));
		break;
	case 2:
		floatPrinter(static_cast<float>(std::atof(str)));
		break;
	case 3:
		doublePrinter(std::atof(str));
		break;
	default:
		elsePrinter(str);
		break;
	}
}
