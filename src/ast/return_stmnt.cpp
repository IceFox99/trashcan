#include "return_stmnt.hpp"
#include "code.hpp"

ASTreePtr ReturnStmnt::ret() const
{
    return child(0);
}

std::string ReturnStmnt::toString() const
{
    return "(return " + ret()->toString() + ")";
}

int ReturnStmnt::getCode() const
{
    return RETURN;
}
