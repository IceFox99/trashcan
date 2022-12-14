#pragma once
#include <string>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr& t) :
		ps(t.ps), i(t.i), use(t.use) { ++*use; }
	HasPtr& operator=(const HasPtr& t) {
		++*t.use;
		if (--*use == 0) {
			delete ps;
			delete use;
		}
		ps = t.ps;
		i = t.i;
		use = t.use;
		return *this;
	}

	~HasPtr() {
		if (--*use == 0) {
			delete ps;
			delete use;
		}
	}
private:
	std::string* ps;
	int i;
	std::size_t* use;
};
