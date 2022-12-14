#include "Person.h"
#include <string>
#include <iostream>
using std::string;

Person::Person() = default;

Person::Person(const string & name, const string & address) :
	name(name), address(address) {}

Person::Person(std::istream & is) {
	read(is, *this);
}

string Person::getName() const {
	return name;
}

string Person::getAddress() const {
	return address;
}

std::istream& read(std::istream & is, Person & p) {
	string name, address;
	is >> name >> address;
	p.name = name;
	p.address = address;
	return is;
}

std::ostream& print(std::ostream & os, const Person & p) {
	os << p.getName() << " " << p.getAddress();
	return os;
}