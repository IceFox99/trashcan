#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "token.hpp"
#include "lexer.hpp"
#include "ast/astree.hpp"
#include "ast/astlist.hpp"
#include "ast/astleaf.hpp"

class Parser {
public:
    Parser();
    ASTreePtr parse(Lexer& l);
    ASTreePtr expectPrimary(Lexer& l);
    ASTreePtr expectExpr(Lexer& l);
    ASTreePtr expectBlock(Lexer& l);
    ASTreePtr expectIf(Lexer& l);
    ASTreePtr expectWhile(Lexer& l);

    class Precedence {
    public:
        Precedence(int v, bool a) {
            value = v;
            leftAssoc = a;
        }
        
        int value;
        bool leftAssoc;
    };

    static const std::unordered_set<std::string> reserved;
    static const std::unordered_map<std::string, Precedence> operators;
};

#endif
