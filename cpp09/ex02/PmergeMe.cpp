#include "PmergeMe.hpp"
#include <cstddef>

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

bool PmergeMe::hasDuplicates() {
	for (std::vector<unsigned>::iterator it = vec.begin(); it != vec.end(); it++)
		if (std::count(it, vec.end(), *it) > 1)
			return true;
	return false;		
}

const std::vector<unsigned>& PmergeMe::get() const {
	return vec;
}

void PmergeMe::addElement(unsigned element) {
	vec.push_back(element);
	list.push_back(element);
}

// --VECTOR--
std::vector<size_t> PmergeMe::orderInsertVec(size_t size) {
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
	for (size_t i = 0; i < vec.size() / 2; i++) {
		if (vec[2 * i] < vec[2 * i + 1])
			toRec.push_back(vec[2 * i + 1]);
		else
			toRec.push_back(vec[2 * i]);
	}

	ret = sortVec(toRec);
	toInsert = createToInsert(ret, vec);
	ret = insertVec(ret, toInsert);

	return ret;
}

std::vector<unsigned> PmergeMe::createToInsert(const std::vector<unsigned>& toRecSorted, const std::vector<unsigned>& vec) {
	std::vector<unsigned> ret;
	
	for (size_t i = 0; i < toRecSorted.size(); i++) {
		for (size_t j = 0; j < vec.size(); j++) {
			if (toRecSorted[i] == vec[j]) {
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

//vectors of size 0 will never enter this function
std::vector<unsigned> PmergeMe::insertVec(const std::vector<unsigned>& vec, const std::vector<unsigned>& toInsert) {
	std::vector<unsigned> ret = vec;
	ret.insert(ret.begin(), toInsert[0]);
	std::vector<size_t> order = orderInsertVec(toInsert.size());

	for (size_t i = 1; i < toInsert.size(); i++) {
		std::vector<unsigned>::iterator pos;
		if (order[i] >= vec.size())
			pos = ret.end();
		else
			pos = std::find(ret.begin(), ret.end(), vec[order[i]]) + 1;
		ret.insert(whereInsert(ret.begin(), pos, toInsert[order[i]]), toInsert[order[i]]);
	}
	return ret;
}

std::vector<unsigned>::iterator PmergeMe::whereInsert(std::vector<unsigned>::iterator begin, std::vector<unsigned>::iterator end, unsigned n) {
	size_t size = end - begin;

	if (size == 1)
		return *begin > n ? begin : begin + 1;
	if (size == 2)
		return *begin > n ? begin : whereInsert(begin + 1, end, n);
	return *(begin + size / 2) > n ? whereInsert(begin, begin + size / 2, n) : whereInsert(begin + size / 2 + 1, end, n);
}

// --LIST--
std::list<size_t> PmergeMe::orderInsertList(size_t size) {
	std::list<size_t> ret;
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

void PmergeMe::moveIterator(std::list<unsigned>::const_iterator& it, long n) {
	if (n > 0)
		for (long i = 0; i < n; i++)
			it++;
	if (n < 0) 
		for (long i = 0; i > n; i--)
			it--;
}

void PmergeMe::moveIterator(std::list<unsigned>::iterator& it, long n) {
	if (n > 0)
		for (long i = 0; i < n; i++)
			it++;
	if (n < 0) 
		for (long i = 0; i > n; i--)
			it--;
}

void PmergeMe::sortList() {
	list = sortList(list);
}

std::list<unsigned> PmergeMe::sortList(const std::list<unsigned>& list) {
	std::list<unsigned> toInsert;
	std::list<unsigned> toRec;
	std::list<unsigned> ret;

	if (list.size() == 0 || list.size() == 1)
		return list;
	for (std::list<unsigned>::const_iterator it = list.begin(); it != list.end(); it++) {
		if (++it == list.end())
			break;
		if (*it < *(--it)) {
			toRec.push_back(*it);
			it++;
		}
		else
			toRec.push_back(*(++it));
	}

	ret = sortList(toRec);
	toInsert = createToInsert(ret, list);
	ret = insertList(ret, toInsert);

	return ret;
}

std::list<unsigned> PmergeMe::createToInsert(const std::list<unsigned>& toRecSorted, const std::list<unsigned>& list) {
	std::list<unsigned> ret;
	size_t cnt;
	
	for (std::list<unsigned>::const_iterator i = toRecSorted.begin(); i != toRecSorted.end(); i++) {
		cnt = 0;
		for (std::list<unsigned>::const_iterator j = list.begin(); j != list.end(); j++) {
			if (*i == *j) {
				if (cnt % 2 == 0) {
					ret.push_back(*(++j));
					j--;
				}
				else {
					ret.push_back(*(--j));
					j++;
				}
			}
			cnt++;
		}
	}
	if (list.size() % 2 == 1)
		ret.push_back(list.back());
	return ret;
}

//lists of size 0 will never enter this function
std::list<unsigned> PmergeMe::insertList(const std::list<unsigned>& list, const std::list<unsigned>& toInsert) {
	std::list<unsigned> ret = list;
	ret.insert(ret.begin(), toInsert.front());

	std::list<size_t> order = orderInsertList(toInsert.size());
	std::list<size_t>::const_iterator itOrder = order.begin();
	long move = 0 - *itOrder + *(++itOrder);

	std::list<unsigned>::const_iterator itList = list.begin();
	moveIterator(itList, move);

	std::list<unsigned>::const_iterator itInsert = toInsert.begin();
	moveIterator(itInsert, move);


	while (itOrder != order.end()) {
		std::list<unsigned>::iterator pos;

		if (*itOrder >= list.size())
			pos = ret.end();
		else {
			pos = std::find(ret.begin(), ret.end(), *itList);
			pos++;
		}
		ret.insert(whereInsert(ret.begin(), pos, *itInsert), *itInsert);
		move = 0 - *itOrder + *(++itOrder);
		moveIterator(itList, move);
		moveIterator(itInsert, move);
	}
	return ret;
}

std::list<unsigned>::iterator PmergeMe::whereInsert(std::list<unsigned>::iterator begin, std::list<unsigned>::iterator end, unsigned n) {
	size_t size = std::distance(begin, end);

	if (size == 1)
		return *begin > n ? begin : ++begin;
	if (size == 2)
		return *begin > n ? begin : whereInsert(++begin, end, n);
	std::list<unsigned>::iterator middle = begin;
	moveIterator(middle, size / 2);
	return *middle > n ? whereInsert(begin, middle, n) : whereInsert(++middle, end, n);
}

std::ostream& operator<<(std::ostream& o, PmergeMe const& prt) {
	const std::vector<unsigned>& aux = prt.get();

	for (std::vector<unsigned>::const_iterator i = aux.begin(); i != aux.end(); i++)
		o << *i << ' ';
	return (o);
}
