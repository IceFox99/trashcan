#include <iostream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned int unitsSold = 0;
	double sellingPrice = 0.0;
};

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