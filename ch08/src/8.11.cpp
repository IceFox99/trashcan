#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};

int main()
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;
	while (getline(std::cin, line)) {
		PersonInfo info;
		//std::istringstream record(line); Original code!

		// Core code
		record.clear(); // Clear the EOF state.
		record.str(line);

		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	// For testing
	/*for (const auto& p : people) {
		std::cout << p.name;
		for (auto& phone : p.phones)
			std::cout << " " << phone;
		std::cout << std::endl;
	}*/

	return 0;
}