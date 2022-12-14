#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

std::string alphaChar("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string flatChar("aceimnorsuvwxz");

/**
 * Check wheth	er all characters are neither ascenders nor descenders.
 *
 * @param	str	Input string to be detected.
 * @return		A bool values that represent whether all characters are neither ascenders nor descenders.
 */
bool IsAllFlatChar(const std::string& str) {
	return str.find_first_not_of(flatChar) == std::string::npos;
}

/**
 * Delete the character which is not normal alphabetic character like colon or dot.
 *
 * @param str Input string.
 */
void FormatString(std::string& str) {
	std::string::size_type pos = 0;
	while ((pos = str.find_first_not_of(alphaChar, pos)) != std::string::npos)
		str.erase(pos, 1);
}

int main()
{
	std::string word;
	std::vector<std::string> longestWords;
	std::string::size_type longestWordSize = 0;
	std::ifstream input("src/9.49/9.49.txt");
	if (input) {
		while (input >> word) {
			FormatString(word);
			auto wordSize = word.size();
			if (wordSize < longestWordSize || !IsAllFlatChar(word))
				continue;
			else if (wordSize == longestWordSize)
				longestWords.push_back(word);
			else {
				longestWords.clear();
				longestWords.push_back(word);
				longestWordSize = wordSize;
			}
		}
	}
	else
		return -1;

	std::cout << "The longest word that contains neither ascenders nor descenders are:" << std::endl;
	for (const auto& str : longestWords)
		std::cout << str << " ";
	std::cout << std::endl;

	return 0;
}