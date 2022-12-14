#include <iostream>
#include <fstream>
#include "token.hpp"
#include "lexer.hpp"

int main()
{
    std::ifstream input("../src/test.sand");

    std::string temp;
    while (std::getline(input, temp)) {
        std::cout << temp << std::endl;
    }
    std::cout << std::endl;
    input.clear();
    input.seekg(0);

    Lexer l(input);
    for (TokenPtr t; !(t = l.read())->isEOF(); ) {
        if (t->isNumber())
            std::cout << "(line " << t->getLineNumber() << ") Number => " << std::static_pointer_cast<NumToken>(t)->getNumber() << std::endl;
        else if (t->isIdentifier()) 
            std::cout << "(line " << t->getLineNumber() << ") Identifier => " << t->getText() << std::endl;
        else if (t->isString())
            std::cout << "(line " << t->getLineNumber() << ") String => " << t->getText() << std::endl;
    }
    return 0;
}
