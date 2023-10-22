#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shruberry creation", "default", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shruberry creation", target, 145, 137) {
	std::cout << "ShrubberyCreationForm params constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other): AForm(other.getName(), other.getTarget(), 145, 137) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	setSigned(rhs.getSigned());
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::ofstream file;

	if (executor.getGrade() > getGradeExec())
		throw AForm::GradeTooLowException();

	file.open((getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!file) {
		throw ShrubberyCreationForm::OutputFileException();
	}

	file << "   *" << std::endl;
	file << "  ***" << std::endl;
	file << " *****" << std::endl;
	file << "*******" << std::endl;
	file << "  ***" << std::endl;
	file.close();
}
