#include "Date.h"

Date& Date::operator-=(const Date& d)
{
	year -= d.year;
	month -= d.month;
	day -= d.day;
	hour -= d.hour;
	minute -= d.minute;
	second -= d.second;
	return *this;
}

Date::Date(const Date& d)
	: year(d.year), month(d.month), day(d.day), hour(d.hour), minute(d.minute), second(d.second) {}

Date::Date(Date&& d) noexcept
	: year(d.year), month(d.month), day(d.day), hour(d.hour), minute(d.minute), second(d.second) {}

Date operator-(const Date& lhs, const Date& rhs)
{
	Date sub = lhs;
	sub -= rhs;
	return sub;
}