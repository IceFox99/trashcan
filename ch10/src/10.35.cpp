#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> iVec{ 0, 1, 1, 2, 3, 5, 8, 13 };
	for (auto iter = iVec.cend() - 1; iter != iVec.cbegin(); --iter)
		std::cout << *iter << " ";
	std::cout << *iVec.cbegin() << std::endl;
	return 0;
}