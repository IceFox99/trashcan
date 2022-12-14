#include <iostream>

int main()
{
	const int i = 42;
	auto j = i;
	auto const& k = i;
	auto* p = &i;
	const auto j2 = i, & k2 = i;

	std::cout << "type of i: " << typeid(i).name()
		<< "\ntype of j: " << typeid(j).name()
		<< "\ntype of k: " << typeid(k).name()
		<< "\ntype of p: " << typeid(p).name()
		<< "\ntype of j2: " << typeid(j2).name()
		<< "\ntype of k2: " << typeid(k2).name() << std::endl;
	return 0;
}