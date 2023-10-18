#include "Brain.hpp"

Brain::Brain(): _lastAdded(-1) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const& rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i <= rhs._lastAdded; i++)
		_ideas[i] = rhs._ideas[i];
	_lastAdded = rhs._lastAdded;
	return (*this);
}

void Brain::printIdeas(std::ostream& o) const {
	if (_lastAdded == -1)
		o << "No ideas in this brain" << std::endl;
	else
	{
		o << "Ideas:" << std::endl;
		for (int i = 0; i <= _lastAdded; i++)
			o << "\t" << i << " :" << _ideas[i] << std::endl;
	}
}

int Brain::addIdea(std::string idea) {
	if (_lastAdded >= 99)
		return 1;
	++_lastAdded;
	_ideas[_lastAdded] = idea;
	return 0;
}

std::ostream& operator<<(std::ostream& o, Brain const& prt) {
	prt.printIdeas(o);
	return (o);
}
