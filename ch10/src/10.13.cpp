#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

inline bool hasFiveChar(const std::string& s) {
	return s.size() >= 5;
}

int main()
{
	std::vector<std::string> strVec{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	auto end = std::partition(strVec.begin(), strVec.end(), hasFiveChar);
	for (auto iter = strVec.cbegin(); iter != end; ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
	return 0;
}