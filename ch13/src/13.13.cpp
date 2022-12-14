#include <iostream>
#include <vector>

struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) {
		std::cout << "X& operator=(const X&)" << std::endl;
		return *this;
	}
	~X() { std::cout << "~X()" << std::endl; }
};

void f(const X& rx, X x) {
	std::vector<X> xVec;
	std::cout << "~~~" << std::endl;

	xVec.reserve(2);
	std::cout << "~~~" << std::endl;

	xVec.push_back(rx);
	std::cout << "~~~" << std::endl;

	xVec.push_back(x);
	std::cout << "~~~" << std::endl;
}

int main()
{
	X x1;
	X x2 = x1;
	X x3;
	x3 = x1;
	X* xPtr = new X;
	std::cout << "~~~~~" << std::endl;

	f(*xPtr, *xPtr);
	std::cout << "~~~~~" << std::endl;

	delete xPtr;
	std::cout << "~~~~~" << std::endl;

	return 0;
}
