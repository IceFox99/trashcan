#include <deque>
#include <string>
#include <iostream>

int main()
{
	std::deque<std::string> strDeque;
	std::string temp;
	while (std::cin >> temp)
		strDeque.push_back(temp);

	for (auto iter = strDeque.cbegin(); iter != strDeque.cend(); ++iter)
		std::cout << *iter << std::endl;

	return 0;
}