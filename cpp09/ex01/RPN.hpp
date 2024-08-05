#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {

private:
	std::stack<float> stack;

public:
	RPN();
	RPN(RPN const& other);
	~RPN();
	RPN &operator=(RPN const& rhs);
	void addOperator(char op);
	void addOperand(float op);
	float returnResult();
};

#endif
