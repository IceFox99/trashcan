#include <iostream>
#include "8.01/8.01.h"

int main()
{
	std::istream& is = readStream(std::cin);
	std::cout << is.rdstate() << std::endl;
	return 0;
}