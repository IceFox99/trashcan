#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::list<int> intList(10, 3);
	std::vector<int> intVec(10, 4);
	std::vector<double> doubleVec1(intList.begin(), intList.end());
	std::vector<double> doubleVec2(intVec.begin(), intVec.end());

	// For testing
	for (auto v1 : doubleVec1)
		std::cout << v1 << " ";
	std::cout << std::endl;
	for (auto v2 : doubleVec2)
		std::cout << v2 << " ";
	std::cout << std::endl;

	return 0;
}