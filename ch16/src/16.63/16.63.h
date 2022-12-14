#pragma once
#include <vector>

template <typename T>
std::size_t count(const std::vector<T>& vec, const T& value)
{
	std::size_t i = 0;
	for (const auto& v : vec) {
		if (v == value)
			++i;
	}
	return i;
}