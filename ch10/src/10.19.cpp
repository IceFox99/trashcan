#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void printStrVecln(const std::vector<std::string>& strVec) {
	for (const auto& str : strVec)
		std::cout << str << " ";
	std::cout << std::endl;
}

void elimDups(std::vector<std::string>& strVec) {
	std::cout << "Before eliminating: ";
	printStrVecln(strVec);

	std::sort(strVec.begin(), strVec.end());
	std::cout << "After sorting: ";
	printStrVecln(strVec);

	auto end = std::unique(strVec.begin(), strVec.end());
	std::cout << "After unique: ";
	printStrVecln(strVec);

	strVec.erase(end, strVec.cend());
	std::cout << "After erasing: ";
	printStrVecln(strVec);
}

void biggies(std::vector<std::string>& strVec, std::vector<std::string>::size_type sz) {
	elimDups(strVec);

	std::stable_sort(strVec.begin(), strVec.end(), [](const std::string& s1, const std::string& s2) {
		return s1.size() < s2.size();
		});
	std::cout << "After stable sorting: ";
	printStrVecln(strVec);

	auto end = std::stable_partition(strVec.begin(), strVec.end(), [sz](const std::string& s) {
		return s.size() >= sz;
		});

	auto count = end - strVec.cbegin();
	std::cout << "There " << ((count > 1) ? "are " : "is ") << count << ((count > 1) ? " words " : " word ") << "whose length is no less than " << sz << "." << std::endl;

	std::cout << "After comparing: ";
	std::for_each(strVec.begin(), end, [](const std::string& s) {
		std::cout << s << " ";
		});
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> strVec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(strVec, 4);
	return 0;
}