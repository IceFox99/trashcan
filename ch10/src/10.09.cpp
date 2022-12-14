#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

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

int main()
{
	std::vector<std::string> strVec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	elimDups(strVec);
	return 0;
}