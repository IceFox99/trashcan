#include <iostream>

int main()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype ((b)) d = a;

	std::cout << "type of a: " << typeid(a).name()
		<< "\ntype of b: " << typeid(b).name()
		<< "\ntype of c: " << typeid(c).name()
		<< "\ntype of d: " << typeid(d).name() << std::endl;

	++c;
	++d;

	std::cout << "a: " << a
		<< "\nb: " << b
		<< "\nc: " << c
		<< "\nd: " << d << std::endl;
	return 0;
}