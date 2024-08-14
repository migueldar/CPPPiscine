#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <ctime>

unsigned atou(std::string str) {
	long int ret = 0;

	if (str.length() > 10)
		throw std::runtime_error(str + " is not a positive integer");
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			throw std::runtime_error(str + " is not a positive integer");
		ret = ret * 10 + (str[i] - '0');
	}
	if (ret > (long int) 0xffffffff)
		throw std::runtime_error(str + " is not a positive integer");
	return ret;
}

//think about duplicates (joan dice que es movidon)
int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "usage: ./PmergeMe <list>" << std::endl;
		return 1;
	}
	PmergeMe pmer;
	try {
		for (int i = 1; i < argc; i++)
			pmer.addElement(atou(argv[i]));
		std::cout << "Before:  " << pmer << std::endl;
		//TODO check for no repetition of elements, maybe a set could be used, so that duplicate elements are not allowed to be added
		pmer.sortVec();
		pmer.sortList();
		std::cout << "After: " << pmer << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
