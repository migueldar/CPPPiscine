#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	srand(time(NULL));

	{
		AForm* s = new ShrubberyCreationForm("steve");
		AForm* r = new RobotomyRequestForm("josh");
		AForm* p = new PresidentialPardonForm("mike");
		Bureaucrat b("HE", 1);
	
		std::cout << std::endl << std::endl;
		b.signForm(*s);
		b.executeForm(*s);
		b.signForm(*r);
		b.executeForm(*r);
		b.signForm(*p);
		b.executeForm(*p);
		std::cout << std::endl << std::endl;
		
		delete s;
		delete r;
		delete p;
	}
	std::cout << std::endl << std::endl;
	{
		AForm* s = new ShrubberyCreationForm("stev");
		AForm* r = new RobotomyRequestForm("jos");
		AForm* p = new PresidentialPardonForm("mik");
		Bureaucrat b("dude", 70);
	
		std::cout << std::endl << std::endl;
		b.signForm(*s);
		b.executeForm(*s);
		b.signForm(*r);
		b.executeForm(*r);
		b.signForm(*p);
		b.executeForm(*p);
		std::cout << std::endl << std::endl;

		delete s;
		delete r;
		delete p;
	}
	std::cout << std::endl << std::endl;
	{
		AForm* s = new ShrubberyCreationForm("ste");
		AForm* r = new RobotomyRequestForm("jo");
		AForm* p = new PresidentialPardonForm("mi");
		Bureaucrat b("psegura-", 150);
	
		std::cout << std::endl << std::endl;
		b.signForm(*s);
		b.executeForm(*s);
		b.signForm(*r);
		b.executeForm(*r);
		b.signForm(*p);
		b.executeForm(*p);
		std::cout << std::endl << std::endl;

		delete s;
		delete r;
		delete p;
	}
	std::cout << std::endl << std::endl;
	{
		AForm* s = new ShrubberyCreationForm("ste");
		AForm* r = new RobotomyRequestForm("jo");
		AForm* p = new PresidentialPardonForm("mi");
	
		std::cout << std::endl << std::endl;
		std::cout << *s << std::endl;
		std::cout << *r << std::endl;
		std::cout << *p << std::endl;
		std::cout << std::endl << std::endl;

		delete s;
		delete r;
		delete p;
	}
}
