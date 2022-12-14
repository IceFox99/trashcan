#include <iostream>

int main()
{
	int i = 0, & r1 = i;
	double d = 0, & r2 = d;
	//r2 = 3.14159;
	//r2 = r1;
	//i = r2;
	//r1 = d;

	std::cout << "i is " << i
		<< "\nr1 is " << r1
		<< "\nd is " << d
		<< "\nr2 is " << r2 << std::endl;
	return 0;
}