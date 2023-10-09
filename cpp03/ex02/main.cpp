#include "FragTrap.hpp"

int main() {
	{
		FragTrap clap("luigi");
		FragTrap ccclap;

		clap.attack("mario");
		clap.beRepaired(22);
		clap.takeDamage(6);
		clap.beRepaired(3);
		std::cout << std::endl << clap << std::endl;
		clap.beRepaired(10);
		clap.takeDamage(100);
		std::cout << std::endl << clap << std::endl;
		clap.beRepaired(10);
		clap.takeDamage(1000);
		std::cout << std::endl << clap << std::endl;
		ccclap = clap;
		std::cout << std::endl << ccclap << std::endl;

	}
	std::cout << std::endl << std::endl << std::endl;
	{
		FragTrap trap("itsa me");
		FragTrap tttrap(trap);

		for (int i = 0; i < 100; i++)
			trap.attack("mario");
		trap.attack("mario");
		trap.beRepaired(10);
		trap.takeDamage(5);
		std::cout << std::endl << trap << std::endl;
		std::cout << std::endl << tttrap << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	{
		FragTrap flap;

		std::cout << std::endl << flap << std::endl;
		flap.attack("a");
		flap.highFivesGuys();
	}
}
