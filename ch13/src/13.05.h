#pragma once
#include <string>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& t) :
		ps(new std::string(*t.ps)), i(t.i) {}
private:
	std::string* ps;
	int i;
};