#include "StrBlob.h"

std::string& StrBlobPtr::operator*()
{
	auto p = check(curr, "out of range");
	return (*p)[curr];
}

std::string* StrBlobPtr::operator->()
{
	return &(this->operator*());
}

const std::string& ConstStrBlobPtr::operator*()
{
	auto p = check(curr, "out of range");
	return (*p)[curr];
}

const std::string* ConstStrBlobPtr::operator->()
{
	return &(this->operator*());
}