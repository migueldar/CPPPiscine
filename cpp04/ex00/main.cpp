#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

//missing to check for leaks
//missing more tests (copy constructor, assignment operator)

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
	}
	std::cout << std::endl << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		delete i;
		delete meta;
	}
	std::cout << std::endl << std::endl;
	{
		const Animal* a = new Cat();
		Animal b;
		Animal c(*a);
		b = *a;

		b.makeSound();
		c.makeSound();
		delete a;
	}
	std::cout << std::endl << std::endl;
	{
		const Dog d;

		d.makeSound();
		std::cout << d.getType() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		const Cat c;
		
		c.makeSound();
		std::cout << c.getType() << std::endl;
	}
}