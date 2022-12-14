#include <iostream>

int main()
{
	int a, b, min, max;
	std::cout << "Please input first integer: ";
	std::cin >> a;
	std::cout << "Please input second integer: ";
	std::cin >> b;

	min = a;
	max = b;
	if (a > b) {
		min = b;
		max = a;
	}
	while (min <= max) {
		std::cout << min << " ";
		++min;
	}

	return 0;
}