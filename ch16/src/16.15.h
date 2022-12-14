#pragma once
#include "16.14.h"

template <unsigned H, unsigned W>
std::istream& operator>>(std::istream& is, Screen<H, W>& s)
{
	char c;
	is >> c;
	std::string temp(H * W, c);
	s.contents = temp;
	return is;
}

template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s)
{
	for (unsigned i = 0; i != s.height; ++i)
		os << s.contents.substr(i * s.width, s.width) << std::endl;
	return os;
}