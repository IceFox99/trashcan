#include <utility>
#include <iostream>

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
	int i = 100;
	auto func = [](int&& i, int& j)
	{
		std::cout << i << " | " << ++j << std::endl;
	};
	flip(func, i, 50);
	flip(func, i, 60);
	flip(func, i, 70);
	std::cout << i << std::endl;
	return 0;
}