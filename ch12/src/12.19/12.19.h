#pragma once
#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	std::vector<std::string>::size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	StrBlob() :
		data(std::make_shared<std::vector<std::string>>()) {}

	StrBlob(std::initializer_list<std::string> li) :
		data(std::make_shared<std::vector<std::string>>(li)) {}

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
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(std::vector<std::string>::size_type i, const std::string& msg) const {
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};

class StrBlobPtr {
public:
	StrBlobPtr() :
		curr(0) {}
	StrBlobPtr(StrBlob& a, std::size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};