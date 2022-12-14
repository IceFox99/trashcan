#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	std::string tempBookNo;
	unsigned int totalUnitsSold = 0;
	double totalPrice = 0;
	Sales_data tempSale;
	std::cout << "Please input first sale: ";
	if (std::cin >> tempSale.bookNo >> tempSale.unitsSold >> tempSale.sellingPrice) {
		tempBookNo = tempSale.bookNo;
		totalUnitsSold += tempSale.unitsSold;
		totalPrice += tempSale.sellingPrice * tempSale.unitsSold;
		std::cout << "Please input next sale: ";
		while (std::cin >> tempSale.bookNo >> tempSale.unitsSold >> tempSale.sellingPrice) {
			if (tempSale.bookNo == tempBookNo) {
				totalUnitsSold += tempSale.unitsSold;
				totalPrice += tempSale.sellingPrice * tempSale.unitsSold;
				std::cout << "Please input next sale: ";
			}
			else {
				std::cout << "The sum is " << tempBookNo << " " << totalUnitsSold << " "
					<< totalPrice << " " << totalPrice / totalUnitsSold << "." << std::endl;
				tempBookNo = tempSale.bookNo;
				totalUnitsSold = tempSale.unitsSold;
				totalPrice = tempSale.sellingPrice * tempSale.unitsSold;
				std::cout << "Please input next sale: ";
			}
		}
		std::cout << "The sum is " << tempBookNo << " " << totalUnitsSold << " "
			<< totalPrice << " " << totalPrice / totalUnitsSold << "." << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}