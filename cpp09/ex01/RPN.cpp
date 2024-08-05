#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& other) {
	*this = other;
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& rhs) {
	this->stack = rhs.stack;
	return (*this);
}

void RPN::addOperand(float op) {
	stack.push(op);
}

void RPN::addOperator(char op) {
	if (stack.empty())
		throw std::runtime_error("not enough operands");
	float a = stack.top();
	stack.pop();
	if (stack.empty())
		throw std::runtime_error("not enough operands");
	float b = stack.top();
	stack.pop();

	switch (op) {
		case '+':
			stack.push(b + a);
			break;
		case '-':
			stack.push(b - a);
			break;
		case '*':
			stack.push(b * a);
			break;
		case '/':
			if (a == 0)
				throw std::runtime_error("cannot divide by 0");
			stack.push(b / a);
			break;
	}
}

//should throw if there
float RPN::returnResult() {
	if (stack.size() == 1)
		return stack.top();
	if (stack.size() == 0)
		throw std::runtime_error("not enough operands");
	throw std::runtime_error("too many operands");
}
