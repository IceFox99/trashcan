#include "Sales_data.h"
#include <iostream>

std::istream& operator>>(std::istream& is, Sales_data& item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}