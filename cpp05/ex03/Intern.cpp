#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const& other) {
	(void) other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(Intern const& rhs) {
	(void) rhs;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int which = -1;

	for (int i = 0; i < 3; i++) {
		if (forms[i] == name) {
			which = i;
			std::cout << "Intern creates " << name << std::endl;
			break;
		}
	}

	switch (which)
	{
	case 0:
		return new ShrubberyCreationForm(target);
		break;
	case 1:
		return new RobotomyRequestForm(target);
		break;
	case 2:
		return new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "Intern couldn't create " << name << ", form doesn't exist" << std::endl;
		break;
	}
	return NULL;
}
