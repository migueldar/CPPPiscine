#include "AForm.hpp"

AForm::AForm(): _target("notarget"), _gradeSign(150), _gradeExec(150), _signed(false) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string target, int gradeSign, int gradeExec): _target(target), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false) {
	std::cout << "AForm params constructor called" << std::endl;
	if (gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeExec > 150)
		throw AForm::GradeTooLowException();
	if (gradeSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const& other): _target(other._target), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _signed(other._signed) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(AForm const& rhs) {
	_signed = rhs._signed;
	std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

const std::string &AForm::getTarget() const {
	return _target;
}

const int &AForm::getGradeSign() const {
	return _gradeSign;
}

const int &AForm::getGradeExec() const {
	return _gradeExec;
}

const bool &AForm::getSigned() const {
	return _signed;
}

void AForm::setSigned(bool sign) {
	_signed = sign;
}

void AForm::beSigned(Bureaucrat const& b) {
	if (_signed)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& o, AForm const& prt) {
	o << "AForm with target: " << prt.getTarget() << ", sign grade: " << prt.getGradeSign() << ", exec grade: ";
	o << prt.getGradeExec() << ", signed: " << prt.getSigned();
	return (o);
}
