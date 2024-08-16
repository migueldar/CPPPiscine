#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

class PmergeMe {

private:
	std::vector<unsigned> vec;
	std::list<unsigned> list;

	//given the size of a vector, it returns the order of insertion
	std::vector<size_t> orderInsertVec(size_t size);
	std::list<size_t> orderInsertList(size_t size);

	void moveIterator(std::list<unsigned>::const_iterator& it, long n);
	void moveIterator(std::list<unsigned>::iterator& it, long n);

public:
	PmergeMe();
	PmergeMe(PmergeMe const& other);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const& rhs);
	bool							hasDuplicates();
	const std::vector<unsigned>&	get() const;
	void							addElement(unsigned element);

	void							sortVec();
	std::vector<unsigned>			sortVec(const std::vector<unsigned>& vec);
	std::vector<unsigned>			createToInsert(const std::vector<unsigned>& toRecSorted, const std::vector<unsigned>& vec);
	std::vector<unsigned>			insertVec(const std::vector<unsigned>& vec, const std::vector<unsigned>& toInsert);
	std::vector<unsigned>::iterator	whereInsert(std::vector<unsigned>::iterator begin, std::vector<unsigned>::iterator end, unsigned n);
	
	void							sortList();
	std::list<unsigned>				sortList(const std::list<unsigned>& vec);
	std::list<unsigned>				createToInsert(const std::list<unsigned>& toRecSorted, const std::list<unsigned>& vec);
	std::list<unsigned>				insertList(const std::list<unsigned>& vec, const std::list<unsigned>& toInsert);
	std::list<unsigned>::iterator	whereInsert(std::list<unsigned>::iterator begin, std::list<unsigned>::iterator end, unsigned n);
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &prt);

#endif
