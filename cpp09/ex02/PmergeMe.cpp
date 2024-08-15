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

std::vector<size_t> PmergeMe::vecToInsert(size_t size) {
	std::vector<size_t> ret;
	size_t prev = 0;
	size_t curr = 2;
	bool plus = true;

	if (size == 0)
		return ret;
	ret.push_back(0);
	if (size == 1)
		return ret;
	if (size == 2) {
		ret.push_back(1);
		return ret;
	}
	for (size_t i = 1; i < size; i++) {
		ret.push_back(curr);
		if (curr == prev + 1) {
			prev = 2 * prev + (plus ? 2 : 0);
			plus = !plus;
			curr = 2 * prev + (plus ? 2 : 0);
			if (curr > size - 1)
				curr = size - 1;
		}
		else
			curr--;
	}
	return ret;
}

void PmergeMe::sortVec() {
	vec = sortVec(vec);
}

std::vector<unsigned> PmergeMe::sortVec(const std::vector<unsigned>& vec) {
	std::vector<unsigned> toInsert;
	std::vector<unsigned> toRec;
	std::vector<unsigned> ret;

	if (vec.size() == 0 || vec.size() == 1)
		return vec;
	for (size_t i = 0; i < vec.size() / 2; i += 2) {
		if (vec[i] < vec[i + 1])
			toRec.push_back(vec[i + 1]);
		else
			toRec.push_back(vec[i]);
	}

	ret = sortVec(toRec);
	toInsert = createToInsert(toRec, vec);
	ret = insertVec(ret, toInsert);

	return ret;
}

std::vector<unsigned> PmergeMe::insertVec(std::vector<unsigned> vec, std::vector<unsigned> toInsert) {

}

std::vector<unsigned> PmergeMe::createToInsert(const std::vector<unsigned>& toRec, const std::vector<unsigned>& vec) {
	std::vector<unsigned> ret;
	
	for (size_t i = 0; i < toRec.size(); i++) {
		for (size_t j = 0; j < vec.size(); j++) {
			if (toRec[i] == vec[j]) {
				if (j % 2 == 0)
					ret.push_back(vec[j + 1]);
				else
					ret.push_back(vec[j - 1]);
			}
		}
	}
	if (vec.size() % 2 == 1)
		ret.push_back(vec.back());
	return ret;
}

std::ostream& operator<<(std::ostream& o, PmergeMe const& prt) {
	const std::vector<unsigned>& aux = prt.get();

	for (std::vector<unsigned>::const_iterator i = aux.begin(); i != aux.end(); i++)
		o << *i << ' ';
	return (o);
}
