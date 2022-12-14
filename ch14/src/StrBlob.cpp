#include "StrBlob.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound ConstStrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

const std::string& ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}