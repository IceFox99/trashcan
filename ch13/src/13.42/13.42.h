#pragma once
#include "../13.39/13.39.h"
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
	TextQuery(std::ifstream& infile);
	QueryResult query(const std::string& s) const;
private:
	std::shared_ptr<StrVec> strVec;
	std::map<std::string, std::shared_ptr<std::set<std::size_t>>> lineNum;
};

class QueryResult {
public:
	QueryResult(const std::string& s, std::shared_ptr<StrVec> strVec, std::shared_ptr<std::set<std::size_t>> lines) :
		word(s), strVec(strVec), lines(lines) {}
	void print();
private:
	std::string word;
	std::shared_ptr<StrVec> strVec;
	std::shared_ptr<std::set<std::size_t>> lines;
};

void FormatString(std::string& str);
void runQueries(std::ifstream& infile);