#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		std::cout << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(5);
		mstack.push(2);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
		std::cout << s.top() << std::endl;
		std::cout << std::endl;


		MutantStack<int> sss(mstack);
		it = sss.begin();
		ite = sss.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		std::cout << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(5);
		mstack.push_back(2);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}