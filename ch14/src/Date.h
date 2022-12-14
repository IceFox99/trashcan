#pragma once
#include <iostream>

class Date {
	friend std::ostream& operator<<(std::ostream& os, const Date& data);
	friend std::istream& operator>>(std::istream& is, Date& date);
	friend bool operator==(const Date& lhs, const Date& rhs);
	friend bool operator!=(const Date& lhs, const Date& rhs);
	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator>(const Date& lhs, const Date& rhs);
	friend Date operator-(const Date& lhs, const Date& rhs);
private:
	unsigned int year, month, day, hour, minute, second;
public:
	Date() = default;
	Date(int year, int month, int day, int hour, int minute, int second) :
		year(year), month(month), day(day), hour(hour), minute(minute), second(second) {}
	Date(const Date& d); // Exercise 14.25
	Date(Date&& d) noexcept; // Exercise 14.25
	Date& operator=(const Date& d); // Exercise 14.24
	Date& operator=(Date&& d) noexcept; // Exercise 14.24
	Date& operator-=(const Date& d); // Exercise 14.25
	explicit operator bool() const; // Exercise 14.49
	void printDate() {
		std::cout << "Year: " << year << "\n"
			<< "Month: " << month << "\n"
			<< "Day: " << day << "\n"
			<< "Hour: " << hour << "\n"
			<< "Minute: " << minute << "\n"
			<< "Second: " << second;
	}
};

std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);
bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
Date operator-(const Date& lhs, const Date& rhs);
