#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe {

private:
	std::vector<unsigned> vec;
	std::list<unsigned> list;

	//returns the next to insert, given the current one and the total size
	size_t nextToInsert(size_t curr, size_t size);
	//returns until which to compare, give the current 

public:
	PmergeMe();
	PmergeMe(PmergeMe const& other);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const& rhs);
	const std::vector<unsigned>& get() const;
	void addElement(unsigned element);
	void sortVec();
	std::vector<unsigned> sortVec(std::vector<unsigned> vec);
	std::vector<unsigned> insertVec(std::vector<unsigned> vec, std::vector<unsigned> toInsert);
	void sortList();
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &prt);

#endif
