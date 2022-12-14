#pragma once
#include <string>
#include <iostream>

class Date {
private:
	int year, month, day, hour, minute, second;
public:
	Date() = default;
	Date(int year, int month, int day, int hour, int minute, int second) :
		year(year), month(month), day(day), hour(hour), minute(minute), second(second) {}
	void printDate() {
		std::cout << "Year: " << year << "\n"
			<< "Month: " << month << "\n"
			<< "Day: " << day << "\n"
			<< "Hour: " << hour << "\n"
			<< "Minute: " << minute << "\n"
			<< "Second: " << second;
	}
};