#include <iostream>

class numbered1 {
public:
	numbered1() :
		mysn(unique1++) {}
	int mysn;
	static int unique1;
};

class numbered2 {
public:
	numbered2() :
		mysn(unique2++) {}
	numbered2(const numbered2& n) :
		mysn(unique2++) {}
	int mysn;
	static int unique2;
};

class numbered3 {
public:
	numbered3() :
		mysn(unique3++) {}
	numbered3(const numbered3& n) :
		mysn(unique3++) {}
	int mysn;
	static int unique3;
};

int numbered1::unique1 = 10;
int numbered2::unique2 = 10;
int numbered3::unique3 = 10;

void f1(numbered1 s) {
	std::cout << s.mysn << std::endl;
}

void f2(numbered2 s) {
	std::cout << s.mysn << std::endl;
}

void f3(const numbered3& s) {
	std::cout << s.mysn << std::endl;
}

int main()
{
	// Ex 13.14
	numbered1 a1, b1 = a1, c1 = b1;
	f1(a1); // 10
	f1(b1); // 10
	f1(c1); // 10

	// Ex 13.15
	numbered2 a2, b2 = a2, c2 = b2;
	f2(a2); // 13
	f2(b2); // 14
	f2(c2); // 15

	// Ex 13.16
	numbered3 a3, b3 = a3, c3 = b3;
	f3(a3); // 10
	f3(b3); // 11
	f3(c3); // 12

	return 0;
}
