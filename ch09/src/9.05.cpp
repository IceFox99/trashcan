#include <iostream>
#include <vector>

std::vector<int>::const_iterator findIter(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int value) {
	while (begin != end) {
		if (*begin == value)
			return begin;
		++begin;
	}
	return end;
}

// For testing
//int main()
//{
//	std::vector<int> test = { 0, 1, 2, 3, 4, 5 };
//	std::cout << *(findIter(test.begin(), test.end(), 4)) << std::endl;
//	std::cout << *(findIter(test.begin(), test.end(), 6) - 1) << std::endl;
//	return 0;
//}