#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

//missing brain into animals

int main()
{
	{
		//test for correct deepcopy
		Brain b;
		Brain c;

		for (int i = 0; i < 10; i++)
			b.addIdea("hola");
		b.addIdea("adios");
		c = b;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b.addIdea("tolai");
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		//test for brain fullness
		Brain b;

		for (int i = 0; i < 1000; i++)
			b.addIdea("hola");
		b.addIdea("adios");
		std::cout << b << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		Animal *arr[10];

		for (int i = 0; i < 5; i++)
			arr[i] = new Cat();
		for (int i = 5; i < 10; i++)
			arr[i] = new Dog();
		for (int i = 0; i < 10; i++)
			delete arr[i];
	}
	std::cout << std::endl << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}
	std::cout << std::endl << std::endl;
	{
		Animal *a = new Cat();
		Animal *b = new Cat
		a->makeSound();

	}
}