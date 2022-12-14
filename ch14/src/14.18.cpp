#include "String.h"
#include <algorithm>

bool operator<(const String& lhs, const String& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String& lhs, const String& rhs)
{
	return rhs < lhs;
}