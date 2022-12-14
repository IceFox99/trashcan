#pragma once
#include <iostream>
#include <string>

class ReadString {
public:
	ReadString(std::istream& is = std::cin) :
		is(is) {}
	std::string operator()()
	{
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
private:
	std::istream& is;
};
