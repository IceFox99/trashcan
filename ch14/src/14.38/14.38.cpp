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
	std::size_t counts = 0;
	TestLength tl(1, 10);
	std::ifstream input("src/14.38/14.38.txt");
	for (std::string word; input >> word; ) {
		if (tl(FormatString(word)))
			++counts;
	}
	std::cout << counts << std::endl;
	return 0;
}