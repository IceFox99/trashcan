﻿#pragma once
#include <set>
#include <utility>
#include <string>
#include <iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& bookNo, double price) :
		bookNo(bookNo), price(price) {}
	Quote(const Quote& q); // Exercise 15.26
	Quote(Quote&& q) noexcept; // Exercise 15.26
	Quote& operator=(const Quote& rhs); // Exercise 15.26
	Quote& operator=(Quote&& rhs) noexcept; // Exercise 15.26

	virtual Quote* clone() const& { return new Quote(*this); } // Exercise 15.30
	virtual Quote* clone()&& { return new Quote(std::move(*this)); } // Exercise 15.30

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const { std::cout << "bookNo: " << bookNo << "\nprice: " << price; } // Exercise 15.11
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& bookNo, double price, std::size_t quantity, double discount) :
		Quote(bookNo, price), quantity(quantity), discount(discount) {}
	virtual double net_price(std::size_t n) const override = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	using Disc_quote::Disc_quote; // Exercise 15.27
	/*Bulk_quote(const std::string& bookNo, double price, std::size_t quantity, double discount) :
		Disc_quote(bookNo, price, quantity, discount) {}*/
	Bulk_quote(const Bulk_quote& bq); // Exercise 15.26
	Bulk_quote(Bulk_quote&& bq) noexcept; // Exercise 15.26
	Bulk_quote& operator=(const Bulk_quote& rhs); // Exercise 15.26
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept; // Exercise 15.26

	virtual Bulk_quote* clone() const& { return new Bulk_quote(*this); } // Exercise 15.30
	virtual Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); } // Exercise 15.30

	double net_price(std::size_t n) const override { return n >= quantity ? n * (1 - discount) * price : n * price; }
};

inline double print_total(std::ostream& os, const Quote& item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

class Basket { // Exercise 15.30
public:
	void add_item(const Quote& q) { items.insert(std::shared_ptr<Quote>(q.clone())); }
	void add_item(Quote&& q) { items.insert(std::shared_ptr<Quote>(std::move(q).clone())); }
	double total_receipt(std::ostream& os) const;
private:
	static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};
