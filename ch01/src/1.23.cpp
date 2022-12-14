#include <iostream>
#include "../include/Sales_item.h"

int main()
{
	Sales_item item1, item2;
	int num = 1;
	std::cout << "Please input the first item: ";
	if (std::cin >> item1) {
		std::cout << "Please input the next item: ";
		while (std::cin >> item2) {
			if (item1.isbn() == item2.isbn()) {
				++num;
				std::cout << "Please input the next item: ";
			}
			else {
				std::cout << item1.isbn() << " has " << num << " records." << std::endl;
				item1 = item2;
				num = 1;
				std::cout << "Please input the next item: ";
			}
		}
		std::cout << item1.isbn() << " has " << num << " records." << std::endl;
	}
	else {
		std::cout << "There is no record!" << std::endl;
	}
	return 0;
}