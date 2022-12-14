#pragma once
#include <iostream>
#include <vector>

class StrBlob {
public:
	std::vector<std::string>::size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	StrBlob() :
		data(std::make_shared<std::vector<std::string>>()) {}

	StrBlob(std::initializer_list<std::string> li) :
		data(std::make_shared<std::vector<std::string>>(li)) {}

	// Copy constructor
	StrBlob(const StrBlob& sb) :
		data(std::make_shared<std::vector<std::string>>(*sb.data)) {}

	// Copy assignment operator
	StrBlob& operator=(const StrBlob& sb) {
		data = std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}

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
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(std::vector<std::string>::size_type i, const std::string& msg) const {
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};
