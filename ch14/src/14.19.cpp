#include "Date.h"

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.year < rhs.year)
		return true;
	else if (lhs.year > rhs.year)
		return false;
	else if (lhs.month < rhs.month)
		return true;
	else if (lhs.month > rhs.month)
		return false;
	else if (lhs.day < rhs.day)
		return true;
	else if (lhs.day > rhs.day)
		return false;
	else if (lhs.hour < rhs.hour)
		return true;
	else if (lhs.hour > rhs.hour)
		return false;
	else if (lhs.minute < rhs.minute)
		return true;
	else if (lhs.minute > rhs.minute)
		return false;
	else if (lhs.second < rhs.second)
		return true;
	else
		return false;
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return rhs < lhs;
}
