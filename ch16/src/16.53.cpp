#include <iostream>

template <typename T>
std::ostream& print(std::ostream& os, const T& t)
{
	return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	print(std::cout, 100) << std::endl;
	print(std::cout, 50, "fuck") << std::endl;
	print(std::cout, 25, 3.14159, "three", true, 0) << std::endl;
	return 0;
}