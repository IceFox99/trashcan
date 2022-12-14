#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> iVec{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	std::list<int> iLst;
	std::copy(iVec.crbegin() + 2, iVec.crend() - 3, back_inserter(iLst));
	for (const auto& i : iLst)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}