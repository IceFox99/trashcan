#include "interpreter.hpp"
#include "ast/code.hpp"
#include "ast/if_stmnt.hpp"
#include "ast/while_stmnt.hpp"
#include "ast/block_stmnt.hpp"
#include "ast/assign_stmnt.hpp"
#include "exception.hpp"
#include <iostream>

#define JUDGEBP(bp) \
    if (bp->getType() == INT && bp->toString() == "0") \
        return false; \
    else if (bp->getType() == BOOL && bp->toString() == "false") \
        return false; \
    return true;

void Interpreter::inter(ASTreePtr p)
{
    int code = p->getCode();
    if (code == LIT) {
        std::cout << p->toString() << std::endl;
    }
    else if (code == VAR) {
        if (vars.find(p->toString()) != vars.end()) {
            std::cout << vars.at(p->toString())->toString() << std::endl;
        }
        else
            throw SandException("Undefined variable at " + p->location());
    }
    else if (code == EXPR) {
        std::cout << eval(p)->toString() << std::endl;
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(p);
        if (asp->value()->getCode() != ASSIGN)
            vars[asp->var()->toString()] = eval(asp); // Push this variable to stack
        else { // nested definition, e.g. i=j=k=z=x=c=...
            ASTreePtr temp = p;
            std::vector<std::string> varVec;
            while (temp->getCode() == ASSIGN) {
                AssignStmntPtr tempAss = std::static_pointer_cast<AssignStmnt>(temp);
                varVec.push_back(tempAss->var()->toString());
                temp = tempAss->value();
            }
            BasePtr res = eval(temp);
            for (const std::string& v : varVec)
                vars[v] = res;
                //vars[v] = makeBase(*res);
        }
    }
    else if (code == IFSTMNT) {
        IfStmntPtr isp = std::static_pointer_cast<IfStmnt>(p);
        ASTreePtr c = isp->condition();
        if (isTrue(c)) {
            ASTreePtr th = isp->thenBlock();
            if (th->getCode() == BLOCK) {
                for (int i = 0; i != th->numChildren(); ++i)
                    inter(th->child(i));
            }
            else
                inter(th);
        }
        else {
            if (isp->numChildren() > 2) {
                ASTreePtr el = isp->elseBlock();
                if (el->getCode() == BLOCK) {
                    for (int i = 0; i != el->numChildren(); ++i)
                        inter(el->child(i));
                }
                else
                    inter(el);
            }
        }
    }
    else if (code == WHILESTMNT) {
        WhileStmntPtr wsp = std::static_pointer_cast<WhileStmnt>(p);
        ASTreePtr c = wsp->condition();
        ASTreePtr b = wsp->body();
        while (isTrue(c)) {
            if (b->getCode() == BLOCK) {
                for (int i = 0; i != b->numChildren(); ++i)
                    inter(b->child(i));
            }
            else
                inter(b);
        }
    }
}

bool Interpreter::isTrue(ASTreePtr c) {
    //int code = c->getCode();
    //if (code == VAR) {
    //    if (vars.find(c->toString()) != vars.end()) { // When it's a variable
    //        BasePtr val = vars.at(c->toString());
    //        JUDGEBP(val);
    //    }
    //    else
    //        throw SandException("Undefined variable at " + c->location());
    //}
    //else if (code == EXPR || code == ASSIGN || code == LIT) {
    //    BasePtr bp = eval(c);
    //    JUDGEBP(bp);
    //}
    //else
    //    throw SandException("Illegal condition in if statement at " + c->location());
    BasePtr bp = eval(c);
    JUDGEBP(bp);
}

BasePtr Interpreter::eval(ASTreePtr t)
{
    int code = t->getCode();
    if (code == LIT) {
        ASTLeafPtr l = std::static_pointer_cast<ASTLeaf>(t);
        TokenPtr tp = l->token();
        if (tp->isNumber())
            return makeInt(std::static_pointer_cast<NumToken>(tp)->getNumber());
        else if (tp->isIdentifier()) {
            if (tp->getText() == "true")
                return makeBool(true);
            else if (tp->getText() == "false")
                return makeBool(false);
            else
                throw SandException("Parse variable into literal unproperly", tp);
        }
        else
            return makeStr(tp->getText());
    }
    else if (code == VAR) {
        if (vars.find(t->toString()) != vars.end()) {
            return vars.at(t->toString()); 
        }
        else
            throw SandException("Undefined variable at " + t->location());
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(t);
        return eval(asp->value());
    }
    else if (code == EXPR) {
        ExprStmntPtr esp = std::static_pointer_cast<ExprStmnt>(t);
        std::string oper = esp->op()->toString();
        BasePtr l = eval(esp->left());
        BasePtr r = eval(esp->right());

        if (l->getType() == r->getType() && l->getType() == STR) {
            if (oper == "+")
                return makeStr(std::static_pointer_cast<String>(l)->getStr()
                        + std::static_pointer_cast<String>(r)->getStr());
            else
                throw SandException("Illegal operations for string at " + esp->left()->location());
        }
        else if (l->getType() == STR || r->getType() == STR)
            throw SandException("Illegal operatiosn for string and other type at " 
                    + esp->left()->location());
        else {
            // Uncomplete: need support for more types, e.g. double
            if (oper == "+")
                return makeInt(std::static_pointer_cast<Int>(l)->getInt()
                        + std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "-")
                return makeInt(std::static_pointer_cast<Int>(l)->getInt()
                        - std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "*")
                return makeInt(std::static_pointer_cast<Int>(l)->getInt()
                        * std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "/")
                return makeInt(std::static_pointer_cast<Int>(l)->getInt()
                        / std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "%")
                return makeInt(std::static_pointer_cast<Int>(l)->getInt()
                        % std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "==")
                return makeBool(std::static_pointer_cast<Int>(l)->getInt()
                        == std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "<")
                return makeBool(std::static_pointer_cast<Int>(l)->getInt()
                        < std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == ">")
                return makeBool(std::static_pointer_cast<Int>(l)->getInt()
                        > std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == "<=")
                return makeBool(std::static_pointer_cast<Int>(l)->getInt()
                        <= std::static_pointer_cast<Int>(r)->getInt());
            else if (oper == ">=")
                return makeBool(std::static_pointer_cast<Int>(l)->getInt()
                        >= std::static_pointer_cast<Int>(r)->getInt());
            else
                throw SandException("Unknown operation at " + esp->left()->location());
        }
    }

    throw SandException("Unable to evaluate the code at " + t->location());
}
