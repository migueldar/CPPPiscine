#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form a("form1", 200, 100);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try {
		Form a("form1", -2, 100);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try {
		Form a("form1", 100, 200);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	try {
		Form a("form1", 100, -3);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		Form f("fff", 100, 4);
		Bureaucrat b("bbb", 101);
		b.signForm(f);
	}
	std::cout << std::endl << std::endl;
	{
		Form f("fff", 100, 4);
		Bureaucrat b("bbb", 99);
		b.signForm(f);
		std::cout << f << std::endl;
		b.signForm(f);
	}
	std::cout << std::endl << std::endl;
	{
		Form f("fff", 100, 4);
		Form a(f);
		Bureaucrat b("bbb", 10);
		f.beSigned(b);
		std::cout << f << std::endl;
		std::cout << a << std::endl;
	}
}
