#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45) {
	std::cout << "RobotomyRequestForm params constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other): AForm(other.getTarget(), 72, 45) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	setSigned(rhs.getSigned());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	srand(time(NULL));
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises... " << getTarget();
	if (rand() % 2 == 0)
		std::cout << "has been lobotomized successfully" << std::endl;
	else
		std::cout << "has not been lobotomized" << std::endl;
}
