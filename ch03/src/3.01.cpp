#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::cerr; using std::string;

struct Sales_data {
	string bookNo;
	unsigned int unitsSold = 0;
	double sellingPrice = 0.0;
};

int main()
{
	string tempBookNo;
	unsigned int totalUnitsSold = 0;
	double totalPrice = 0;
	Sales_data tempSale;
	cout << "Please input first sale: ";
	if (cin >> tempSale.bookNo >> tempSale.unitsSold >> tempSale.sellingPrice) {
		tempBookNo = tempSale.bookNo;
		totalUnitsSold += tempSale.unitsSold;
		totalPrice += tempSale.sellingPrice * tempSale.unitsSold;
		cout << "Please input next sale: ";
		while (cin >> tempSale.bookNo >> tempSale.unitsSold >> tempSale.sellingPrice) {
			if (tempSale.bookNo == tempBookNo) {
				totalUnitsSold += tempSale.unitsSold;
				totalPrice += tempSale.sellingPrice * tempSale.unitsSold;
				cout << "Please input next sale: ";
			}
			else {
				cout << "The sum is " << tempBookNo << " " << totalUnitsSold << " "
					<< totalPrice << " " << totalPrice / totalUnitsSold << "." << endl;
				tempBookNo = tempSale.bookNo;
				totalUnitsSold = tempSale.unitsSold;
				totalPrice = tempSale.sellingPrice * tempSale.unitsSold;
				cout << "Please input next sale: ";
			}
		}
		cout << "The sum is " << tempBookNo << " " << totalUnitsSold << " "
			<< totalPrice << " " << totalPrice / totalUnitsSold << "." << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}