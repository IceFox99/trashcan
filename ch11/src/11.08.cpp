#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<std::string> exclude{ "the", "but", "and", "or", "an", "a", "The", "But", "And", "Or", "An", "A" };
	std::string temp;
	std::cout << "Please input a word: ";
	while (std::cin >> temp) {
		if (std::find(exclude.cbegin(), exclude.cend(), temp) == exclude.cend())
			std::cout << "Not excluded." << std::endl;
		else
			std::cout << "Excluded." << std::endl;
		std::cout << "Please input a word: ";
	}
	return 0;
}