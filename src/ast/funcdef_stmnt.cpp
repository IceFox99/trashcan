#include "funcdef_stmnt.hpp"
#include "code.hpp"
#include "../exception.hpp"

FuncDefStmnt::FuncDefStmnt(ASTreePtr f) :
    ASTList() 
{
    add(f);
}

ASTreePtr FuncDefStmnt::parameters() const
{
    return child(0);
}

// Return a block_stmnt
ASTreePtr FuncDefStmnt::func() const
{
    return child(1);
}

//ASTreePtr FuncDefStmnt::ret() const
//{
//    if (numChildren() < 2)
//        throw SandException("No return value for the function at" + fsp->location());
//    return child(1);
//}

std::string FuncDefStmnt::toString() const
{
    return parameters()->toString() + " " + func()->toString();
}

int FuncDefStmnt::getCode() const
{
    return FUNCDEF;
}
