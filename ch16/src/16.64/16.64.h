#pragma once
#include "../16.63/16.63.h"

template <>
std::size_t count(const std::vector<const char*>& vec, const char* const& value)
{
	std::size_t i = 0;
	for (const auto& v : vec) {
		if (!strcmp(v, value))
			++i;
	}
	return i;
}