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

	for (min; min <= max; ++min) {
		std::cout << min << " ";
	}
	return 0;
}