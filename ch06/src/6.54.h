#pragma once
#include <vector>

int func(int, int);
int funcAdd(int, int);
int funcSubtract(int, int);
int funcMultiply(int, int);
int funcDivide(int, int);
extern std::vector<decltype(func)*> fvec;