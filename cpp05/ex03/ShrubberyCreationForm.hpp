#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {

private:
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const& rhs);

public:
	class OutputFileException: public std::exception {
		virtual const char* what() const throw() {
			return "couldn't open output file";
		}
	};
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& other);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const& executor) const;
};

#endif
