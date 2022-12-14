#pragma once
#include <iostream>

template <typename Arr>
void print(const Arr& value)
{
	for (const auto& v : value)
		std::cout << v << std::endl;
}