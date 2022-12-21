#include "interpreter.hpp"
#include "ast/code.hpp"
#include "ast/if_stmnt.hpp"
#include "ast/while_stmnt.hpp"
#include "ast/block_stmnt.hpp"
#include "ast/assign_stmnt.hpp"
#include "ast/func_stmnt.hpp"
#include "ast/funcdef_stmnt.hpp"
#include "ast/return_stmnt.hpp"
#include "exception.hpp"
#include <iostream>

#define JUDGEBP(bp) \
    if (bp->getType() == INT && bp->toString() == "0") \
        return false; \
    else if (bp->getType() == BOOL && bp->toString() == "false") \
        return false; \
    return true;

#define CLEANFUNC(name) \
    if (funcVars.find(name) != funcVars.end()) \
        funcVars.erase(name); \
    if (funcs.find(name) != funcs.end()) \
        funcs.erase(name); \
    if (retVars.find(name) != retVars.end()) \
        retVars.erase(name);

#define GETBASEPTR(tp, bp) \
    if (tp->isNumber()) \
        bp = makeInt(std::static_pointer_cast<NumToken>(tp)->getNumber()); \
    else if (tp->isIdentifier()) { \
        if (tp->getText() == "true") \
            bp = makeBool(true); \
        else if (tp->getText() == "false") \
            bp = makeBool(false); \
        else \
            throw SandException("Parse variable into literal unproperly", tp); \
    } \
    else \
        bp = makeStr(tp->getText()); 

void Interpreter::inter(ASTreePtr p)
{
    int code = p->getCode();
    if (code == LIT) {
        std::cout << p->toString() << std::endl;
    }
    else if (code == VAR) {
        if (isGlobal) {
            if (vars.find(p->toString()) != vars.end()) {
                std::cout << vars.at(p->toString())->toString() << std::endl;
                return;
            }
        }
        else {
            if (funcVars[currFuncName].find(p->toString()) != vars.end()) {
                std::cout << funcVars[currFuncName].at(p->toString())->toString() << std::endl;
                return;
            }
        }
        throw SandException("Undefined variable at " + p->location());
    }
    else if (code == EXPR) {
        std::cout << eval(p)->toString() << std::endl;
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(p);
        if (asp->value()->getCode() != ASSIGN) {
            if (isGlobal)
                vars[asp->var()->toString()] = eval(asp); // Push this variable to stack
            else
                funcVars[currFuncName][asp->var()->toString()] = eval(asp);
        }
        else { // nested definition, e.g. i=j=k=z=x=c=...
            ASTreePtr temp = p;
            std::vector<std::string> varVec;
            while (temp->getCode() == ASSIGN) {
                AssignStmntPtr tempAss = std::static_pointer_cast<AssignStmnt>(temp);
                varVec.push_back(tempAss->var()->toString());
                temp = tempAss->value();
            }
            BasePtr res = eval(temp);
            if (isGlobal) {
                for (const std::string& v : varVec)
                    vars[v] = res;
            }
            else {
                for (const std::string& v : varVec)
                    funcVars[currFuncName][v] = res;
            }
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
    else if (code == FUNC) {
        eval(p);
    }
    else if (code == FUNCDEF) {
        FuncDefStmntPtr fdsp = std::static_pointer_cast<FuncDefStmnt>(p);
        FuncStmntPtr fsp = std::static_pointer_cast<FuncStmnt>(fdsp->parameters());
        std::string funcName = fsp->getFuncName();
        
        // Clear previous definition if any
        CLEANFUNC(funcName);

        for (int i = 1; i != fsp->numChildren(); ++i)
            funcVars[funcName][fsp->child(i)->toString()] = nullptr;
        funcs[funcName] = fdsp;
    }
    else if (code == RETURN) {
        if (isGlobal) {
            throw SandException("Illegal return statement in global namespace at " + p->location());
        }
        ReturnStmntPtr rsp = std::static_pointer_cast<ReturnStmnt>(p);
        retVars[currFuncName] = eval(rsp->ret());
    }
}

bool Interpreter::isTrue(ASTreePtr c) {
    BasePtr bp = eval(c);
    JUDGEBP(bp);
}

BasePtr Interpreter::eval(ASTreePtr t)
{
    int code = t->getCode();
    if (code == LIT) {
        ASTLeafPtr l = std::static_pointer_cast<ASTLeaf>(t);
        TokenPtr tp = l->token();
        BasePtr bp;
        GETBASEPTR(tp, bp);
        return bp;
    }
    else if (code == VAR) {
        if (isGlobal) {
            if (vars.find(t->toString()) != vars.end())
                return vars.at(t->toString()); 
        }
        else {
            if (funcVars[currFuncName].find(t->toString()) != funcVars[currFuncName].end())
                return funcVars[currFuncName].at(t->toString());
        }
        throw SandException("Undefined variable at " + t->location());
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(t);
        BasePtr res = eval(asp->value());
        if (res == nullptr)
            throw SandException("Can't assign variable to void at " + asp->location());
        return res;
    }
    else if (code == EXPR) {
        ExprStmntPtr esp = std::static_pointer_cast<ExprStmnt>(t);
        std::string oper = esp->op()->toString();
        BasePtr l = eval(esp->left());
        BasePtr r = eval(esp->right());

        if (l == nullptr || r == nullptr)
            throw SandException("Void can't be the operand at " + esp->left()->location());

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
    else if (code == FUNC) {
        //isGlobal = false;
        FuncStmntPtr fsp = std::static_pointer_cast<FuncStmnt>(t);
        currFuncName = fsp->getFuncName();
        if (funcs.find(currFuncName) == funcs.end())
            throw SandException("Undefined function at " + t->location());

        FuncDefStmntPtr fdsp = funcs[currFuncName];
        BlockStmntPtr bsp = std::static_pointer_cast<BlockStmnt>(funcs[currFuncName]->func());

        // function variable initialization
        if (fdsp->parameters()->numChildren() != fsp->numChildren())
            throw SandException("Incorrect number of function parameter at " + t->location());
        for (int i = 1; i != fsp->numChildren(); ++i) {
            ASTreePtr parameter = fsp->child(i);
            if (parameter->getCode() == VAR) {
                if (isGlobal)
                    funcVars[currFuncName][fdsp->parameters()->child(i)->toString()] = vars[fsp->child(i)->toString()];
                else
                    funcVars[currFuncName][fdsp->parameters()->child(i)->toString()] = funcVars[currFuncName][fsp->child(i)->toString()];
            }
            else if (parameter->getCode() == LIT) {
                ASTLeafPtr l = std::static_pointer_cast<ASTLeaf>(parameter);
                TokenPtr tp = l->token();
                BasePtr bp;
                GETBASEPTR(tp, bp);
                funcVars[currFuncName][fdsp->parameters()->child(i)->toString()] = bp;
            }
            else if (parameter->getCode() == EXPR)
                funcVars[currFuncName][fdsp->parameters()->child(i)->toString()] = eval(parameter);
            else
                throw SandException("Invalid function parameter at " + parameter->location());
        }

        isGlobal = false;

        // Function body
        ASTreePtr temp;
        for (int i = 0; i != bsp->numChildren(); ++i) {
            temp = bsp->child(i);
            inter(temp);
            if (temp->getCode() == RETURN)
                break;
        }

        // copy back to global variable
        for (int i = 1; i != fsp->numChildren(); ++i)
            vars[fsp->child(i)->toString()] = funcVars[currFuncName][fdsp->parameters()->child(i)->toString()];

        isGlobal = true;
        if (retVars.find(currFuncName) != retVars.end())
            return retVars[currFuncName];
        else
            return nullptr;
    }

    throw SandException("Unable to evaluate the code at " + t->location());
}
