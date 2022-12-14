#include <iostream>
#include <vector>

bool findInt(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int value) {
	while (begin != end) {
		if (*begin == value)
			return true;
		++begin;
	}
	return false;
}

// For testing
//int main()
//{
//	std::vector<int> test = {0, 1, 2, 3, 4, 5};
//	std::cout << findInt(test.begin(), test.end(), 4) << std::endl;
//	std::cout << findInt(test.begin(), test.end(), 6) << std::endl;
//	return 0;
//}