#include "15.26.h"

int main()
{
	Bulk_quote a("a", 10, 10, 0.3);
	// Quote 2 parameter constructor
	// Bulk 4 parameter constructor
	std::cout << std::endl;

	Bulk_quote b, c, d(a);
	// Quote default constructor
	// Bulk default constructor
	// Quote default constructor
	// Bulk default constructor
	// Quote copy constructor
	// Bulk copy constructor
	std::cout << std::endl;

	b = a;
	// Quote copy assignment
	// Bulk copy assignment
	std::cout << std::endl;

	c = std::move(b);
	// Quote move assignment
	// Bulk move assignment
	std::cout << std::endl;

	Bulk_quote e(std::move(d));
	// Quote move constructor
	// Bulk move constructor
	return 0;
}