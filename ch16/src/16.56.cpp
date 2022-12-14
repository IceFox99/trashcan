#include "16.48.h"

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

template <typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	errorMsg(std::cout, 1, 1, 2, 3.14159, 5.0f, "test", false);
	return 0;
}