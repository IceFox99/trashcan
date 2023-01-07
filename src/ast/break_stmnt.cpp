#include "break_stmnt.hpp"
#include "code.hpp"

BreakStmnt::BreakStmnt(int line) :
    ASTLeaf(makeIdToken(line, "break")) {}

int BreakStmnt::getCode() const
{
    return BREAK;
}
