#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> intVec{ 0, 1, 1, 2, 3, 5, 8, 13 };
	std::fill_n(intVec.begin(), intVec.size(), 0);
	for (const auto& i :intVec)
		std::cout << i << " ";
	return 0;
}
