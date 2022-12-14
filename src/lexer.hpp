#ifndef LEXER_H
#define LEXER_H

#include <regex>
#include <istream>
#include <vector>
#include <memory>

#include "token.hpp"
#include "exception.hpp"

class Lexer {
public:
    Lexer(std::istream& inputStream);
    TokenPtr read(); 
    TokenPtr peek(int i);
    ~Lexer();
private:
    bool fillVector(int i);
    void readLine();
    void addToken(const std::smatch& m);
    std::string toStringLiteral(std::string s);

    std::istream& is;
    static const std::regex allRegex;
    TokenPtrVec tokenVec;
    bool hasMore;
    int lineNumber;
};

#endif
