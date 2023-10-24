#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {

private:
	int _a;
	int _b;

public:
	Data();
	Data(Data const& other);
	~Data();
	Data &operator=(Data const& rhs);
	int getA() const;
	int getB() const;
	void setA(int n);
	void setB(int n);
};

std::ostream &operator<<(std::ostream &o, Data const &prt);

#endif
