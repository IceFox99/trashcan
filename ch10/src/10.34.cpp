#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> iVec{ 0, 1, 1, 2, 3, 5, 8, 13 };
	std::for_each(iVec.crbegin(), iVec.crend(), [](int i) {
		std::cout << i << " ";
		});
	std::cout << std::endl;
	return 0;
}