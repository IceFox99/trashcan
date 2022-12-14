#include <numeric>
#include <iostream>
#include <vector>

int main()
{
	std::vector<double> v{ 0.4, -1.45, 13.4431, 9.23 };
	std::cout << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;
	// The answer will be 21 because 0 is an integer and the calculation will be converted into integer.
	return 0;
}