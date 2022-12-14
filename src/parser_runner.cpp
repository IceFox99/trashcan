#include <iostream>
#include <fstream>
#include "lexer.hpp"
#include "parser.hpp"

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
    Parser p;
    while (!l.peek(0)->isEOF()) {
        ASTreePtr ast = p.parse(l);
        std::cout << "=> " << ast->toString() << " with type " << ast->getCode() << std::endl;
    }
    //std::cout << "=> " << p.parse(l)->toString() << std::endl;
    //std::cout << "=> " << p.parse(l)->toString() << std::endl;
    
    //ASTListPtr alp = makeASTListPtr();
    //ASTLeafPtr leaf = makeASTLeafPtr(l.read());
    //std::cout << alp->numChildren() << std::endl;
    //std::cout << "before adding" << std::endl;
    //alp->add(leaf);
    //std::cout << "after adding" << std::endl;
    ////ast = makeASTListPtr();
    ////alp->add(makeASTLeafPtr(l.read()));
    //std::cout << alp->child(0)->toString() << std::endl;
    return 0;
}
