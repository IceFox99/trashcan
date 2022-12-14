#include <iostream>
#include <fstream>
#include "lexer.hpp"
#include "parser.hpp"
#include "interpreter.hpp"

int main()
{
    std::ifstream input("../src/test.sand");

    //std::string temp;
    //while (std::getline(input, temp)) 
    //    std::cout << temp << std::endl;
    //std::cout << std::endl;
    //input.clear();
    //input.seekg(0);

    Lexer l(input);
    Parser p;
    Interpreter it;
    while (!l.peek(0)->isEOF()) {
        ASTreePtr ast = p.parse(l);
        it.inter(ast);
    }
    return 0;
}
