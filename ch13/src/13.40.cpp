#include "13.39/13.39.h"

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	cap = first_free = data.second;
}