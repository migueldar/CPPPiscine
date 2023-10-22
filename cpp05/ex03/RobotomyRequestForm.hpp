#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {

private:
	RobotomyRequestForm &operator=(RobotomyRequestForm const& rhs);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& other);
	~RobotomyRequestForm();
	void execute(Bureaucrat const& executor) const;
};

#endif
