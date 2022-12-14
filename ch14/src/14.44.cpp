#include <map>
#include <functional>
#include <string>
#include <iostream>

int main()
{
	std::map<std::string, std::function<int(int, int)>> binops;
	auto add = [](int i, int j) { return i + j; };
	auto sub = [](int i, int j) { return i - j; };
	auto mul = [](int i, int j) { return i * j; };
	auto div = [](int i, int j) { return i / j; };
	auto mod = [](int i, int j) { return i % j; };
	binops.insert({ "+", add });
	binops.insert({ "-", sub });
	binops.insert({ "*", mul });
	binops.insert({ "/", div });
	binops.insert({ "%", mod });

	int a = 10, b = 2;
	std::cout << a << " + " << b << " = " << binops["+"](a, b) << std::endl;
	std::cout << a << " - " << b << " = " << binops["-"](a, b) << std::endl;
	std::cout << a << " * " << b << " = " << binops["*"](a, b) << std::endl;
	std::cout << a << " / " << b << " = " << binops["/"](a, b) << std::endl;
	std::cout << a << " % " << b << " = " << binops["%"](a, b) << std::endl;

	return 0;
}