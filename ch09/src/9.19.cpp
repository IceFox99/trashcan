#include <list>
#include <string>
#include <iostream>

int main()
{
	std::list<std::string> strList;
	std::string temp;
	while (std::cin >> temp)
		strList.push_back(temp);

	for (auto iter = strList.cbegin(); iter != strList.cend(); ++iter)
		std::cout << *iter << std::endl;

	return 0;
}