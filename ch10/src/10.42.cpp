#include <list>
#include <string>
#include <iostream>
#include <algorithm>

void printStrVecln(const std::list<std::string>& strVec) {
	for (const auto& str : strVec)
		std::cout << str << " ";
	std::cout << std::endl;
}

void elimDups(std::list<std::string>& strVec) {
	std::cout << "Before eliminating: ";
	printStrVecln(strVec);

	strVec.sort();
	std::cout << "After sorting: ";
	printStrVecln(strVec);

	strVec.unique();
	std::cout << "After unique: ";
	printStrVecln(strVec);
}

int main()
{
	std::list<std::string> strVec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	elimDups(strVec);
	return 0;
}