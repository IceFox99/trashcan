#pragma once
#include <string>
#include <sstream>

template <typename T>
std::string debug_rep(const T& t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T>
std::string debug_rep(T* p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

// Specialization where T = const char, char respectively.
template <>
std::string debug_rep(const char* p)
{
	std::ostringstream ret;
	ret << "pointer: " << static_cast<const void*>(p);
	if (p)
		ret << " " << std::string(p);
	else
		ret << " null pointer";
	return ret.str();
}

template <>
std::string debug_rep(char* p)
{
	std::ostringstream ret;
	ret << "pointer: " << static_cast<const void*>(p);
	if (p)
		ret << " " << std::string(p);
	else
		ret << " null pointer";
	return ret.str();
}