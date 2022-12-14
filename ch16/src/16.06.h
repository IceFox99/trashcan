#pragma once

namespace ch16
{
	template <typename T, unsigned size>
	T* begin(T (&arr)[size])
	{
		return arr;
	}

	template <typename T, unsigned size>
	T* end(T (&arr)[size])
	{
		return arr + size;
	}
}
