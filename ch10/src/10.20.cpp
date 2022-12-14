#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::size_t biggerThanSize(const std::vector<std::string>& strVec, std::size_t sz) {
	return std::count_if(strVec.cbegin(), strVec.cend(), [sz](const std::string& s) {
		return s.size() > sz;
		});
}

int main()
{
	std::vector<std::string> strVec{ "Hello", "Motherfucker", "Shit", "Asshole", "Bitch", "Trash", "Fuck", "Bastard" };
	auto count = biggerThanSize(strVec, 6);
	std::cout << "There " << ((count > 1) ? "are " : "is ") << count << ((count > 1) ? " words " : " word ") << "whose length is more than " << 6 << "." << std::endl;
	return 0;
}