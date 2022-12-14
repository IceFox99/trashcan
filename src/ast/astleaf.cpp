#include "code.hpp"
#include "astleaf.hpp"
#include "../exception.hpp"

ASTLeaf::ASTLeaf(TokenPtr t) :
    t(t) {}

ASTreePtr ASTLeaf::child(int i) const
{
    throw SandException("Can't access ASTLeaf's nodes");
}

int ASTLeaf::numChildren() const
{
    return 0;
}

std::string ASTLeaf::location() const
{
    return "line " + std::to_string(t->getLineNumber());
}

std::string ASTLeaf::toString() const
{
    return t->getText();
}

TokenPtr ASTLeaf::token() const
{
    return t;
}

//void ASTLeaf::optimize() {}

int ASTLeaf::getCode() const
{
    if (t->isIdentifier() && t->getText() != "true" && t->getText() != "false")
        return VAR;
    return LIT;
}
