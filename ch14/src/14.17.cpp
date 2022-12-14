#include "Date.h"

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.year == rhs.year) && (lhs.month == rhs.month) && (lhs.day == rhs.day) && (lhs.hour == rhs.hour) && (lhs.minute == lhs.minute) && (lhs.second == rhs.second);
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}