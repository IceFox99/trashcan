#include "Date.h"

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.month << "/" << date.day << "/" << date.year << " " << date.hour << ":" << date.minute << ":" << date.second;
	return os;
}
