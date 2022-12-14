#include <vector>
#include <iostream>
#include <algorithm>

class Foo {
public:
	Foo sorted()&&;
	Foo sorted() const&;
private:
	std::vector<int> data;
};

Foo Foo::sorted()&&
{
	std::sort(data.begin(), data.end());
	std::cout << "&& called." << std::endl;
	return *this;
}

Foo Foo::sorted() const&
{
	Foo ret(*this);
	std::sort(ret.data.begin(), ret.data.end());
	std::cout << "const & called." << std::endl;
	return ret;
}

int main()
{
	Foo().sorted(); // &&

	Foo f1;
	f1.sorted(); // const &

	const Foo f2;
	f2.sorted(); // const &

	return 0;
}