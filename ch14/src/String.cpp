#include "String.h"
#include <iostream>

String::String(const char* str)
{
	auto temp = str;
	while (*temp)
		++temp;
	auto newdata = alloc_n_copy(str, ++temp);
	beg = newdata.first;
	cap = first_free = newdata.second;
}

String::String(const String& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	beg = newdata.first;
	cap = first_free = newdata.second;
	std::cout << "Copy constructor." << std::endl; // Exercise 13.47
}

String& String::operator=(const String& s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	beg = data.first;
	cap = first_free = data.second;
	std::cout << "Copy assignment." << std::endl; // Exercise 13.47
	return *this;
}

String::~String()
{
	free();
}

void String::push_back(char c)
{
	chk_n_alloc();
	alloc.construct(first_free - 1, c);
	alloc.construct(first_free++, '\0');
}

void String::reserve(std::size_t new_cap)
{
	if (new_cap > capacity())
		alloc_n_move(new_cap);
}

void String::resize(std::size_t count, char new_ch /*= '\0'*/)
{
	if (count > size()) {
		if (count > capacity())
			reserve(count * 2);

		alloc.construct(first_free - 1, new_ch);
		for (auto p = first_free; p != begin() + count - 1; ++p)
			alloc.construct(first_free++, new_ch);
		alloc.construct(first_free++, '\0');
	}
	else if (count < size()) {
		while (first_free != beg + count)
			alloc.destroy(--first_free);
		*(first_free - 1) = '\0';
	}
}

void String::free()
{
	if (beg) {
		for (auto p = first_free; p != beg;)
			alloc.destroy(--p);
		alloc.deallocate(beg, capacity());
	}
}

void String::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	alloc_n_move(newcapacity);
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void String::alloc_n_move(std::size_t new_capacity)
{
	auto newdata = alloc.allocate(new_capacity);
	auto dest = newdata; // Temporary pointer
	auto temp_beg = beg; // Temporary pointer
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*temp_beg++));
	free();
	beg = newdata;
	first_free = dest;
	cap = beg + new_capacity;
}


