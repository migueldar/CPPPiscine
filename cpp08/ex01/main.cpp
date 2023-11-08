#include "Span.hpp"

int main() {
	std::vector<int> a;
	Span b(10);
	b.addNumbers(1, 2);

	for (int i = 0; i < 1000; i++)
		a.push_back(i);
	
}