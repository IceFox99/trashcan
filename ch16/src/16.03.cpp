#include <iostream>

class Sales_data {};

template <typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}

int main()
{
	Sales_data lhs, rhs;
	// Compiler Error:
	// binary '<': 'const T' does not define this operator or a conversion to a type acceptable to the predefined operator
	std::cout << compare(lhs, rhs) << std::endl;

	return 0;
}