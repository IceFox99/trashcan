#include "13.39.h"
#include <utility>

StrVec::StrVec(const StrVec& sv)
{
	auto newdata = alloc_n_copy(sv.begin(), sv.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& sv)
{
	auto data = alloc_n_copy(sv.begin(), sv.end());
	free();
	elements = data.first;
	cap = first_free = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(std::size_t newcapacity)
{
	if (newcapacity > capacity())
		alloc_n_move(newcapacity);
}

void StrVec::resize(std::size_t count, const std::string& s)
{
	if (count > size()) {
		if (count > capacity())
			reserve(count * 2);
		for (std::size_t p = 0; p != count - size(); ++p)
			alloc.construct(first_free++, s);
	}
	else if (count < size()) {
		while(first_free != elements + count)
			alloc.destroy(--first_free);
	}
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* beg, const std::string* end)
{
	auto data = alloc.allocate(end - beg);
	return { data, std::uninitialized_copy(beg, end, data) };
}

void StrVec::alloc_n_move(std::size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata; // Temporary pointer
	auto elem = elements; // Temporary pointer
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, capacity());
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}
