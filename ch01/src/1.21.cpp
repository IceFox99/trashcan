#include <iostream>
#include "../include/Sales_item.h"

int main()
{
	Sales_item item1, item2;
	std::cout << "Please input the first item: ";
	std::cin >> item1;
	std::cout << "Please input the second item: ";
	std::cin >> item2;
	std::cout << "The sum of these two items is " << item1 + item2 << std::endl;
	return 0;
}