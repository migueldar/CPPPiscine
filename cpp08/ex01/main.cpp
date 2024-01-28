#include "Span.hpp"

int main() {
	std::vector<int> a;

	{
		Span s(5);

		s.addNumber(1);
		s.addNumber(25);
		s.addNumber(7);
		s.addNumber(5);
		s.addNumber(-1);

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		Span s(5);

		s.addNumber(42);
		s.addNumber(18);
		s.addNumber(76);
		s.addNumber(53);
		s.addNumber(9);

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		Span s(10);
		try {
			s.longestSpan();
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	{
		Span s(2);
		try {
			s.addNumber(42);
			s.addNumber(18);
			s.addNumber(76);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	{
		Span s(15000);

		for (int i = 0; i < 15000; i++)
			s.addNumber(i);
		
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		std::vector<int> v;
		Span s(10);

		v.push_back(64);
		v.push_back(27);
		v.push_back(89);
		v.push_back(13);
		v.push_back(50);

		s.addNumbers(v.begin(), v.end());

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
}