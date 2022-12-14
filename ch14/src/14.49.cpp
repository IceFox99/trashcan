#include "Date.h"

explicit Date::operator bool() const
{
	return year >= 1970;
}