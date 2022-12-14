#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; using std::begin; using std::end;

void f() {
	cout << "This is f()" << endl;
}

void f(int i) {
	cout << "This is f(int)" << endl;
}

void f(int i1, int i2) {
	cout << "This is f(int, int)" << endl;
}

void f(double d, double = 3.14) {
	cout << "This is f(double, double = 3.14)" << endl;
}

int main()
{
	// f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}