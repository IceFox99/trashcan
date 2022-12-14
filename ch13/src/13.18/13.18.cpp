#include "13.18.h"
#include <iostream>

int Employee::incr = 0;

Employee::Employee() :
	id(incr++) {}

Employee::Employee(const std::string& name) :
	name(name), id(incr++) {}

void Employee::print() {
	std::cout << "name: " << name << " id: " << id << std::endl;
}

int main()
{
	Employee a;
	Employee b("test");
	a.print();
	b.print();
	return 0;
}