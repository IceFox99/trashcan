#include "15.26.h"

Quote::Quote(const Quote& q) : // Exercise 15.26
	bookNo(q.bookNo), price(q.price)
{
	std::cout << "Quote copy constructor called!" << std::endl;
}
Quote::Quote(Quote&& q) noexcept : // Exercise 15.26
	bookNo(std::move(q.bookNo)), price(std::move(q.price))
{
	std::cout << "Quote move constructor called!" << std::endl;
}
Quote& Quote::operator=(const Quote& rhs)  // Exercise 15.26
{
	if (this != &rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
	}
	std::cout << "Quote copy assignment called!" << std::endl;
	return *this;
}
Quote& Quote::operator=(Quote&& rhs) noexcept // Exercise 15.26
{
	if (this != &rhs) {
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
	}
	std::cout << "Quote move assignment called!" << std::endl;
	return *this;
}

Bulk_quote::Bulk_quote(const Bulk_quote& bq) :
	Disc_quote(bq)
{
	std::cout << "Bulk_quote copy constructor called!" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote&& bq) noexcept :
	Disc_quote(std::move(bq))
{
	std::cout << "Bulk_quote move constructor called!" << std::endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs)
{
	Disc_quote::operator=(rhs);
	std::cout << "Bulk_quote copy assignment called!" << std::endl;
	return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs) noexcept
{
	Disc_quote::operator=(std::move(rhs));
	std::cout << "Bulk_quote move assignment called!" << std::endl;
	return *this;
}
