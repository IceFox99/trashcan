#pragma once
#include <string>

class Employee {
public:
	Employee();
	Employee(const std::string& name);
	Employee(const Employee& e) = delete;
	Employee& operator=(const Employee& e) = delete;
	void print();
private:
	std::string name;
	int id;
	static int incr;
};
