#include "iter.hpp"
#include <cstring>

void printi(const int i) {
	print(i);
}

int lennn(const char *str) {
	std::cout << strlen(str) << std::endl;
	return strlen(str);
}

int main() {
	{
		int arr[2];
		arr[0] = 2;
		arr[1] = 1;
		iter(arr, 2, printi);
	}
	std::cout << std::endl << std::endl;
	{
		const char *arr[4] = {"hola", "adios", "danrodri", "toi"};
		iter(arr, 4, lennn);
		std::cout << std::endl << std::endl;
		iter(arr, 4, print<const char*>);
	}
}
