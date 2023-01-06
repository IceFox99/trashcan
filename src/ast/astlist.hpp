#ifndef ASTLIST_H
#define ASTLIST_H

#include "astree.hpp"

#define ASTListPtr std::shared_ptr<ASTList>
//#define makeASTList(i) std::make_shared<ASTList>(i)

class ASTList : public ASTree {
friend class Interpreter;
public:
    ASTList();
    //ASTList(ASTreePtr t);
    ASTList(ASTreePtrVec vec);
    void add(ASTreePtr t);
    void pop();
    ASTreePtr child(int i) const override;
    int numChildren() const override;
    std::string location() const override;
    virtual std::string toString() const override;
protected:
    ASTreePtrVec children; 
};

#endif
