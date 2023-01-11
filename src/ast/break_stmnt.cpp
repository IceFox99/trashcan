#include "break_stmnt.hpp"
#include "code.hpp"

BreakStmnt::BreakStmnt(int line, const std::string& label) :
    ASTLeaf(makeIdToken(line, "break")), label(label) {}

int BreakStmnt::getCode() const
{
    return BREAK;
}

void BreakStmnt::setLabel(const std::string& str)
{
    label = str;
}

std::string BreakStmnt::getLabel() const
{
    return label;
}

std::string BreakStmnt::toString() const
{
    return label.empty() ? "break" : "(break " + label + ")";
}
