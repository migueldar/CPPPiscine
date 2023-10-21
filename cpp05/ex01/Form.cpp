#include "Form.hpp"

Form::Form(): _name("noname"), _gradeSign(150), _gradeExec(150), _signed(false) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false) {
	std::cout << "Form params constructor called" << std::endl;
	if (gradeExec < 1)
		throw Form::GradeTooHighException();
	if (gradeExec > 150)
		throw Form::GradeTooLowException();
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _signed(other._signed) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(Form const& rhs) {
	_signed = rhs._signed;
	std::cout << "Form copy assignment operator called" << std::endl;
	return (*this);
}

const std::string &Form::getName() const {
	return _name;
}

const int &Form::getGradeSign() const {
	return _gradeSign;
}

const int &Form::getGradeExec() const {
	return _gradeExec;
}

const bool &Form::getSigned() const {
	return _signed;
}

void Form::beSigned(Bureaucrat const& b) {
	if (_signed)
		throw Form::AlreadySignedException();
	if (b.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& o, Form const& prt) {
	o << prt.getName() << ", form sign grade: " << prt.getGradeSign() << ", exec grade: ";
	o << prt.getGradeExec() << ", signed: " << prt.getSigned();
	return (o);
}
