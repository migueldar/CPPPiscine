#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExec;
	bool				_signed;
	Form &operator=(Form const& rhs);

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
	class AlreadySignedException: public std::exception {
		virtual const char* what() const throw() {
			return "already signed";
		}
	};
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const& other);
	~Form();
	const std::string& getName() const;
	const int& getGradeSign() const;
	const int& getGradeExec() const;
	const bool& getSigned() const;
	void beSigned(Bureaucrat const& b);
};

std::ostream &operator<<(std::ostream &o, Form const &prt);

#endif
