#include <string>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std::placeholders;

bool check_size(const std::string& s, std::string::size_type sz) {
	return s.size() >= sz;
}

int main()
{
	std::vector<int> iVec{ 0, 1, 1, 2, 3, 5, 8, 13, 21 };
	std::cout << *(std::find_if_not(iVec.cbegin(), iVec.cend(), std::bind(check_size, "shit", _1))) << std::endl;
	return 0;
}