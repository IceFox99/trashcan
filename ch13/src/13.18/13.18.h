#pragma once
#include <string>

class Employee {
public:
	Employee();
	Employee(const std::string& name);
	void print();
private:
	std::string name;
	int id;
	static int incr;
};