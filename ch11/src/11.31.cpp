#include <map>
#include <string>
#include <iostream>

int main()
{
	auto eraseElement = [](std::multimap<std::string, std::string>& m, const std::pair<std::string, std::string>& p) {
		auto iter = m.find(p.first);
		auto cnt = m.count(p.first);
		while (cnt) {
			if (iter->second == p.second) {
				m.erase(iter);
				break;
			}
			--cnt;
			++iter;
		}
	};

	auto printMap = [](std::multimap<std::string, std::string>& m) {
		for (const auto& p : m)
			std::cout << p.first << " - " << p.second << std::endl;
	};

	std::multimap<std::string, std::string> m{ { "HYF", "shit" }, { "GJX", "bullshit" }, { "HYF", "another shit" } };
	std::cout << "Before erasing: " << std::endl;
	printMap(m);

	eraseElement(m, { "TEST", "shit" });
	std::cout << std::endl << "After erasing a nonexistent element: " << std::endl;
	printMap(m);

	eraseElement(m, { "HYF", "shit" });
	std::cout << std::endl << "After erasing an existent element: " << std::endl;
	printMap(m);
	return 0;
}