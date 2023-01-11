#include "while_stmnt.hpp"
#include "code.hpp"

//WhileStmnt::WhileStmnt(ASTreePtrVec c) :
//    ASTList(c) {}

ASTreePtr WhileStmnt::condition() const
{
    return child(0);
}

ASTreePtr WhileStmnt::body() const
{
    return child(1);
}

std::string WhileStmnt::toString() const
{
    return "(while " + condition()->toString() + " " 
           + (label.empty() ? "" : ": " + label + " ")
           + body()->toString() + ")";
}

int WhileStmnt::getCode() const
{
    return WHILESTMNT;
}

void WhileStmnt::setLabel(const std::string& str)
{
    label = str;
}

std::string WhileStmnt::getLabel() const
{
    return label;
}
