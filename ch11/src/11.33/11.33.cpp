#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>

void word_transformation(std::ifstream& map_file, std::ifstream& input) {
	std::map<std::string, std::string> m;

	// Initialize the map.
	std::string key, value;
	while (map_file >> key) {
		std::getline(map_file, value);
		if (value.size() > 1)
			m[key] = value.substr(1);
	}

	// Read the input file and transform them.
	std::string line, temp;
	while (std::getline(input, line)) {
		std::istringstream iss(line);
		while (iss >> temp) {
			auto iter = m.find(temp);
			std::cout << (iter != m.cend() ? iter->second : temp) << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::ifstream map_file("src/11.33/map_file.txt");
	std::ifstream input("src/11.33/input.txt");
	word_transformation(map_file, input);
	return 0;
}