#include "assign_stmnt.hpp"
#include "code.hpp"

//AssignStmnt::AssignStmnt() = default;

//AssignStmnt::AssignStmnt(ASTreePtrVec c) :
//    ASTList(c) {}

ASTreePtr AssignStmnt::var() const
{
    return child(0);
}

ASTreePtr AssignStmnt::value() const
{
    return child(1);
}

std::string AssignStmnt::toString() const
{
    return "(" + var()->toString() + " = " + value()->toString() + ")";
}

int AssignStmnt::getCode() const
{
    return ASSIGN;
}
