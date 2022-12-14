#include "String.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const String& str)
{
	char* c = const_cast<char*>(str.c_str());
	while (*c)
		os << *c++;
	return os;
}