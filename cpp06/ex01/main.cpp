#include "Serializer.hpp"

int main() {
	Serializer s;
	Data* a = new Data();
	std::cout << *a << std::endl;

	uintptr_t u = s.serialize(a);
	Data* b = s.deserialize(u);
	
	std::cout << *b << std::endl;
	a->setA(10);
	std::cout << *b << std::endl;
	std::cout << *a << std::endl;
	delete a;
}