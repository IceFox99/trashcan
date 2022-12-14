#pragma once
#include <iostream>
#include <string>

class HasPtr {
	friend void swap(HasPtr& lhp, HasPtr& rhp);
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& t) :
		ps(new std::string(*t.ps)), i(t.i) {}
	HasPtr& operator=(const HasPtr& t) {
		if (this != &t) {
			std::string* temp = new std::string(*t.ps);
			delete ps;
			ps = temp;
			i = t.i;
		}
		return *this;
	}

	~HasPtr() {
		delete ps;
	}
private:
	std::string* ps;
	int i;
};

inline void swap(HasPtr& lhp, HasPtr& rhp) {
	using std::swap;
	swap(lhp.ps, rhp.ps);
	swap(lhp.i, rhp.i);
	std::cout << "Call the function swap(HasPtr& lhp, HasPtr& rhp)." << std::endl;
}
