#include "StrBlob.h"

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	check(curr - 1, "decrement past begin of StrBlobPtr");
	--curr;
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	auto ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	auto ret = *this;
	--*this;
	return ret;
}