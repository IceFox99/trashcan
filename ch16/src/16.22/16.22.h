#pragma once
#include "../16.21.h"
#include <memory>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>

class QueryResult;

class TextQuery {
	friend class QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream& infile);
	QueryResult query(const std::string& s) const;
private:
	std::shared_ptr<std::vector<std::string>> strVec;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> lineNum;
};

class QueryResult {
	friend std::ostream& print(std::ostream& os, const QueryResult& qr);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(const std::string& s, std::shared_ptr<std::vector<std::string>> strVec, std::shared_ptr<std::set<line_no>> lines) :
		word(s), strVec(strVec), lines(lines) {}
private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> strVec;
	std::shared_ptr<std::set<line_no>> lines;
};

void FormatString(std::string& str);
std::ostream& print(std::ostream& os, const QueryResult& qr);
void runQueries(std::ifstream& infile);