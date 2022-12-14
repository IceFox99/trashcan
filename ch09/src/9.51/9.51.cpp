#include "9.51.h"
#include <vector>
#include <sstream>

std::vector<std::string> months{ "Jan", "January", "Feb", "February", "Mar", "March", "Apr", "April", "May", "May", "Jun", "June", "Jul", "July", "Aug", "August", "Sep", "September", "Oct", "October", "Nov", "November", "Dec", "December" };
std::string characters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string numbers("0123456789");

DateStr::DateStr(std::string s) {
	std::string::size_type index = 0;
	while ((index = s.find_first_not_of(characters + numbers + " ", index)) != std::string::npos)
		s[index] = ' ';
	std::istringstream ss(s);
	std::string year, month, day;
	ss >> month >> day >> year;
	if (month.find_first_of(numbers) == std::string::npos) {
		this->month = (std::find(months.cbegin(), months.cend(), month) - months.cbegin()) / 2 + 1;
	}
	else
		this->month = std::stoi(month);
	this->day = std::stoi(day);
	this->year = std::stoi(year);
}

// For testing
int main()
{
	DateStr d1("Oct 21, 1985");
	DateStr d2("7/30/2021");
	DateStr d3("April 8, 1875");

	d1.PrintDate();
	std::cout << std::endl;
	d2.PrintDate();
	std::cout << std::endl;
	d3.PrintDate();
	std::cout << std::endl;
	return 0;
}