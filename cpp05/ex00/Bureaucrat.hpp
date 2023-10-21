#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw() {
			return "Grade too high";
		}
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw() {
			return "Grade too low";
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
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &prt);

#endif
