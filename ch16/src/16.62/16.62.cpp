#include <iostream>
#include "16.62.h"

std::istream& operator>>(std::istream& is, Sales_data& item) {
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	is >> bookNo >> units_sold >> price;
	item.bookNo = bookNo;
	item.units_sold = units_sold;
	item.revenue = units_sold * price;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.getUnitsSold() << " "
		<< item.getRevenue() << " " << item.avg_price();
	return os;
}

Sales_data& Sales_data::operator=(const std::string& isbn)
{
	*this = Sales_data(isbn);
	return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

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

bool operator==(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.bookNo == rhs.bookNo &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
	return !(lhs == rhs);
}