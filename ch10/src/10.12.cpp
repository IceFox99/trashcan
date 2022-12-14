#include <vector>
#include <iostream>
#include <algorithm>
#include "Sales_data.h"

inline bool compareIsbn(const Sales_data& s1, const Sales_data& s2) {
	return std::stoi(s1.isbn()) < std::stoi(s2.isbn());
}

int main()
{
	std::vector<Sales_data> sVec{ Sales_data("813"), Sales_data("135"), Sales_data("4"), Sales_data("277") };
	std::sort(sVec.begin(), sVec.end(), compareIsbn);
	for (const auto& s : sVec)
		std::cout << s.isbn() << " ";
	std::cout << std::endl;
	return 0;
}