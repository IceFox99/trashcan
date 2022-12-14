#pragma once
#include <utility>
#include <initializer_list>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

template <typename T> class Blob;
template <typename T> class BlobPtr;

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs);
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>& lhs, const Blob<T>& rhs);
public:
	typedef typename std::vector<T>::size_type size_type;
	Blob() :
		data(std::make_shared<std::vector<T>>()) {}
	Blob(std::initializer_list<T> il) :
		data(std::make_shared<std::vector<T>>(il)) {}
	template <typename Iter> Blob(Iter beg, Iter end); // Exercise 16.24
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T& t) { data->push_back(t); }
	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();
	T& back();
	const T& back() const;
	T& operator[](size_type n);
	const T& operator[](size_type n) const;
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string& msg) const;
};

template <typename T>
class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
	typedef typename Blob<T>::size_type size_type;
	BlobPtr() :
		curr(0) {}
	BlobPtr(Blob<T>& a, size_type sz = 0) :
		wptr(a.data), curr(sz) {}
	T& operator*();
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(size_type i, const std::string& msg) const;
	std::weak_ptr<std::vector<T>> wptr;
	size_type curr;
};

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data == *rhs.data; }

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::operator[](size_type n)
{
	check(n, "out of range");
	return data->at(n);
}

template <typename T>
const T& Blob<T>::operator[](size_type n) const
{
	check(n, "out of range");
	return data->at(n);
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_type i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("BlobPtr to different Blobs!");
	return lhs.curr == rhs.curr;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr - 1, "decrement past begin of StrBlobPtr");
	--curr;
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++* this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	auto ret = *this;
	--* this;
	return ret;
}

template <typename T>
T& BlobPtr<T>::operator*()
{
	auto p = check(curr, "out of range");
	return (*p)[curr];
}