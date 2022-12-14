#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	std::ifstream input("src/8.10/8.10.txt");
	std::vector<std::string> strVec;
	if (input) {
		std::string buffer;
		while (getline(input, buffer))
			strVec.push_back(buffer);
	}

	// For testing
	/*for (const auto& line : strVec)
		std::cout << line << std::endl;*/

	return 0;
}