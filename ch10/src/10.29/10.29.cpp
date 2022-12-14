#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
	std::ifstream input("src/10.29/10.29.txt");
	std::istream_iterator<std::string> str_iter(input), eof;
	std::vector<std::string> strVec;
	while (str_iter != eof)
		strVec.push_back(*str_iter++);

	for (const auto& str : strVec)
		std::cout << str << " ";
	std::cout << std::endl;
	return 0;
}