#pragma once
#include <string>

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data();
	Sales_data(const std::string& s);
	Sales_data(const std::string& s, unsigned n, double p);
	Sales_data(std::istream& is);
	std::string isbn() const;
	unsigned getUnitsSold() const;
	double getRevenue() const;
	Sales_data& combine(const Sales_data& rhs);
	double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);