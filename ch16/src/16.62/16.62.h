#pragma once
#include <string>
#include <functional>

class Sales_data {
	friend std::hash<Sales_data>;
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend Sales_data operator-(const Sales_data&, const Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const std::string& s) :
		bookNo(s) {}
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(n * p) {}
	Sales_data(std::istream& is) { is >> *this; }
	std::string isbn() const { return bookNo; }
	unsigned getUnitsSold() const { return units_sold; }
	double getRevenue() const { return revenue; }
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }
	Sales_data& operator+=(const Sales_data& rhs);
	Sales_data& operator-=(const Sales_data& rhs);
	Sales_data& operator=(const std::string& rhs);
	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return avg_price(); }
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&);
bool operator==(const Sales_data&, const Sales_data&);

namespace std
{
	template <>
	struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const
		{
			return hash<string>()(s.bookNo) ^
				hash<unsigned>()(s.units_sold) ^
				hash<double>()(s.revenue);
		}
	};
}