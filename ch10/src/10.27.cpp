#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> iVec{ 0, 1, 1, 2, 2, 2, 3, 5, 8, 8, 13, 21, 21, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	std::list<int> lVec;
	std::sort(iVec.begin(), iVec.end());
	std::unique_copy(iVec.begin(), iVec.end(), std::back_inserter(lVec));
	for (const auto& i : lVec)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}