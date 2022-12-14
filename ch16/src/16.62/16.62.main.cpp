#include <iostream>
#include <unordered_set>
#include "16.62.h"

int main()
{
	// test for ex16.62
	std::unordered_multiset<Sales_data> mset;
	Sales_data sd("1984", 10, 0.98);
	mset.insert(sd);
	mset.emplace("C++ Primer", 5, 9.99);
	mset.insert(Sales_data("The Three-Body Problem", 20, 50));

	std::hash<Sales_data> temp;
	for (const auto& item : mset)
		std::cout << "the hash code of " << item.isbn()
		<< ":\n0x" << std::hex << temp(item)
		<< "\n";

	return 0;
}