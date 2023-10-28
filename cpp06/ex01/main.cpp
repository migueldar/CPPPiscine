#include "Serializer.hpp"

int main() {
	Data* a = new Data();
	std::cout << *a << std::endl;

	uintptr_t u = Serializer::serialize(a);
	Data* b = Serializer::deserialize(u);
	
	std::cout << *b << std::endl;
	a->setA(10);
	std::cout << *b << std::endl;
	std::cout << *a << std::endl;
	delete a;
}