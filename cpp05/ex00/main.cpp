#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat a("jorge", 200);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try {
		Bureaucrat a("jorge", -10);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try {
		Bureaucrat a("dani", 10);
		for (int i = 0; i < 10; i++) {
			a.increaseGrade();
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try {
		Bureaucrat a("dani", 131);
		for (int i = 0; i < 20; i++) {
			a.decreaseGrade();
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	{
		Bureaucrat a("migue", 100);
		Bureaucrat b(a);
		Bureaucrat c;
		c = a;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b.increaseGrade();
		c.decreaseGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
}