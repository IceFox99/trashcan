#pragma once
#include <string>
#include <iostream>

class DateStr {
private:
	unsigned int year, month, day;
public:
	DateStr(std::string s);
	inline void PrintDate() { std::cout << year << "-" << month << "-" << day; }
};
