#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned int unitsSold = 0;
	double sellingPrice = 0.0;
};

int main()
{
	Sales_data fSale, nSale;
	unsigned int totalUnitsSold = 0;
	double totalPrice = 0.0;
	std::cout << "Please input first sale: ";
	std::cin >> fSale.bookNo >> fSale.unitsSold >> fSale.sellingPrice;
	totalUnitsSold += fSale.unitsSold;
	totalPrice += fSale.unitsSold * fSale.sellingPrice;

	std::cout << "Please input next sale: ";
	while (std::cin >> nSale.bookNo >> nSale.unitsSold >> nSale.sellingPrice) {
		if (nSale.bookNo == fSale.bookNo) {
			totalUnitsSold += nSale.unitsSold;
			totalPrice += nSale.unitsSold * nSale.sellingPrice;
			std::cout << "Please input next sale: ";
		}
		else {
			std::cout << "Their ISBN is different! Program fails!" << std::endl;
			return -1;
		}
	}

	std::cout << "Their sum is " << fSale.bookNo << " " << totalUnitsSold << " "
		<< totalPrice << " " << totalPrice / totalUnitsSold << "." << std::endl;
	return 0;
}