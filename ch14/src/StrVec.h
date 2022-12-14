#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <initializer_list>

class StrVec {
	friend bool operator==(const StrVec& lhs, const StrVec& rhs);
	friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec& sv);
	StrVec& operator=(const StrVec& sv);
	StrVec(StrVec&& sv) noexcept; // Exercise 13.49
	StrVec& operator=(StrVec&& sv) noexcept; // Exercise 13.49
	StrVec& operator=(std::initializer_list<std::string> il); // Exercise 14.23
	std::string& operator[](std::size_t n); // Exercise 14.26
	const std::string& operator[](std::size_t n) const; // Exercise 14.26
	~StrVec();

	void push_back(const std::string& s);
	std::size_t size() const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	const std::string& at(std::size_t pos);

	void reserve(std::size_t newcapacity);
	void resize(std::size_t count, const std::string& s = std::string());
private:
	std::allocator<std::string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string* beg, const std::string* end);
	void alloc_n_move(std::size_t newcapacity);
	void free();
	void reallocate();
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};