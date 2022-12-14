#include <fstream>
#include <iostream>
#include "../12.19/12.19.h"

int main()
{
	std::ifstream input("src/12.20/12.20.txt");
	std::string temp;
	StrBlob sb;
	while (std::getline(input, temp))
		sb.push_back(temp);

	for (auto beg = sb.begin(); beg != sb.end(); beg.incr())
		std::cout << beg.deref() << std::endl;

	return 0;
}
