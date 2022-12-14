#pragma once

template <typename T, unsigned size>
constexpr unsigned getSize(const T(&arr)[size])
{
	return size;
}
