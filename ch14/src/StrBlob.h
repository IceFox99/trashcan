#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <initializer_list>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
	friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
	friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	std::vector<std::string>::size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	StrBlob() :
		data(std::make_shared<std::vector<std::string>>()) {}

	StrBlob(std::initializer_list<std::string> li) :
		data(std::make_shared<std::vector<std::string>>(li)) {}

	std::string& operator[](std::size_t n); // Exercise 14.26
	const std::string& operator[](std::size_t n) const; // Exercise 14.26

	std::string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back() {
		check(0, "back on empty StrBlob");
		return data->back();
	}

	void push_back(const std::string& str) { data->push_back(str); }

	void pop_back() {
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(std::vector<std::string>::size_type i, const std::string& msg) const {
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
	friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
public:
	StrBlobPtr() :
		curr(0) {}
	StrBlobPtr(StrBlob& a, std::size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	std::string& operator[](std::size_t n); // Exercise 14.26
	const std::string& operator[](std::size_t n) const; // Exercise 14.26
	StrBlobPtr& operator++(); // Exercise 14.27
	StrBlobPtr& operator--(); // Exercise 14.27
	StrBlobPtr operator++(int); // Exercise 14.27
	StrBlobPtr operator--(int);	// Exercise 14.27
	StrBlobPtr& operator+=(std::size_t); // Exercise 14.28
	StrBlobPtr& operator-=(std::size_t); // Exercise 14.28
	StrBlobPtr operator+(std::size_t); // Exercise 14.28
	StrBlobPtr operator-(std::size_t); // Exercise 14.28
	std::string& operator*(); // Exercise 14.30
	std::string* operator->(); // Exercise 14.30
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :
		curr(0) {}
	ConstStrBlobPtr(const StrBlob& a, std::size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	const std::string& deref() const;
	ConstStrBlobPtr& incr();
	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
	const std::string& operator*(); // Exercise 14.30
	const std::string* operator->(); // Exercise 14.30
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};