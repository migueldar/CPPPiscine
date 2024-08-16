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

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "usage: ./PmergeMe <list>" << std::endl;
		return 1;
	}
	PmergeMe pmer;
	try {
		for (int i = 1; i < argc; i++)
			pmer.addElement(atou(argv[i]));
		if (pmer.hasDuplicates())
			throw std::runtime_error("the input list has duplicates");
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	clock_t start, end;
	double time;

	std::cout << "Before:  " << pmer << std::endl;
	start = clock();
	pmer.sortVec();
	end = clock();
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken by std::vector: " << time * 1000 << " ms" << std::endl;
	
	start = clock();
	pmer.sortList();
	end = clock();
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken by std::list:   " << time * 1000 << " ms" << std::endl;
	std::cout << "After:   " << pmer << std::endl;
	return 0;
}
