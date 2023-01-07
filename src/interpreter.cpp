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

#define BPTOSTRING(bp, str) \
    if (bp->getType() == STR) \
        str = std::static_pointer_cast<String>(bp)->getStr(); \
    else if (bp->getType() == INT) \
        str = std::to_string(std::static_pointer_cast<Int>(bp)->getInt()); \
    else if (bp->getType() == BOOL) \
        str = std::static_pointer_cast<Bool>(bp)->getBool() ? "true" : "false";

void Interpreter::inter(ASTreePtr p)
{
    int code = p->getCode();
    if (code == LIT) {
        std::cout << p->toString();
    }
    else if (code == VAR) {
        if (!depth) {
            if (vars.find(p->toString()) != vars.end()) {
                std::cout << vars.at(p->toString())->toString();
                return;
            }
        }
        else {
            if (funcVars[currFuncName].find(p->toString()) != funcVars[currFuncName].end()) {
                std::cout << funcVars[currFuncName][p->toString()][depth]->toString();
                return;
            }
        }
        throw SandException("Undefined variable at " + p->location());
    }
    else if (code == EXPR) {
        std::cout << eval(p)->toString();
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(p);
        if (asp->value()->getCode() != ASSIGN) {
            if (!depth)
                vars[asp->var()->toString()] = eval(asp); // Push this variable to stack
            else
                funcVars[currFuncName][asp->var()->toString()][depth] = eval(asp);
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
            if (!depth) {
                for (const std::string& v : varVec)
                    vars[v] = res;
            }
            else {
                for (const std::string& v : varVec)
                    funcVars[currFuncName][v][depth] = res;
            }
        }
    }
    else if (code == IFSTMNT) {
        IfStmntPtr isp = std::static_pointer_cast<IfStmnt>(p);
        ASTreePtr c = isp->condition();
        if (isTrue(c)) {
            ASTreePtr th = isp->thenBlock();
            if (th->getCode() == BLOCK) {
                for (int i = 0; i != th->numChildren(); ++i) {
                    inter(th->child(i));
                    if (isReturned || isBroke)
                        break;
                }
            }
            else
                inter(th);
        }
        else {
            if (isp->numChildren() > 2) {
                ASTreePtr el = isp->elseBlock();
                if (el->getCode() == BLOCK) {
                    for (int i = 0; i != el->numChildren(); ++i) {
                        inter(el->child(i));
                        if (isReturned || isBroke)
                            break;
                    }
                }
                else
                    inter(el);
            }
        }
    }
    else if (code == WHILESTMNT) {
        isWhile = true;
        WhileStmntPtr wsp = std::static_pointer_cast<WhileStmnt>(p);
        ASTreePtr c = wsp->condition();
        ASTreePtr b = wsp->body();
        while (isTrue(c)) {
            if (b->getCode() == BLOCK) {
                for (int i = 0; i != b->numChildren(); ++i) {
                    inter(b->child(i));
                    if (isReturned || isBroke)
                        break;
                }
                if (isBroke)
                    break;
            }
            else
                inter(b);
        }
        isBroke = false;
        isWhile = false;
    }
    else if (code == FUNC) {
        eval(p);
    }
    else if (code == INFUNC) {
        throw SandException("Illegal colon operator at " + p->location() + ", it should only exists in function definition");
    }
    else if (code == FUNCDEF) {
        FuncDefStmntPtr fdsp = std::static_pointer_cast<FuncDefStmnt>(p);
        FuncStmntPtr fsp = std::static_pointer_cast<FuncStmnt>(fdsp->parameters());
        BlockStmntPtr bsp = std::static_pointer_cast<BlockStmnt>(fdsp->func());
        std::string funcName = fsp->getFuncName();
        
        // Clear previous definition if any
        CLEANFUNC(funcName);

        // Inline the function
        ASTreePtr temp;
        for (int i = 0; i != bsp->numChildren(); ++i) {
            temp = bsp->child(i);
            if (temp->getCode() == INFUNC) {
                InFuncStmntPtr ifsp = std::static_pointer_cast<InFuncStmnt>(temp);
                if (funcs.find(ifsp->getFuncName()) == funcs.end())
                    throw SandException("Illegal colon operator at " + p->location() + ", undefined function");

                FuncDefStmntPtr in_fdsp = funcs[ifsp->getFuncName()]; // function to be inlined
                if (in_fdsp->parameters()->numChildren() != ifsp->numChildren())
                    throw SandException("Incorrect number of function parameter at " + p->location());

                for (int j = 0; j != in_fdsp->func()->numChildren(); ++j)
                    inlStat(bsp, &i, ifsp, in_fdsp, j, false);

                bsp->children.erase(bsp->children.begin() + i); // delete the inlined statement
                --i;
            }
        }

        funcs[funcName] = fdsp;
    }
    else if (code == RETURN) {
        if (!depth)
            throw SandException("Illegal return statement in global namespace at " + p->location());

        ReturnStmntPtr rsp = std::static_pointer_cast<ReturnStmnt>(p);
        retVars[currFuncName] = eval(rsp->ret());
        isReturned = true;
    }
    else if (code == BREAK) {
        if (!isWhile)
            throw SandException("Illegal break statment outside of while loop at " + p->location());
        
        isBroke = true;
    }
    else
        throw SandException("Illegal statement at " + p->location());
}

ASTreePtr Interpreter::inlPrim(FuncStmntPtr fsp, FuncDefStmntPtr fdsp, ASTreePtr p) {
    if (p->getCode() == LIT) {
        return p;
    }
    else if (p->getCode() == VAR) {
        FuncStmntPtr ori_fsp = std::static_pointer_cast<FuncStmnt>(fdsp->parameters());
        for (int i = 1; i != ori_fsp->numChildren(); ++i) {
            if (p->toString() == ori_fsp->child(i)->toString()) {
                return fsp->child(i);
            }
        }

        TokenPtr ori_tp = std::static_pointer_cast<ASTLeaf>(p)->token();
        TokenPtr tp = makeIdToken(ori_tp->getLineNumber(), "__F" + ori_fsp->getFuncName() +
                "_" + ori_tp->getText());
        ASTLeafPtr lp = makeASTLeaf(tp);
        return lp;
    }
    else if (p->getCode() == EXPR) {
        ExprStmntPtr esp = std::static_pointer_cast<ExprStmnt>(p);
        ExprStmntPtr new_esp = makeExprStmnt();
        new_esp->add(inlPrim(fsp, fdsp, esp->left()));
        new_esp->add(esp->op());
        new_esp->add(inlPrim(fsp, fdsp, esp->right()));
        return new_esp;
    }
    else if (p->getCode() == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(p);
        AssignStmntPtr new_asp = makeAssignStmnt();
        new_asp->add(inlPrim(fsp, fdsp, asp->var()));
        new_asp->add(inlPrim(fsp, fdsp, asp->value()));
        return new_asp;
    }
    else if (p->getCode() == IFSTMNT) {
        IfStmntPtr isp = std::static_pointer_cast<IfStmnt>(p);
        IfStmntPtr new_isp = makeIfStmnt();
        new_isp->add(inlPrim(fsp, fdsp, isp->condition()));
        BlockStmntPtr then_bsp = makeBlockStmnt();
        for (int i = 0; i != isp->thenBlock()->numChildren(); ++i)
            then_bsp->add(inlPrim(fsp, fdsp, isp->thenBlock()->child(i)));
        new_isp->add(then_bsp);

        BlockStmntPtr else_bsp;
        if (isp->numChildren() > 2) {
            else_bsp = makeBlockStmnt();
            for (int j = 0; j != isp->elseBlock()->numChildren(); ++j)
                else_bsp->add(inlPrim(fsp, fdsp, isp->elseBlock()->child(j)));
            new_isp->add(else_bsp);
        }
        return new_isp;
    }
    else if (p->getCode() == WHILESTMNT) {
        WhileStmntPtr wsp = std::static_pointer_cast<WhileStmnt>(p);
        WhileStmntPtr new_wsp = makeWhileStmnt();
        new_wsp->add(inlPrim(fsp, fdsp, wsp->condition()));
        BlockStmntPtr while_bsp = makeBlockStmnt();
        for (int i = 0; i != wsp->body()->numChildren(); ++i)
            while_bsp->add(inlPrim(fsp, fdsp, wsp->body()->child(i)));
        new_wsp->add(while_bsp);
        return new_wsp;
    }
    else if (p->getCode() == FUNC) {
        FuncStmntPtr old_fsp = std::static_pointer_cast<FuncStmnt>(p);
        FuncStmntPtr new_fsp = makeFuncStmnt();
        new_fsp->add(old_fsp->child(0));
        for (int i = 1; i != old_fsp->numChildren(); ++i)
            new_fsp->add(inlPrim(fsp, fdsp, old_fsp->child(i)));
        return new_fsp;
    }
    else if (p->getCode() == RETURN) {
        ReturnStmntPtr rsp = std::static_pointer_cast<ReturnStmnt>(p);
        ReturnStmntPtr new_rsp = makeReturnStmnt();
        new_rsp->add(inlPrim(fsp, fdsp, rsp->ret()));
        return new_rsp;
    }
    else
        throw SandException("Illegal statement for colon operator at " + p->location());
}

// Inline the statement, replace the corresponding variable name
// bsp stands for the outer function's block statement
// fsp stands for function statment (with new variable name) 
// fdsp stands for the function definition of the function to be inlined
void Interpreter::inlStat(BlockStmntPtr bsp, int* b_index, FuncStmntPtr fsp, FuncDefStmntPtr fdsp, int fd_index, bool keepRet) {
    FuncStmntPtr ori_fsp = std::static_pointer_cast<FuncStmnt>(fdsp->parameters());
    ASTreePtr st = std::static_pointer_cast<BlockStmnt>(fdsp->func())->child(fd_index);
    if (st->getCode() == RETURN && !keepRet)
        return;

    bsp->children.insert(bsp->children.begin() + (*b_index)++, inlPrim(fsp, fdsp, st));
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
        if (!depth) {
            if (vars.find(t->toString()) != vars.end())
                return vars.at(t->toString()); 
        }
        else {
            if (funcVars[currFuncName].find(t->toString()) != funcVars[currFuncName].end())
                return funcVars[currFuncName][t->toString()].at(depth);
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

        //if (l->getType() == r->getType() && l->getType() == STR) {
        if (l->getType() == STR || r->getType() == STR) {
            if (oper == "+") {
                std::string left, right;
                BPTOSTRING(l, left);
                BPTOSTRING(r, right);
                return makeStr(left + right);
            }
            else
                throw SandException("Illegal operations for string at " + esp->left()->location());
            //return makeStr(std::static_pointer_cast<String>(l)->getStr()
            //        + std::static_pointer_cast<String>(r)->getStr());
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
        FuncStmntPtr fsp = std::static_pointer_cast<FuncStmnt>(t);
        std::string lastFuncName = currFuncName;
        currFuncName = fsp->getFuncName();
        if (funcs.find(currFuncName) == funcs.end())
            throw SandException("Undefined function at " + t->location());

        FuncDefStmntPtr fdsp = funcs[currFuncName];
        BlockStmntPtr bsp = std::static_pointer_cast<BlockStmnt>(funcs[currFuncName]->func());

        // function variable initialization
        if (fdsp->parameters()->numChildren() != fsp->numChildren())
            throw SandException("Incorrect number of function parameter at " + t->location());

        // function temporary backup
        std::vector<BasePtr> varBackup;
        for (int i = 1; i != fsp->numChildren(); ++i) {
            ASTreePtr parameter = fsp->child(i);
            if (parameter->getCode() == VAR) {
                if (!depth)
                    varBackup.push_back(vars[fsp->child(i)->toString()]);
                else
                    varBackup.push_back(funcVars[lastFuncName][fsp->child(i)->toString()][depth]);
                    //varBackup.push_back(funcVars[currFuncName][fsp->child(i)->toString()][depth]);
            }
            else if (parameter->getCode() == LIT) {
                ASTLeafPtr l = std::static_pointer_cast<ASTLeaf>(parameter);
                TokenPtr tp = l->token();
                BasePtr bp;
                GETBASEPTR(tp, bp);
                varBackup.push_back(bp);
            }
            else if (parameter->getCode() == EXPR || parameter->getCode() == FUNC) {
                varBackup.push_back(eval(parameter));
            }
            else
                throw SandException("Invalid function parameter at " + parameter->location());
        }

        ++depth;

        // Copy back
        for (int j = 1; j != fsp->numChildren(); ++j)
            funcVars[currFuncName][fdsp->parameters()->child(j)->toString()][depth] = varBackup.at(j - 1);

        varBackup.clear();

        // Function body
        for (int i = 0; i != bsp->numChildren(); ++i) {
            inter(bsp->child(i));
            if (isReturned)
                break;
        }

        // copy back to global variable
        for (int i = 1; i != fsp->numChildren(); ++i) {
            if (fsp->child(i)->getCode() == VAR) {
                if (depth == 1)
                    vars[fsp->child(i)->toString()] = funcVars[currFuncName][fdsp->parameters()->child(i)->toString()][depth];
                else
                    funcVars[lastFuncName][fsp->child(i)->toString()][depth - 1] = funcVars[currFuncName][fdsp->parameters()->child(i)->toString()][depth];
            }
        }

        --depth;
        currFuncName = lastFuncName;
        isReturned = false;
        if (retVars.find(fsp->getFuncName()) != retVars.end())
            return retVars[fsp->getFuncName()];
        else
            return nullptr;
    }

    throw SandException("Unable to evaluate the code at " + t->location());
}
