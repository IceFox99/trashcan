#include "12.30.h"
#include <sstream>
#include <iostream>

// Format the string, Delete the character which is not normal alphabetic character like colon or dot, and make them into lowercase.
void FormatString(std::string& str) {
	std::string::size_type pos = 0;
	while ((pos = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz0123456789", pos)) != std::string::npos) {
		if (isupper(str[pos]))
			str[pos] = tolower(str[pos]);
		else
			str.erase(pos, 1);
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << qr.word << " occurs " << qr.lines->size() << " times" << std::endl;
	for (const auto& s : *qr.lines)
		os << "\t(line " << s << ") " << qr.strVec->at(s - 1) << std::endl;
	os << std::endl;
	return os;
}

void runQueries(std::ifstream& infile) {
	TextQuery tq(infile);
	while (true) {
		std::cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s));
	}
}

TextQuery::TextQuery(std::ifstream& infile) :
	strVec(std::make_shared<std::vector<std::string>>()) {
	std::string tempLine, tempWord;
	int line = 1;
	while (std::getline(infile, tempLine)) {
		strVec->push_back(tempLine);
		std::istringstream input(tempLine);
		while (input >> tempWord) {
			FormatString(tempWord);
			if (!tempWord.empty()) {
				if (!lineNum[tempWord])
					lineNum[tempWord] = std::make_shared<std::set<line_no>>();
				lineNum[tempWord]->insert(line);
			}
		}
		++line;
	}
}

QueryResult TextQuery::query(const std::string& s) const {
	auto it = lineNum.find(s);
	static std::shared_ptr<std::set<line_no>> emptySet = std::make_shared<std::set<line_no>>();
	return (it == lineNum.end()) ? QueryResult(s, strVec, emptySet) : QueryResult(s, strVec, it->second);
}
