#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <memory>
#include <vector>

class Token;

#define TokenPtr std::shared_ptr<Token>
#define TokenPtrVec std::vector<TokenPtr>
#define makeIdToken(line, id) std::make_shared<IdToken>(line, id)
#define makeNumToken(line, n) std::make_shared<NumToken>(line, n)
#define makeStrToken(line, str) std::make_shared<StrToken>(line, str)

class IdToken;

class Token {
public:
    Token();
    Token(int line);
    virtual bool isIdentifier() const;
    virtual bool isNumber() const;
    virtual bool isString() const;
    int getLineNumber() const;
    virtual std::string getText() const = 0;
    //virtual int getNumber() const;
    bool isEOF() const;
    virtual ~Token();

    static const std::string SEOL;
    static const IdToken SEOF;
private:
    int lineNumber;
};

class NumToken : public Token {
public:
    NumToken(int line, int n);
    bool isNumber() const override;
    std::string getText() const override;
    int getNumber() const;
private:
    int num;
};

class IdToken : public Token {
public:
    IdToken(int line, const std::string& id);
    bool isIdentifier() const override;
    std::string getText() const override;
    void setText(const std::string& str);
private:
    std::string text;
};

class StrToken : public Token {
public:
    StrToken(int line, const std::string& str);
    bool isString() const override;
    std::string getText() const override;
private:
    std::string literal;
};

#endif
