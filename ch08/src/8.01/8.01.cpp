#include <iostream>
#include <string>
#include "8.01.h"

std::istream& readStream(std::istream& is) {
	std::string input;
	while (is >> input)
		std::cout << input << std::endl;

	is.clear();
	return is;
}