#include <iostream>
#include <sstream>
#include <string>
#include "8.01/8.01.h"

int main()
{
	std::istringstream strm("test1 test2 test3");
	readStream(strm);
	return 0;
}