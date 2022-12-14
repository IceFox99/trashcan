#include <map>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::multimap<std::string, std::vector<std::string>> families;
	auto printFamily = [](std::multimap<std::string, std::vector<std::string>>& families) {
		for (const auto& f : families) {
			std::cout << f.first << ": ";
			for (const auto& c : f.second)
				std::cout << c << " ";
			std::cout << std::endl;
		}
	};
	// Add new families
	families.insert({ "HYF", { "GJX", "HTH", "LYF" }});
	families.insert({ "ZZX", { "GJX", "HTH", "LYF" }});
	printFamily(families);

	// Add new children to an existing family
	auto iter = families.find("HYF");
	if (iter != families.end())
		iter->second.push_back("FYH");
	printFamily(families);

	return 0;
}