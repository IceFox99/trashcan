#pragma once
#include <string>

class HasPtr {
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