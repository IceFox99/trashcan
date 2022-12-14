#include "astlist.hpp"
#include "../exception.hpp"

ASTList::ASTList() = default;

//ASTList::ASTList(ASTreePtr t)
//{
//    add(t);
//}

ASTList::ASTList(ASTreePtrVec vec) :
    children(vec) {}

void ASTList::add(ASTreePtr t)
{
    //children.push_back(std::static_pointer_cast<ASTree>(t));
    children.push_back(t);
}

void ASTList::pop()
{
    children.pop_back();
}

ASTreePtr ASTList::child(int i) const
{
    return children.at(i);
}

int ASTList::numChildren() const
{
    return children.size();
}

std::string ASTList::location() const
{
    for (auto p : children) {
        std::string str = p->location();
        if (!str.empty())
            return str;
    }
    return std::string();
}

std::string ASTList::toString() const
{
    std::string str = "(";
    for (auto p : children) {
        str += p->toString();
        str += " ";
    }
    if (str.length() > 1)
        str.pop_back(); // remove the last space
    str += ")";
    return str;
}

//int ASTList::getCode() const
//{
//    throw SandException("Unknown statement at " + location());
//}

//void ASTList::optimize()
//{
//    while (numChildren() == 1 && child(0)->numChildren() != 0) {
//        ASTreePtr son = child(0);
//        children = std::static_pointer_cast<ASTList>(son)->children;
//    }
//
//    for (auto& p : children) {
//        p->optimize();
//    }
//}
