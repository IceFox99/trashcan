#include <numeric>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> intVec{ 0, 1, 1, 2, 3, 5, 8, 13 };
	std::cout << std::accumulate(intVec.cbegin(), intVec.cend(), 0) << std::endl;
	return 0;
}