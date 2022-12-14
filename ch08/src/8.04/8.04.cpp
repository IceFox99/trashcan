#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	std::string fileName = "src/8.04/8.04.txt";
	std::ifstream input(fileName);
	std::vector<std::string> strs;

	if (input) {
		std::string buffer;
		while (getline(input, buffer))
			strs.push_back(buffer);
	}

	// For testing
	/*if (input.is_open()) {
		for (const auto& str : strs)
			std::cout << str << std::endl;
	}*/

	input.close();

	return 0;
}