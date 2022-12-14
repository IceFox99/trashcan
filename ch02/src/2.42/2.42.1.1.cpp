#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data item;

	std::cout << "Please input the sale: ";
	while (std::cin >> item.bookNo >> item.unitsSold >> item.sellingPrice) {
		std::cout << "The sale is " << item.bookNo << " " << item.unitsSold << " " << item.sellingPrice * item.unitsSold
			<< " " << item.sellingPrice << ".\n" << std::endl;
		std::cout << "Please input the sale: ";
	}

	return 0;
}