#include <string>
#include <vector>
#include <iostream>

int main()
{
	const std::string str("ab2c3d7R4E6");
	const std::string number("0123456789");
	const std::string character("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	// Version 1
	std::vector<std::string::size_type> numIndex1;
	std::vector<std::string::size_type> charIndex1;
	for (std::string::size_type pos = 0; (pos = str.find_first_of(number, pos)) != std::string::npos; ++pos)
		numIndex1.push_back(pos);
	for (std::string::size_type pos = 0; (pos = str.find_first_of(character, pos)) != std::string::npos; ++pos)
		charIndex1.push_back(pos);

	std::cout << "VERSION 1" << std::endl;
	std::cout << "Number:";
	for (const auto& n : numIndex1)
		std::cout << " " << str[n];
	std::cout << std::endl << "Character:";
	for (const auto& c : charIndex1)
		std::cout << " " << str[c];
	std::cout << std::endl;

	// Version 2
	std::vector<std::string::size_type> numIndex2;
	std::vector<std::string::size_type> charIndex2;
	for (std::string::size_type pos = 0; (pos = str.find_first_not_of(number, pos)) != std::string::npos; ++pos)
		charIndex2.push_back(pos);
	for (std::string::size_type pos = 0; (pos = str.find_first_not_of(character, pos)) != std::string::npos; ++pos)
		numIndex2.push_back(pos);

	std::cout << std::endl << "VERSION 2" << std::endl;
	std::cout << "Number:";
	for (const auto& n : numIndex2)
		std::cout << " " << str[n];
	std::cout << std::endl << "Character:";
	for (const auto& c : charIndex2)
		std::cout << " " << str[c];
	std::cout << std::endl;

	return 0;
}