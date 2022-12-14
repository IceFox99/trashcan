#include "String.h"
#include "StrBlob.h"
#include "StrVec.h"

std::string& StrBlob::operator[](std::size_t n)
{
	check(n, "out of range");
	return data->at(n);
}

const std::string& StrBlob::operator[](std::size_t n) const
{
	check(n, "out of range");
	return data->at(n);
}

std::string& StrBlobPtr::operator[](std::size_t n)
{
	auto sp = check(n, "out of range");
	return sp->at(n);
}

const std::string& StrBlobPtr::operator[](std::size_t n) const
{
	auto sp = check(n, "out of range");
	return sp->at(n);
}

std::string& StrVec::operator[](std::size_t n)
{
	return elements[n];
}

const std::string& StrVec::operator[](std::size_t n) const
{
	return elements[n];
}

char& String::operator[](std::size_t n)
{
	return beg[n];
}

const char& String::operator[](std::size_t n) const
{
	return beg[n];
}