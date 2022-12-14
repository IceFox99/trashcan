#pragma once
#include <iostream>

template <typename T>
std::ostream& print(std::ostream& os, const T& t)
{
	for (typename T::size_type i = 0; i != t.size(); ++i)
		os << t[i] << " ";
	return os;
}