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

	//given the size of a vector, it returns the order of insertion
	std::vector<size_t> vecToInsert(size_t size);

public:
	PmergeMe();
	PmergeMe(PmergeMe const& other);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const& rhs);
	const std::vector<unsigned>& get() const;
	void addElement(unsigned element);
	void sortVec();
	std::vector<unsigned> sortVec(const std::vector<unsigned>& vec);
	std::vector<unsigned> insertVec(std::vector<unsigned> vec, std::vector<unsigned> toInsert);
	std::vector<unsigned> createToInsert(const std::vector<unsigned>& toRec, const std::vector<unsigned>& vec);
	void sortList();
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &prt);

#endif
