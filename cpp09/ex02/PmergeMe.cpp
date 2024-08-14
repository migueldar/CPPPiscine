#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
	vec = rhs.vec;
	list = rhs.list;
	return (*this);
}

const std::vector<unsigned>& PmergeMe::get() const {
	return vec;
}

void PmergeMe::addElement(unsigned element) {
	vec.push_back(element);
	list.push_back(element);
}

void PmergeMe::sortVec() {
	vec = sortVec(vec);
}

std::vector<unsigned> PmergeMe::sortVec(std::vector<unsigned> vec) {
	std::vector<unsigned> toInsert;
	std::vector<unsigned> toRec;
	std::vector<unsigned> ret;

	for (size_t i = 0; i < vec.size() / 2; i++) {
		if (vec[i] < vec[i + 1]) {
			toRec.push_back(vec[i + 1]);
			toInsert.push_back(vec[i]);
		} else {
			toRec.push_back(vec[i]);
			toInsert.push_back(vec[i + 1]);
		}
	}
	if (vec.size() % 2 == 1)
		toInsert.push_back(vec.back());

	ret = sortVec(toRec);
	ret = insertVec(ret, toInsert);

	return ret;
}

std::vector<unsigned> PmergeMe::insertVec(std::vector<unsigned> vec, std::vector<unsigned> toInsert) {
	
}

std::ostream& operator<<(std::ostream& o, PmergeMe const& prt) {
	const std::vector<unsigned>& aux = prt.get();

	for (std::vector<unsigned>::const_iterator i = aux.begin(); i != aux.end(); i++)
		o << *i << ' ';
	return (o);
}

