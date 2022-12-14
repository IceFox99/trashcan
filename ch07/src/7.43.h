#pragma once
class NoDefault {
private:
	int i;
public:
	NoDefault(int i) : i(i) {}
};

class C {
private:
	NoDefault nd;
public:
	C(int i = 0) : nd(i) {}
};
