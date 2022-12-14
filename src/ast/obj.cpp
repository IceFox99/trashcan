#include "obj.hpp"
#include "code.hpp"

Base::~Base() = default;

Int::Int(int i) :
    i(i) {}

int Int::getInt() const
{
    return i;
}

std::string Int::getType() const
{
    return INT;
}

std::string Int::toString() const
{
    return std::to_string(i);
}

String::String(std::string str) :
    str(str) {}

std::string String::getStr() const
{
    return str;
}

std::string String::getType() const
{
    return STR;
}

std::string String::toString() const
{
    return getStr();
}

Bool::Bool(bool b) :
    b(b) {}

bool Bool::getBool() const
{
    return b;
}

std::string Bool::getType() const
{
    return BOOL;
}

std::string Bool::toString() const
{
    return (b ? "true" : "false");
}
