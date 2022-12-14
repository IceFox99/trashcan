#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec1{0, 1, 2};
	std::vector<int> vec2{0, 1, 2, 3};
	if (vec1 == vec2)
		std::cout << "These two vectors are equal." << std::endl;
	else
		std::cout << "These two vectors are not equal." << std::endl;
	return 0;
}