#include <fstream>
#include <iostream>
#include "../16.29.h"

int main()
{
	std::ifstream input("src/16.30/16.30.txt");
	std::string temp;
	Blob<std::string> sb;
	while (std::getline(input, temp))
		sb.push_back(temp);

	for (std::size_t i = 0; i != sb.size(); ++i)
		std::cout << sb[i] << std::endl;

	return 0;
}
