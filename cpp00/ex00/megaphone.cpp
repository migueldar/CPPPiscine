#include <iostream>
#include <cstring>

int main(int argc, char **argv) 
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::string aux = argv[i];
		for (size_t j = 0; j < aux.size(); j++)
			std::cout << (char) toupper(aux[j]);
	}
	std::cout << std::endl;

	return 0;
}
