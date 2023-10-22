#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw() {
			return "grade too high";
		}
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw() {
			return "grade too low";
		}
	};
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& other);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const& rhs);
	const std::string& getName() const;
	const int& getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void signForm(AForm& f) const;
};


std::ostream &operator<<(std::ostream &o, Bureaucrat const &prt);

#endif
