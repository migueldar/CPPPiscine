#pragma once

#include <iostream>

class Harl {
	private:
		void debug() const;
		void info() const;
		void warning() const;
		void error() const;
	public:
		Harl();
		~Harl();
		void complain(std::string level) const;
		void multipleComplain(std::string level) const;
};