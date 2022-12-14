#include "Sales_data.h"

Sales_data& Sales_data::operator-=(const Sales_data& item)
{
	units_sold -= item.units_sold;
	revenue -= item.revenue;
	return *this;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data item = lhs;
	item -= rhs;
	return item;
}