#include "Intern.hpp"

int main()
{
	srand(time(NULL));

	{
		Intern danrodri;
		Bureaucrat b("HE", 1);
	
		AForm* s = danrodri.makeForm("shrubbery creation", "steve");
		AForm* r = danrodri.makeForm("robotomy request", "josh");
		AForm* p = danrodri.makeForm("presidential pardon", "mike");
		danrodri.makeForm("patata", "mike");

		std::cout << std::endl << std::endl;
		b.signForm(*s);
		b.executeForm(*s);
		b.signForm(*r);
		b.executeForm(*r);
		b.signForm(*p);
		b.executeForm(*p);
		std::cout << std::endl << std::endl;
		
		delete s;
		delete r;
		delete p;
	}
}
