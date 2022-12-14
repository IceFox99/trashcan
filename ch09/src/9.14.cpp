#include <list>
#include <vector>
#include <string>
#include <iostream>

int main()
{
	char c1[] = "c1";
	char c2[] = "c2";
	char c3[] = "c3";
	std::list<char*> charList{c1, c2, c3};

	std::vector<std::string> strVec(charList.cbegin(), charList.cend());

	// For testing
	for (auto str : strVec)
		std::cout << str << std::endl;

	return 0;
}