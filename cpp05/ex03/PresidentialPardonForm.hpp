#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {

private:
	PresidentialPardonForm &operator=(PresidentialPardonForm const& rhs);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& other);
	~PresidentialPardonForm();
	void execute(Bureaucrat const& executor) const;
};

#endif
