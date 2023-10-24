#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const& other) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = other;
}

Serializer::~Serializer() {
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer& Serializer::operator=(Serializer const& rhs) {
	(void) rhs;
	std::cout << "Serializer copy assignment operator called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
