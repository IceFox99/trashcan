#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T& t, const Args&... rest)
{
	std::cout << sizeof...(Args) << " " << sizeof...(rest) << std::endl;
}

int main()
{
	int i = 0;
	double d = 3.14;
	std::string s = "how now brown cow";

	foo(i, s, 42, d);	// 3 3
	foo(s, 42, "hi");	// 2 2
	foo(d, s);	// 1 1
	foo("hi"); // 0 0
	return 0;
}