#include <map>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::map<std::string, std::vector<std::string>> families;
	auto printFamily = [](std::map<std::string, std::vector<std::string>>& families) {
		for (const auto& f : families) {
			std::cout << f.first << ": ";
			for (const auto& c : f.second)
				std::cout << c << " ";
			std::cout << std::endl;
		}
	};
	// Add new families
	families["HYF"] = std::vector<std::string>{ "GJX", "HTH", "LYF" };
	printFamily(families);

	// Add new children to an existing family
	families["HYF"].push_back("FYH");
	families["HYF"].push_back("PZJ");
	printFamily(families);

	return 0;
}