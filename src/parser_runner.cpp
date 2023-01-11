#include <iostream>
#include <fstream>
#include "lexer.hpp"
#include "parser.hpp"

int main()
{
    std::ifstream input("../examples/test.sand");

    std::string temp;
    while (std::getline(input, temp)) {
        std::cout << temp << std::endl;
    }
    std::cout << std::endl;
    input.clear();
    input.seekg(0);

    Lexer l(input);
    Parser p;
    while (!l.peek(0)->isEOF()) {
        ASTreePtr ast = p.parse(l);
        std::cout << "=> " << ast->toString() << " with type " << ast->getCode() << std::endl;
    }

    return 0;
}
