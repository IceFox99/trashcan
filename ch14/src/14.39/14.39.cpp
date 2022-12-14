#include <iostream>
#include <fstream>
#include <map>

// Format the string, Delete the character which is not normal alphabetic character like colon or dot, and make them into lowercase.
std::string& FormatString(std::string& str) {
	std::string::size_type pos = 0;
	while ((pos = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789", pos)) != std::string::npos) {
		if (isupper(str[pos]))
			str[pos] = tolower(str[pos]);
		else
			str.erase(pos, 1);
	}
	return str;
}

class TestLength {
public:
	TestLength(std::size_t ll, std::size_t ul) :
		lowerLimit(ll), upperLimit(ul) {}
	bool operator()(const std::string& str)
	{
		return (str.size() >= lowerLimit) && (str.size() <= upperLimit);
	}
private:
	std::size_t lowerLimit, upperLimit;
};

int main()
{
	std::size_t counts1 = 0;
	std::size_t counts2 = 0;

	TestLength tl1(1, 9);
	TestLength tl2(10, 100);
	std::ifstream input("src/14.39/14.39.txt");
	for (std::string word; input >> word; ) {
		FormatString(word);
		if (tl1(word))
			++counts1;
		else if (tl2(word))
			++counts2;
	}
	std::cout << "1 through 9: " << counts1 << std::endl;
	std::cout << "10 or more: " << counts2 << std::endl;
	return 0;
}