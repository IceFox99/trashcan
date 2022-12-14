#include <iostream>

int main()
{
	/*
		Initiate the variable
	*/
	int i = 0, & r = i;
	auto a = r;
	const int ci = i, & cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto& g = ci;

	/*
		Print the initial value
	*/
	std::cout << "The initial values are"
		<< "\na: " << a
		<< "\nb: " << b
		<< "\nc: " << c
		<< "\nd: " << d << "\t*d: " << *d
		<< "\ne: " << e << "\t*e: " << *e
		<< "\ng: " << g << std::endl;

	/*
		Change the value
	*/
	a = 42; b = 42; c = 42;
	//d = 42;
	//e = 42;
	//g = 42;

	/*
		Print the value after changing
	*/
	std::cout << "\nThe initial values are"
		<< "\na: " << a
		<< "\nb: " << b
		<< "\nc: " << c
		<< "\nd: " << d << "\t*d: " << *d
		<< "\ne: " << e << "\t*e: " << *e
		<< "\ng: " << g << std::endl;
	return 0;
}