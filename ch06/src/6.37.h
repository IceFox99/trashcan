#pragma once
#include <string>
using std::string;

typedef string arrStrTen[10];
arrStrTen& func1();

auto func2()->string(&)[10];

string str[10];
decltype(str)& func3();