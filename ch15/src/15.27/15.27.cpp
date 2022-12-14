#include "15.27.h"

Quote::Quote(const Quote& q) : // Exercise 15.26
	bookNo(q.bookNo), price(q.price) {}
Quote::Quote(Quote&& q) noexcept : // Exercise 15.26
	bookNo(std::move(q.bookNo)), price(std::move(q.price)) {}
Quote& Quote::operator=(const Quote& rhs)  // Exercise 15.26
{
	if (this != &rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
	}
	return *this;
}
Quote& Quote::operator=(Quote&& rhs) noexcept // Exercise 15.26
{
	if (this != &rhs) {
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
	}
	return *this;
}

Bulk_quote::Bulk_quote(const Bulk_quote& bq) :
	Disc_quote(bq) {}

Bulk_quote::Bulk_quote(Bulk_quote&& bq) noexcept :
	Disc_quote(std::move(bq)) {}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs)
{
	Disc_quote::operator=(rhs);
	return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs) noexcept
{
	Disc_quote::operator=(std::move(rhs));
	return *this;
}
