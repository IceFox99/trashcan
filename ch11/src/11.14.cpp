#include <map>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> families;
	auto printFamily = [](std::map<std::string, std::vector<std::pair<std::string, std::string>>>& families) {
		for (const auto& f : families) {
			std::cout << f.first << ": ";
			for (const auto& c : f.second)
				std::cout << c.first << " " << c.second << " ";
			std::cout << std::endl;
		}
	};
	// Add new families
	families["HYF"] = std::vector<std::pair<std::string, std::string>>{ {"GJX", "1999-08-04" }, { "HTH", "1998-11-22" }, { "LYF", "2000-1-1" } };
	printFamily(families);

	// Add new children to an existing family
	families["HYF"].push_back({ "FYH", "1999-02-08" });
	families["HYF"].push_back({ "PZJ", "1999-02-27" });
	printFamily(families);

	return 0;
}