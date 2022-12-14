#include <iostream>
#include "../include/Sales_item.h"

int main()
{
	Sales_item item, sum;
	std::cout << "Please input the first item: ";
	std::cin >> item;
	sum = item;
	std::cout << "Please input the next item: ";
	while (std::cin >> item) {
		sum += item;
		std::cout << "Please input the next item: ";
	}
	std::cout << "The sum of these items is " << sum << std::endl;
	return 0;
}