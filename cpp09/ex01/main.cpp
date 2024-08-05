#include "RPN.hpp"

void solveExpression(std::string expr) {
	RPN rpn;

	for (size_t i = 0; i < expr.size(); i++) {
		if (std::isspace(expr[i]))
			continue ;
		else if (std::isdigit(expr[i]))
			rpn.addOperand(expr[i] - '0');
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			rpn.addOperator(expr[i]);
		else {
			std::string err = "invalid character: ";
			err.push_back(expr[i]);
			throw std::runtime_error(err);
		}
	}
	float res;

	res = rpn.returnResult();
	std::cout << res << std::endl;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "usage: ./RPN <expression>" << std::endl;
		return 1;
	}
	try {
		solveExpression(argv[1]);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
