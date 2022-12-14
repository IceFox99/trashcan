#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

int main()
{
	// (a)
	std::vector<int> vec;
	std::list<int> lst;
	int i;
	while (std::cin >> i)
		lst.push_back(i);
	std::copy(lst.cbegin(), lst.cend(), std::back_inserter(vec)); // The key of this problem.
	for (const auto& i : vec) // For testing
		std:: cout << i << " ";
	std::cout << std::endl;

	// (b)
	std::vector<int> vec2;
	std::fill_n(std::back_inserter(vec2), 10, 0); // The key of this problem.
	for (const auto& i : vec2) // For testing
		std::cout << i << " ";

	return 0;
}