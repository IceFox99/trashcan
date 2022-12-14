#pragma once
#include <iostream>

template <typename T>
std::ostream& print2(std::ostream& os, const T& t)
{
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		os << *iter << " ";
	return os;
}