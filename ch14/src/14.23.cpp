#include "StrVec.h"

StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	cap = first_free = data.second;
	return *this;
}