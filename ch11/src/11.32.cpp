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
		if (m.empty())
			return;

		auto iter = m.begin();
		auto lastIter = iter;
		std::cout << iter->first << " - " << "\"" << iter->second << "\" ";
		++iter;
		while (iter != m.end()) {
			if (iter->first != lastIter->first) {
				std::cout << std::endl << iter->first << " - " << "\"" << iter->second << "\" ";
				lastIter = iter;
			}
			else
				std::cout << "\"" << iter->second << "\" ";
			++iter;
		}
	};

	std::multimap<std::string, std::string> m{ { "HYF", "shit" }, { "GJX", "bullshit" }, { "HYF", "another shit" }, { "GJX", "another bullshit" }, { "GJX", "piece of shit" } };
	std::cout << "Before erasing: " << std::endl;
	printMap(m);

	eraseElement(m, { "TEST", "shit" });
	std::cout << std::endl << std::endl << "After erasing a nonexistent element: " << std::endl;
	printMap(m);

	eraseElement(m, { "GJX", "another bullshit" });
	std::cout << std::endl << std::endl << "After erasing an existent element: " << std::endl;
	printMap(m);
	return 0;
}