#include "func_stmnt.hpp"
#include "code.hpp"

FuncStmnt::FuncStmnt(ASTreePtr p) :
    ASTList() 
{
    add(p);
}

std::string FuncStmnt::getFuncName() const
{
    return child(0)->toString();
}

std::string FuncStmnt::toString() const
{
    std::string str = getFuncName() + "(";
    for (int i = 1; i != numChildren(); ++i) {
        str += child(i)->toString();
        str += ", "; 
    }
    if (numChildren() > 1) {
        str.pop_back();
        str.pop_back();
    }
    str += ")";
    return str;
}

int FuncStmnt::getCode() const
{
    return FUNC;
}
