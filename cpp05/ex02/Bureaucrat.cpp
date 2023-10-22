#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("noname"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat params constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other): _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	_grade = rhs._grade;
	return (*this);
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

const int& Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::increaseGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed form with target " << f.getTarget() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign form with target " << f.getTarget() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& prt) {
	o << prt.getName() << ", bureaucrat grade " << prt.getGrade();
	return (o);
}
