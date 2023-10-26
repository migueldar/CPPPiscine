#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	switch (rand() % 3) {
	case(0):
		return new A();
	case(1):
		return new B();
	case(2):
		return new C();
	}
	return NULL;
}

void identify(Base *p) {
	Base* aux;
	
	aux = dynamic_cast<A *>(p);
	if (aux) {
		std::cout << "Type A" << std::endl;
		return ;
	}

	aux = dynamic_cast<B *>(p);
	if (aux) {
		std::cout << "Type B" << std::endl;
		return ;
	}

	aux = dynamic_cast<C *>(p);
	if (aux) {
		std::cout << "Type C" << std::endl;
		return ;
	}

	std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "Type A" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "Type B" << std::endl;
		return ;
	} catch (...) {}
	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "Type C" << std::endl;
		return ;
	} catch (...) {}
	std::cout << "Unknown type" << std::endl;
}
		
int main() {
	srand(time(NULL));

	A a;
	B b;
	C c;
	Base base;
	Base *aux;
	

	for (int i = 0; i < 10; i++) {
		aux = generate();
		identify(aux);
		delete aux;
	}

	std::cout << std::endl;
	identify(&a);
	identify(&b);
	identify(&c);
	identify(&base);

	std::cout << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(base);
}
