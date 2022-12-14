#include <iostream>

int main()
{
	int i = 5;
	auto f = [&i]() {
		return (i > 0) ? !--i : !i;
	};
	while (!f())
		std::cout << i << " ";
	std::cout << std::endl << i << std::endl;
	return 0;
}