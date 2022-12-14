#pragma once
#include <string>
#include <iostream>
class Person {
	friend std::istream& read(std::istream&, Person&);
	friend std::ostream& print(std::ostream&, const Person&);
private:
	std::string name;
	std::string address;
public:
	Person();
	Person(const std::string& name, const std::string& address);
	explicit Person(std::istream& is);
	std::string	getName() const;
	std::string getAddress() const;
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);
