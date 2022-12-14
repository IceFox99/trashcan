#include <iostream>

template <typename T>
void f(T t)
{
	std::cout << "f(T) T: " << typeid(T).name() << std::endl;
}

template <typename T>
void f(const T* p)
{
	std::cout << "f(const T*) T: " << typeid(T).name() << std::endl;
}

template <typename T>
void g(T t)
{
	std::cout << "g(T) T: " << typeid(T).name() << std::endl;
}

template <typename T>
void g(T* p)
{
	std::cout << "g(T*) T: " << typeid(T).name() << std::endl;
}

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);	// g(T) int
	g(p);	// g(T*) int
	g(ci);	// g(T) int
	g(p2);	// g(T*) int
	f(42);	// f(T) int
	f(p);	// f(T) int*
	f(ci);	// f(T) int
	f(p2);	// f(const T*) int
	return 0;
}