#include <iostream>

int main()
{
	// fisrt instance
	int i1 = 0, * iptr1 = &i1;
	decltype(iptr1) j1 = iptr1;
	auto k1 = iptr1;
	std::cout << "type of j1: " << typeid(j1).name() << std::endl;
	std::cout << "type of k1: " << typeid(k1).name() << std::endl;

	// second instance
	int i2 = 0;
	int* const iptr2 = &i2;
	decltype(iptr2) j2 = iptr2;
	auto k2 = iptr2;
	//j2 = &i1; Error, j2 is a int *const
	//k2 = &i1; Pass, k2 is int *
	std::cout << "\ntype of iptr2: " << typeid(iptr2).name() << std::endl;
	std::cout << "type of j2: " << typeid(j2).name() << std::endl;
	std::cout << "type of k2: " << typeid(k2).name() << std::endl;

	return 0;
}