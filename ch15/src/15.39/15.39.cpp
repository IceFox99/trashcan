#include "../15.35.h"
#include <iterator>
#include <algorithm>

Query::Query(const std::string& s) :
	q(new WordQuery(s)) {}
Query::Query(std::shared_ptr<Query_base> query) :
	q(query) {}
std::string Query::rep() const { return q->rep(); }

WordQuery::WordQuery(const std::string& s) :
	query_word(s) {}
std::string WordQuery::rep() const { return query_word; }

NotQuery::NotQuery(const Query& q) :
	query(q) {}
std::string NotQuery::rep() const {	return "~(" + query.rep() + ")"; }

BinaryQuery::BinaryQuery(const Query& l, const Query& r, std::string s) :
	lhs(l), rhs(r), opSym(s) {}
std::string BinaryQuery::rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

AndQuery::AndQuery(const Query& l, const Query& r) :
	BinaryQuery(l, r, "&") {}

OrQuery::OrQuery(const Query& l, const Query& r) :
	BinaryQuery(l, r, "|") {}

QueryResult OrQuery::eval(const TextQuery& tq) const
{
	auto right = rhs.eval(tq), left = lhs.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), *left.get_file(), ret_lines);
}

QueryResult AndQuery::eval(const TextQuery& tq) const
{
	auto left = lhs.eval(tq), right = rhs.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), *left.get_file(), ret_lines);
}

QueryResult NotQuery::eval(const TextQuery& tq) const
{
	auto result = query.eval(tq);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 1; n != sz + 1; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), *result.get_file(), ret_lines);
}