#include "if_stmnt.hpp"
#include "code.hpp"
#include "../exception.hpp"
#include "astleaf.hpp"

//IfStmnt::IfStmnt(ASTreePtrVec c) :
//    ASTList(c) {}

ASTreePtr IfStmnt::condition() const
{
    return child(0);
}

ASTreePtr IfStmnt::thenBlock() const
{
    return child(1);
}

ASTreePtr IfStmnt::elseBlock() const
{
    return numChildren() > 2 ? child(2) : nullptr;
}

std::string IfStmnt::toString() const
{
    return "(if " + condition()->toString() + " " + thenBlock()->toString()
           + ((numChildren() > 2) ? " else " + elseBlock()->toString() + ")" : ")");
}

int IfStmnt::getCode() const
{
    return IFSTMNT;
}
