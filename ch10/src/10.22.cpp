#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <string>

using namespace std::placeholders;

bool isShorter(const std::string& s, std::string::size_type sz) {
	return s.size() <= sz;
}

int main()
{
	std::vector<std::string> strVec{ "Hello", "Motherfucker", "Shit", "Asshole", "Bitch", "Trash", "Fuck", "Bastard" };
	std::cout << std::count_if(strVec.cbegin(), strVec.cend(), std::bind(isShorter, _1, 6)) << std::endl;
	return 0;
}
