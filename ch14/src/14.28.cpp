#include "StrBlob.h"

StrBlobPtr& StrBlobPtr::operator+=(std::size_t n)
{
	check(curr + n, "increment past end of StrBlobPtr");
	curr += n;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator-=(std::size_t n)
{
	check(curr - n, "decrement past begin of StrBlobPtr");
	curr -= n;
	return *this;
}

StrBlobPtr StrBlobPtr::operator+(std::size_t n)
{
	auto ret = *this;
	ret += n;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(std::size_t n)
{
	auto ret = *this;
	ret -= n;
	return ret;
}