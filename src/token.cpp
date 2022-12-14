#include "token.hpp"
#include "exception.hpp"

const std::string Token::SEOL = "\\n";
const IdToken Token::SEOF(-1, "EOF");

Token::Token(int line)
{
    lineNumber = line;
}

int Token::getLineNumber() const
{
    return lineNumber;
}

bool Token::isIdentifier() const
{
    return false;
}

bool Token::isNumber() const
{
    return false;
}

bool Token::isString() const
{
    return false;
}

// std::string Token::getText() const
// {
//     throw SandException("Try to access abstract token class!");
// }
// 
//int Token::getNumber() const
//{
//    throw SandException("Not number token!");
//}

bool Token::isEOF() const
{
    return (lineNumber == Token::SEOF.getLineNumber());
}

Token::~Token() = default;

NumToken::NumToken(int line, int n) :
    Token(line) 
{
    num = n;
}

bool NumToken::isNumber() const
{
    return true;
}

std::string NumToken::getText() const
{
    return std::to_string(num);
}

int NumToken::getNumber() const
{
    return num;
}

IdToken::IdToken(int line, const std::string& id) :
    Token(line)
{
    text = id;
}

bool IdToken::isIdentifier() const
{
    return true;
}

std::string IdToken::getText() const
{
    return text;
}

StrToken::StrToken(int line, const std::string& str) :
    Token(line)
{
    literal = str;
}

bool StrToken::isString() const
{
    return true;
}

std::string StrToken::getText() const
{
    return literal;
}
