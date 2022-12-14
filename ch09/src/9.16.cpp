#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> vec{ 0, 1, 2 };
	std::list<int> li{ 0, 1, 2 };
	if (vec == std::vector<int>(li.cbegin(), li.cend()))
		std::cout << "These two vectors are equal." << std::endl;
	else
		std::cout << "These two vectors are not equal." << std::endl;
	return 0;
}