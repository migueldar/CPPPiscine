#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential pardon", "notarget", 25, 5) {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("presidential pardon", target, 25, 5) {
	std::cout << "PresidentialPardonForm params constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other): AForm(other.getName(), other.getTarget(), 25, 5) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	setSigned(rhs.getSigned());
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << getTarget() << " has been perdoned by Zaphod Beeblebrox" << std::endl;
}
