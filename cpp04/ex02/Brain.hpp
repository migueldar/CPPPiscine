#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

private:
	std::string _ideas[100];
	int _lastAdded;

public:
	Brain();
	Brain(Brain const& other);
	~Brain();
	Brain &operator=(Brain const& rhs);
	void printIdeas(std::ostream& o) const;
	int addIdea(std::string idea);
};

std::ostream& operator<<(std::ostream& o, Brain const& prt);

#endif