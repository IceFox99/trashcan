#include "15.35.h"
#include <iostream>

Query::Query(const std::string& s) :
	q(new WordQuery(s)) { std::cout << "Query::Query(const std::string& s) where s=" << s << std::endl; }
Query::Query(std::shared_ptr<Query_base> query) :
	q(query) { std::cout << "Query(std::shared_ptr<Query_base> query)" << std::endl; }
std::string Query::rep() const
{
	std::cout << "Query::rep()" << std::endl;
	return q->rep();
}

WordQuery::WordQuery(const std::string& s) :
	query_word(s) { std::cout << "WordQuery::WordQuery(const std::string& s) where s=" << s << std::endl; }
std::string WordQuery::rep() const
{
	std::cout << "WordQuery::rep() where word is " << query_word << std::endl;
	return query_word;
}

NotQuery::NotQuery(const Query& q) :
	query(q) { std::cout << "NotQuery::NotQuery(const Query& q)" << std::endl; }
std::string NotQuery::rep() const
{
	std::cout << "NotQuery::rep()" << std::endl;
	return "~(" + query.rep() + ")";
}

BinaryQuery::BinaryQuery(const Query& l, const Query& r, std::string s) :
	lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery::BinaryQuery(const Query & l, const Query & r, std::string s) where s=" << s << std::endl; }
std::string BinaryQuery::rep() const
{
	std::cout << "BinaryQuery::rep() where operator is " << opSym << std::endl;
	return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}

AndQuery::AndQuery(const Query& l, const Query& r) :
	BinaryQuery(l, r, "&") { std::cout << "AndQuery::AndQuery(const Query& l, const Query& r)" << std::endl; }

OrQuery::OrQuery(const Query& l, const Query& r) :
	BinaryQuery(l, r, "|") { std::cout << "OrQuery::OrQuery(const Query& l, const Query& r)" << std::endl; }

int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	// QC for Query constructor, WC for WordQuery constructor, and so on.
	// Exercise 15.34.a
	// WC(wind), QC, WC(bird), QC, WC(fiery), QC
	// BC, AC, QC, BC, OC, QC

	std::cout << "************************************" << std::endl;

	std::cout << q;
	// QR for Query rep, WR for WordQuery rep, and so on.
	// Exercise 15.34.b
	// QR, BR, QR, WR(wind), QR, BR, QR, WR(bird), QR, WR(fiery)
	return 0;
}