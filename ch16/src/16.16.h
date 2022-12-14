#pragma once
#include <memory>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vec;

template <typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs);
template <typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs);

template <typename T>
class Vec {
	friend bool operator==<T>(const Vec<T>& lhs, const Vec<T>& rhs);
	friend bool operator!=<T>(const Vec<T>& lhs, const Vec<T>& rhs);
public:
	Vec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T> il);
	Vec(const Vec& v);
	Vec& operator=(const Vec& v);
	Vec(Vec&& v) noexcept;
	Vec& operator=(Vec&& v) noexcept;
	Vec& operator=(std::initializer_list<T> il);
	T& operator[](std::size_t n);
	const T& operator[](std::size_t n) const;
	~Vec();

	void push_back(const T& t);
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }
	const T& at(std::size_t pos);

	void reserve(std::size_t newcapacity);
	void resize(std::size_t count, const T& t = T());
private:
	std::allocator<T> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<T*, T*> alloc_n_copy(const T* beg, const T* end);
	void alloc_n_move(std::size_t newcapacity);
	void free();
	void reallocate();
	T* elements;
	T* first_free;
	T* cap;
};

template <typename T>
Vec<T>::Vec(std::initializer_list<T> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	cap = first_free = data.second;
}

template <typename T>
Vec<T>::Vec(const Vec<T>& v)
{
	auto newdata = alloc_n_copy(v.begin(), v.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& v)
{
	auto data = alloc_n_copy(v.begin(), v.end());
	free();
	elements = data.first;
	cap = first_free = data.second;
	return *this;
}

template <typename T>
Vec<T>::Vec(Vec&& v) noexcept :
	elements(v.elements), first_free(first_free), cap(cap)
{
	v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec&& v) noexcept
{
	if (this != &v) {
		free();
		elements = v.elements;
		first_free = v.first_free;
		cap = v.cap;
		v.elements = v.first_free = v.cap = nullptr;
	}
	return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
T& Vec<T>::operator[](std::size_t n)
{
	if (n > size() - 1)
		throw std::out_of_range("out of range");
	return elements[n];
}

template <typename T>
const T& Vec<T>::operator[](std::size_t n) const
{
	if (n > size() - 1)
		throw std::out_of_range("out of range");
	return elements[n];
}

template <typename T>
Vec<T>::~Vec()
{
	free();
}

template <typename T>
void Vec<T>::push_back(const T& t)
{
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template <typename T>
const T& Vec<T>::at(std::size_t pos)
{
	return this[pos];
}

template <typename T>
void Vec<T>::reserve(std::size_t newcapacity)
{
	if (newcapacity > capacity())
		alloc_n_move(newcapacity);
}

template <typename T>
void Vec<T>::resize(std::size_t count, const T& t /*= T()*/)
{
	if (count > size()) {
		if (count > capacity())
			reserve(count * 2);
		for (std::size_t p = 0; p != count - size(); ++p)
			alloc.construct(first_free++, t);
	}
	else if (count < size()) {
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* beg, const T* end)
{
	auto data = alloc.allocate(end - beg);
	return { data, std::uninitialized_copy(beg, end, data) };
}

template <typename T>
void Vec<T>::alloc_n_move(std::size_t newcapacity)
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

template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, capacity());
	}
}

template <typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

template <typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs)
{
	if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
		return false;
	else {
		auto lPtr = lhs.begin(), rPtr = rhs.begin();
		for (std::size_t i = 0; i != lhs.size(); ++i) {
			if (*lPtr++ != *rPtr++)
				return false;
		}
		return true;
	}
}

template <typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs)
{
	return !(lhs == rhs);
}