#include "DiamondTrap.hpp"

int main() {
	{
		DiamondTrap a;

		std::cout << a << std::endl;
		a.whoAmI();
		a.guardGate();
		a.highFivesGuys();
		a.attack("pringao");
	}
	std::cout << std::endl << std::endl << std::endl;
	{
		DiamondTrap clap("luigi");
		DiamondTrap ccclap;

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
		DiamondTrap trap("itsa me");
		DiamondTrap tttrap(trap);

		for (int i = 0; i < 50; i++)
			trap.attack("mario");
		trap.attack("mario");
		trap.beRepaired(10);
		trap.takeDamage(5);
		std::cout << std::endl << trap << std::endl;
		std::cout << std::endl << tttrap << std::endl;
		tttrap.takeDamage(10);
		tttrap.beRepaired(1000);
	}
	std::cout << std::endl << std::endl << std::endl;
	{
		DiamondTrap flap;

		std::cout << std::endl << flap << std::endl;
		flap.attack("a");
		flap.highFivesGuys();
	}
}
