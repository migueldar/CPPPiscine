#include "Harl.hpp"

int main(int argc, char** argv) {
	Harl karen;

	if (argc != 2) {
		std::cerr << "Exactly one parameter is needed" << std::endl;
		return 1;
	}

	karen.multipleComplain(argv[1]);
}
