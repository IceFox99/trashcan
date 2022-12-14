#pragma once
#include <memory>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>

class QueryResult;

class StrBlob {
	friend class TextQuery;
	friend class QueryResult;
	friend std::ostream& print(std::ostream& os, const QueryResult& qr);
public:
	std::vector<std::string>::size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	StrBlob() :
		data(std::make_shared<std::vector<std::string>>()) {}

	StrBlob(std::initializer_list<std::string> li) :
		data(std::make_shared<std::vector<std::string>>(li)) {}

	std::string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back() {
		check(0, "back on empty StrBlob");
		return data->back();
	}

	void push_back(const std::string& str) { data->push_back(str); }

	void pop_back() {
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(std::vector<std::string>::size_type i, const std::string& msg) const {
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};

class TextQuery {
	friend class QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream& infile);
	QueryResult query(const std::string& s) const;
private:
	StrBlob strVec;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> lineNum;
};

class QueryResult {
	friend std::ostream& print(std::ostream& os, const QueryResult& qr);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string& s, StrBlob strVec, std::shared_ptr<std::set<line_no>> lines) :
		word(s), strVec(strVec), lines(lines) {}
private:
	std::string word;
	StrBlob strVec;
	std::shared_ptr<std::set<line_no>> lines;
};

void FormatString(std::string& str);
std::ostream& print(std::ostream& os, const QueryResult& qr);
void runQueries(std::ifstream& infile);