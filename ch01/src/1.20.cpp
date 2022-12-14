#include <iostream>
#include "../include/Sales_item.h"

int main()
{
	Sales_item item;
	std::cout << "Please input the sales item:" << std::endl;
	while (std::cin >> item) {
		std::cout << "The ISBN, number, sales and average sales are " << item << std::endl;
	}
	return 0;
}