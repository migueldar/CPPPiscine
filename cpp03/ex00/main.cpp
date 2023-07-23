#include "ClapTrap.hpp"

int main() {
	{
		ClapTrap clap("luigi");

		clap.attack("mario");
		clap.beRepaired(22);
		clap.takeDamage(6);
		clap.beRepaired(3);
		std::cout << std::endl << clap << std::endl;
		clap.beRepaired(10);
		clap.takeDamage(100);
		std::cout << std::endl << clap << std::endl;
		clap.beRepaired(10);
		clap.takeDamage(100);
		std::cout << std::endl << clap << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		ClapTrap trap("itsa me");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.attack("mario");
		trap.beRepaired(10);
	}		
}
