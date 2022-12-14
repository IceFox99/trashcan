#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> intVec{ 0, 1, 1, 2, 3, 5, 8, 13, 13, 8, 5, 3, 2, 1, 1, 0 };
	std::cout << std::count(intVec.cbegin(), intVec.cend(), 1) << " elements have a given value \"1\"." << std::endl;
	return 0;
}