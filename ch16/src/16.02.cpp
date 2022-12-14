#include <iostream>

template <typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}

int main()
{
	std::cout << compare(9, 10) << std::endl;
	std::cout << compare(8, -2) << std::endl;
	std::cout << compare(1, 1) << std::endl;
	return 0;
}