#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>

// Format the string, Delete the character which is not normal alphabetic character like colon or dot, and make them into lowercase.
void FormatString(std::string& str) {
	std::string::size_type pos = 0;
	while ((pos = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789", pos)) != std::string::npos) {
		if (isupper(str[pos]))
			str[pos] = tolower(str[pos]);
		else
			str.erase(pos, 1);
	}
}

int main()
{
	// Initialization
	std::ifstream input("src/12.28/12.28.txt");
	std::vector<std::string> strVec;
	std::map<std::string, std::set<std::size_t>> lineNum;
	std::string tempLine, tempWord;
	int line = 1;
	while (std::getline(input, tempLine)) {
		strVec.push_back(tempLine);
		std::istringstream input(tempLine);
		while (input >> tempWord) {
			FormatString(tempWord);
			if (!tempWord.empty())
				lineNum[tempWord].insert(line);
		}
		++line;
	}

	std::string temp;
	std::cout << "Enter word to look for, or q to quit: ";
	while (std::cin >> temp && temp != "q") {
		// Print the result
		auto lines = lineNum[temp];
		std::cout << temp << " occurs " << lines.size() << " times" << std::endl;
		for (const auto& s : lines)
			std::cout << "\t(line " << s << ") " << strVec.at(s - 1) << std::endl;
		std::cout << std::endl << "Enter word to look for, or q to quit: ";
	}
	return 0;
}