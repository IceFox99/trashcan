#include "null_stmnt.hpp"
#include "code.hpp"

NullStmnt::NullStmnt(int line) :
    ASTLeaf(makeIdToken(line, "")) {}

int NullStmnt::getCode() const
{
    return NUL;
}
