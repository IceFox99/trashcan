#include "expr_stmnt.hpp"
#include "astleaf.hpp"
#include "code.hpp"
#include "../parser.hpp"

//#define evaluate_left(lTree, rTree, op) \
//    BasePtr l = lTree->eval(); \
//    BasePtr r = rTree->eval(); \
//    if (l->getType() == r->getType() && l->getType() == "int") { \
//        return makeIntPtr(static_pointer_cast<Int>(l)->getInt() ## op ## static_pointer_cast<Int>(r)->getInt()); \
//    } \
//    else \
//        throw SandException("Illegal operation at " + lTree->location());

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
