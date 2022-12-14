#include "Sales_data.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.getUnitsSold() << " " << item.getRevenue() << " " << item.avg_price();
	return os;
}
