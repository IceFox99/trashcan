#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

int main()
{
	std::vector<int> intVec{ 2, 3, 5, 7, 11, 13 };
	int value = 30031;
	auto pred = [&](const int v)
	{
		return std::modulus<int>()(value, v) == 0;
	};
	auto ret = std::any_of(intVec.begin(), intVec.end(), pred);
	std::cout << (ret ? "Yes" : "No") << std::endl;
	return 0;
}