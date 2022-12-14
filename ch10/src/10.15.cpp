#include <iostream>

int main()
{
	int i = 5;
	auto f = [i](int j) { return i + j; };
	std::cout << f(10) << std::endl;
	return 0;
}