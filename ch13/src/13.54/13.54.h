#pragma once
#include <iostream>
#include <string>

class HasPtr {
	friend void swap(HasPtr& lhp, HasPtr& rhp);
	friend bool operator<(const HasPtr& lhp, const HasPtr& rhp);
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& t);

	HasPtr& operator=(HasPtr t) {
		swap(*this, t);
		std::cout << "Copy assignment called." << std::endl;
		return *this;
	}
	//HasPtr& operator=(const HasPtr& t);

	HasPtr(HasPtr&& t) noexcept;
	HasPtr& operator=(HasPtr&& t) noexcept;

	void print() {
		std::cout << *ps << std::endl;
	}

	~HasPtr() {
		delete ps;
	}
private:
	std::string* ps;
	int i;
};

void swap(HasPtr& lhp, HasPtr& rhp);
bool operator<(const HasPtr& lhp, const HasPtr& rhp);