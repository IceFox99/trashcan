#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data oldSale, newSale;
	unsigned int saleNo = 0;
	std::cout << "Please input first sale: ";
	std::cin >> oldSale.bookNo >> oldSale.unitsSold >> oldSale.sellingPrice;
	++saleNo;

	std::cout << "Please input next sale: ";
	while (std::cin >> newSale.bookNo >> newSale.unitsSold >> newSale.sellingPrice) {
		if (newSale.bookNo == oldSale.bookNo) {
			++saleNo;
			std::cout << "Please input next sale: ";
		}
		else {
			std::cout << oldSale.bookNo << " has " << saleNo << " records." << std::endl;
			saleNo = 1;
			oldSale.bookNo = newSale.bookNo;
			std::cout << "Please input next sale: ";
		}
	}

	std::cout << oldSale.bookNo << " has " << saleNo << " records." << std::endl;
	return 0;
}