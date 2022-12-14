#include "13.39/13.39.h"
#include <algorithm>

void StrVec::free()
{
	std::for_each(elements, first_free, [this](std::string& s) { alloc.destroy(&s); });
	alloc.deallocate(elements, capacity());
}