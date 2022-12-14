#include "Sales_data.h"

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum;
	sum.units_sold = lhs.units_sold + rhs.units_sold;
	sum.revenue = lhs.revenue + rhs.revenue;
	return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& item)
{
	*this = *this + item;
	return *this;
}