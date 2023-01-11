#include <iostream>
#include <fstream>
#include "lexer.hpp"
#include "parser.hpp"
#include "interpreter.hpp"

int main()
{
    std::ifstream input("../examples/test.sand");

    Lexer l(input);
    Parser p;
    Interpreter it;
    while (!l.peek(0)->isEOF()) {
        ASTreePtr ast = p.parse(l);
        it.inter(ast);
    }
    return 0;
}
