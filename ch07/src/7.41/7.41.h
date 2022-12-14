#pragma once
#include <string>

class Sales_data_delegating {
	friend Sales_data_delegating add(const Sales_data_delegating&, const Sales_data_delegating&);
	friend std::istream& read(std::istream&, Sales_data_delegating&);
	friend std::ostream& print(std::ostream&, const Sales_data_delegating&);
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data_delegating();
	Sales_data_delegating(const std::string& s);
	Sales_data_delegating(const std::string& s, unsigned n, double p);
	Sales_data_delegating(std::istream& is);
	std::string isbn() const;
	unsigned getUnitsSold() const;
	double getRevenue() const;
	Sales_data_delegating& combine(const Sales_data_delegating& rhs);
	double avg_price() const;
};

Sales_data_delegating add(const Sales_data_delegating&, const Sales_data_delegating&);
std::istream& read(std::istream&, Sales_data_delegating&);
std::ostream& print(std::ostream&, const Sales_data_delegating&);