#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void leaks() { system("leaks -q smartAnimals"); }

int main()
{
	// atexit(leaks);
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
		Cat a;
		Cat b;

		a.addIdea("dani");
		a.addIdea("es un poco tolai");
		b = a;
		Cat c(a);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		a.addIdea("es cierto");
		b.addIdea("es broma");
		c.addIdea("quizas...");
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
}
