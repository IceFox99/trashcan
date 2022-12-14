#include "Date.h"

std::istream& operator>>(std::istream& is, Date& date)
{
	is >> date.year >> date.month >> date.day >> date.hour >> date.minute >> date.second;
	if (!is)
		date = Date();
	return is;
}