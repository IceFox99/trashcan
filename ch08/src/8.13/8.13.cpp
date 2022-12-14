#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};

bool valid(const std::string& str) {
	return isdigit(str[0]);
}

std::string format(const std::string& str) {
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::ifstream input("src/8.13/8.13.txt");
	if (input) {
		while (getline(input, line)) {
			PersonInfo info;
			std::istringstream record(line);
			record >> info.name;
			while (record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
	}

	for (const auto& entry : people) {
		std::ostringstream formatted, badNums;
		for (const auto& nums : entry.phones) {
			if (!valid(nums))
				badNums << " " << nums;
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			std::cout << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
	}

	return 0;
}