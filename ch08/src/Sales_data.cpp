#include "Sales_data.h"
#include <iostream>
using std::string; using std::istream; using std::ostream;

Sales_data::Sales_data() = default;

Sales_data::Sales_data(const string & s) :
	bookNo(s) {}

Sales_data::Sales_data(const string & s, unsigned n, double p) :
	bookNo(s), units_sold(n), revenue(n * p) {}

Sales_data::Sales_data(istream & is) {
	read(is, *this);
}

string Sales_data::isbn() const {
	return bookNo;
}

unsigned Sales_data::getUnitsSold() const {
	return units_sold;
}

double Sales_data::getRevenue() const {
	return revenue;
}

Sales_data& Sales_data::combine(const Sales_data & rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const {
	return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data & lhs, const Sales_data & rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream& read(istream & is, Sales_data & item) {
	string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	is >> bookNo >> units_sold >> price;
	item.bookNo = bookNo;
	item.units_sold = units_sold;
	item.revenue = units_sold * price;
	return is;
}

ostream& print(ostream & os, const Sales_data & item) {
	os << item.isbn() << " " << item.getUnitsSold() << " "
		<< item.getRevenue() << " " << item.avg_price();
	return os;
}