#include <iostream>
#include "Array.hpp"

// void leaks() { system("leaks array"); }

#define MAX_VAL 750
int main(int, char**)
{
	//atexit(leaks);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		std::cout << tmp.size() << std::endl;
		tmp[0] = 10000;
		std::cout << numbers[0] << std::endl;
		test[0] = 9999;
		std::cout << numbers[0] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();
    delete [] mirror;

	try {
		Array <char> skibidi;
		std::cout << skibidi.size() << std::endl;
		skibidi[0];
	} catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
	}
}