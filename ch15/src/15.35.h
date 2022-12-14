#pragma once
#include "TextQueryResult.h"

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery& tq) const = 0;
	virtual std::string rep() const = 0;
};

class Query {
	friend Query operator~(const Query& q);
	friend Query operator|(const Query& lhs, const Query& rhs);
	friend Query operator&(const Query& lhs, const Query& rhs);
public:
	Query(const std::string& s);
	QueryResult eval(const TextQuery& tq) const { return q->eval(tq); }
	std::string rep() const;
private:
	Query(std::shared_ptr<Query_base> query);
	std::shared_ptr<Query_base> q;
};
inline std::ostream& operator<<(std::ostream& os, const Query& q) { return os << q.rep(); }

class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const std::string& s);
	QueryResult eval(const TextQuery& tq) const override { return tq.query(query_word); }
	std::string rep() const override;
	std::string query_word;
};

class NotQuery : public Query_base {
	friend class Query;
	friend Query operator~(const Query& q);
	NotQuery(const Query& q);
	QueryResult eval(const TextQuery& tq) const override;
	std::string rep() const override;
	Query query;
};
inline Query operator~(const Query& q) { return std::shared_ptr<Query_base>(new NotQuery(q)); }

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s);
	std::string rep() const override;
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query& lhs, const Query& rhs);
	AndQuery(const Query& l, const Query& r);
	QueryResult eval(const TextQuery& tq) const override;
};
inline Query operator&(const Query& lhs, const Query& rhs) { return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs)); }

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query& lhs, const Query& rhs);
	OrQuery(const Query& l, const Query& r);
	QueryResult eval(const TextQuery& tq) const override;
};
inline Query operator|(const Query& lhs, const Query& rhs) { return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs)); }