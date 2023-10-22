#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:
	Intern();
	Intern(Intern const& other);
	~Intern();
	Intern &operator=(Intern const& rhs);
	AForm* makeForm(std::string name, std::string target);
};

#endif
