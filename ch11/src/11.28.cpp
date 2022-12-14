#include <map>
#include <string>
#include <vector>
#include <iostream>

int main()
{
	std::map<std::string, std::vector<int>> m{ { "HYF", { 0, 1, 1, 2, 3, 5, 8} }, { "GJX", { 8, 5, 3, 2, 1, 1, 0 } } };
	std::map<std::string, std::vector<int>>::iterator iter = m.find("HYF");
	for (const auto& i : iter->second)
		std::cout << i << " ";
	return 0;
}