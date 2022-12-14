#include "Sales_data.h"

explicit Sales_data::operator std::string() const
{
	return bookNo;
}

explicit Sales_data::operator double() const
{
	return avg_price();
}