#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void leaks() { system("leaks -q smartAnimals"); }

int main()
{
	// atexit(leaks);
	{
		Animal *a = new Cat();
		Animal *b = new Dog();

		a->makeSound();
		b->makeSound();
		delete a;
		delete b;
	}
	// {
	// 	Animal a;
	// }
}
