#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() const {
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl << "I really do!" << std::endl << std::endl;
}

void Harl::info() const {
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn't put enough bacon in my burger!" << std::endl << "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning() const {
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error() const {
	std::cout << "[ERROR]" << std::endl << "This is unacceptable!" << std::endl << "I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) const {
	void (Harl::*funcs[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == levels[i]) {
			(this->*funcs[i])();
			return ;
		}
	std::cerr << "Cant complain at that level!" << std::endl << std::endl;
}
