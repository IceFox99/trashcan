#include <iostream>
#include <utility>
#include <vector>

int main()
{
	std::string str;
	int i;
	std::vector<std::pair<std::string, int>> vec;
	std::cout << "Please input a string and an integer:";
	while (std::cin >> str >> i) {
		//vec.push_back(std::make_pair(str, i)); First way.
		//vec.push_back(std::pair<std::string, int>(str, i)); Second way.
		//vec.push_back({ str, i }); Third way.
		vec.emplace_back(str, i); // Fourth way.
		std::cout << "Please input a string and an integer:";
	}

	for (const auto& p : vec)
		std::cout << p.first << " " << p.second << std::endl;
	return 0;
}