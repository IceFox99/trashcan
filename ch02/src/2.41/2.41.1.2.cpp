#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned int unitsSold = 0;
	double sellingPrice = 0.0;
};

int main()
{
	Sales_data sale1, sale2;

	// Read these two sales
	std::cout << "Please input the first sale: ";
	std::cin >> sale1.bookNo >> sale1.unitsSold >> sale1.sellingPrice;
	std::cout << "Please input the second sale: ";
	std::cin >> sale2.bookNo >> sale2.unitsSold >> sale2.sellingPrice;

	// Judge the bookNo
	if (sale1.bookNo == sale2.bookNo) {
		unsigned int totalUnitsSold = sale1.unitsSold + sale2.unitsSold;
		double totalPrice = sale1.sellingPrice * sale1.unitsSold + sale2.sellingPrice * sale2.unitsSold;
		std::cout << "The sum is " << sale1.bookNo << " " << totalUnitsSold << " "
			<< totalPrice << " " << totalPrice / totalUnitsSold << "." << std::endl;
		return 0;
	}
	else {
		std::cout << "Their ISBN are different! Program fails!";
		return -1;
	}
}