#include "Date.h"

Date& Date::operator=(const Date& d)
{
	if (this != &d) {
		year = d.year;
		month = d.month;
		day = d.day;
		hour = d.hour;
		minute = d.minute;
		second = d.second;
	}
	return *this;
}

Date& Date::operator=(Date&& d) noexcept
{
	if (this != &d) {
		year = d.year;
		month = d.month;
		day = d.day;
		hour = d.hour;
		minute = d.minute;
		second = d.second;
	}
	return *this;
}