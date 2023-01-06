#include "expr_stmnt.hpp"
#include "astleaf.hpp"
#include "code.hpp"
#include "../parser.hpp"

ASTreePtr ExprStmnt::left() const
{
    return child(0);
}

ASTreePtr ExprStmnt::op() const
{
    return child(1);
}

ASTreePtr ExprStmnt::right() const
{
    return child(2);
}

int ExprStmnt::getCode() const
{
    return EXPR;
}
