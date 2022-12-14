#include "../6.54.h"

std::vector<decltype(func)*> fvec;
int funcAdd(int i1, int i2) {
	return i1 + i2;
}

int funcSubtract(int i1, int i2) {
	return i1 - i2;
}

int funcMultiply(int i1, int i2) {
	return i1 * i2;
}

int funcDivide(int i1, int i2) {
	return i1 / i2;
}