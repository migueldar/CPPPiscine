#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	const std::string	_target;
	const int			_gradeSign;
	const int			_gradeExec;
	bool				_signed;
	AForm &operator=(AForm const& rhs);

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
	AForm();
	AForm(std::string target, int gradeSign, int gradeExec);
	AForm(AForm const& other);
	virtual ~AForm();
	const std::string& getTarget() const;
	const int& getGradeSign() const;
	const int& getGradeExec() const;
	const bool& getSigned() const;
	void setSigned(bool sign);
	void beSigned(Bureaucrat const& b);
	virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &prt);

#endif
