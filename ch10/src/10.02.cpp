#include <iostream>
#include <list>
#include <string>

int main()
{
	std::list<std::string> strList{ "Hello", "World", "World", "Shit", "World" };
	std::cout << std::count(strList.cbegin(), strList.cend(), "World") << " elements have a given value \"World\"." << std::endl;
	return 0;
}