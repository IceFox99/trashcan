#include "lexer.hpp"

// const std::regex Lexer::spRegex("\\s*");
// const std::regex Lexer::numRegex("[0-9]+");
// const std::regex Lexer::idRegex("[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||[:punct:]");
// const std::regex Lexer::strRegex("\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\"");
// const std::regex Lexer::commentRegex("//.*");
const std::regex Lexer::allRegex("\\s*((//.*)|(-?[0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||[[:punct:]])");

Lexer::Lexer(std::istream& inputStream) :
    is(inputStream), hasMore(true), lineNumber(0) {}

Lexer::~Lexer() = default;

TokenPtr Lexer::read()
{
    if (fillVector(0)) {
        auto temp = *tokenVec.begin();
        tokenVec.erase(tokenVec.begin());
        return temp;
    }
    else 
        return std::make_shared<IdToken>(Token::SEOF);
}

TokenPtr Lexer::peek(int i)
{
    if (fillVector(i))
        return tokenVec.at(i);
    else
        return std::make_shared<IdToken>(Token::SEOF);
}

bool Lexer::fillVector(int i) 
{
    while (i >= (int)tokenVec.size()) {
        if (hasMore)
            readLine();
        else
            return false;
    }
    return true;
}

void Lexer::readLine()
{
    std::string line;
    if (!std::getline(is, line)) {
        hasMore = false;
        return;
    }
    ++lineNumber;

    int pos = 0;
    int endPos = line.length();
    while (pos < endPos) {
        std::smatch m;
        std::string current = line.substr(pos);
        if (std::regex_search(current, m, allRegex)) {
            addToken(m);
            pos += m.length();
        }
        else
            throw SandException("bad token at line " + std::to_string(lineNumber));
    }
    //tokenVec.push_back(makeIdTokenPtr(lineNumber, Token::SEOL)); The EOL should be omiteed
}

void Lexer::addToken(const std::smatch& m)
{
    std::string str = m[1].str(); // string without spaces
    if (!str.empty()) { // if not only spaces
        if (m[2].str().empty()) { // if not a comment
            TokenPtr token;
            if (!m[3].str().empty())
                token = makeNumToken(lineNumber, std::stoi(str));
            else if (!m[4].str().empty()) 
                token = makeStrToken(lineNumber, toStringLiteral(str));
            else 
                token = makeIdToken(lineNumber, str);
            tokenVec.push_back(token);
        }
    }
}

std::string Lexer::toStringLiteral(std::string s) {
    std::string str("");
    int len = s.length() - 1;
    for (int i = 1; i < len; ++i) { // Get rid of two double quotation marks.
        char c = s.at(i);
        if (c == '\\' && i + 1 < len) { // if it's a backslash
            int c2 = s.at(i + 1);
            if (c2 == '"' || c2 == '\\') // if it's followed by a quotation mark or backslash
                c = s.at(++i);
            else if (c2 == 'n') {
                ++i;
                c = '\n';
            }
        }
        str += c;
    }
    return str;
}
