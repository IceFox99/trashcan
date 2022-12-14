#include <iostream>

int main()
{
	auto f = [](int a, int b) { return a + b; };
	std::cout << f(3, 4) << std::endl;
	return 0;
}