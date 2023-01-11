#include "interpreter.hpp"
#include "ast/code.hpp"
#include "ast/if_stmnt.hpp"
#include "ast/while_stmnt.hpp"
#include "ast/block_stmnt.hpp"
#include "ast/assign_stmnt.hpp"
#include "ast/func_stmnt.hpp"
#include "ast/funcdef_stmnt.hpp"
#include "ast/return_stmnt.hpp"
#include "ast/break_stmnt.hpp"
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
        std::cout << p->toString() << std::endl;
    }
    else if (code == VAR) {
        if (!depth) {
            if (vars.find(p->toString()) != vars.end()) {
                std::cout << vars.at(p->toString())->toString() << std::endl;
                return;
            }
        }
        else {
            if (funcVars[currFuncName].find(p->toString()) != funcVars[currFuncName].end()) {
                std::cout << funcVars[currFuncName][p->toString()][depth]->toString() << std::endl;
                return;
            }
        }
        throw SandException("Undefined variable at line " + p->location());
    }
    else if (code == EXPR) {
        std::cout << eval(p)->toString() << std::endl;
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(p);
        if (asp->value()->getCode() != ASSIGN) {
            if (asp->var()->getCode() == FUNC || asp->var()->getCode() == INFUNC) 
                throw SandException("Can't assign value to a function statement at line " + asp->location());

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
            for (int i = 0; i != th->numChildren(); ++i) {
                inter(th->child(i));
                if (isReturned || isBroke)
                    break;
            }
        }
        else {
            if (isp->numChildren() > 2) {
                ASTreePtr el = isp->elseBlock();
                for (int i = 0; i != el->numChildren(); ++i) {
                    inter(el->child(i));
                    if (isReturned || isBroke)
                        break;
                }
            }
        }
    }
    else if (code == WHILESTMNT) {
        //++isWhile;
        //isBroke = false;
        WhileStmntPtr wsp = std::static_pointer_cast<WhileStmnt>(p);

        std::string label = wsp->getLabel();
        whileFlags.push_back(std::make_pair(label, false));

        ASTreePtr c = wsp->condition();
        ASTreePtr b = wsp->body();
        while (isTrue(c)) {
            for (int i = 0; i != b->numChildren(); ++i) {
                inter(b->child(i));
                if (isReturned || whileFlags[whileFlags.size() - 1].second)
                    break;
                //if (isReturned || isBroke)
                //    break;
            }
            if (whileFlags[whileFlags.size() - 1].second)
                break;
        }
        //isBroke = false;
        //--isWhile;
        whileFlags.pop_back();
    }
    else if (code == FUNC) {
        eval(p);
    }
    else if (code == INFUNC) {
        throw SandException("Illegal colon operator at line " + p->location() + ", it should only exists in function definition");
    }
    else if (code == FUNCDEF) {
        FuncDefStmntPtr fdsp = std::static_pointer_cast<FuncDefStmnt>(p);
        FuncStmntPtr fsp = std::static_pointer_cast<FuncStmnt>(fdsp->parameters());
        BlockStmntPtr bsp = std::static_pointer_cast<BlockStmnt>(fdsp->func());
        std::string funcName = fsp->getFuncName();
        
        // Clear previous definition if any
        CLEANFUNC(funcName);

        // Inline the function
        ++depth;
        for (int i = 0; i != bsp->numChildren(); ++i)
            inlStat(bsp, &i, bsp->child(i));
        
        --depth;
        funcs[funcName] = fdsp;
        //std::cout << fdsp->toString() << std::endl;
    }
    else if (code == RETURN) {
        if (!depth)
            throw SandException("Illegal return statement in global namespace at line " + p->location());

        ReturnStmntPtr rsp = std::static_pointer_cast<ReturnStmnt>(p);
        retVars[currFuncName] = eval(rsp->ret());
        isReturned = true;
    }
    else if (code == BREAK) {
        //if (!isWhile)
        //    throw SandException("Illegal break statment outside of while loop at line " + p->location());
        if (whileFlags.empty())
            throw SandException("Illegal break statment outside of while loop at line " + p->location());

        BreakStmntPtr brsp = std::static_pointer_cast<BreakStmnt>(p);
        if (brsp->getLabel().empty())
            whileFlags[whileFlags.size() - 1].second = true;
        else {
            // check whether it's legal break statement
            int index = -1;
            for (int i = whileFlags.size(); i != 0; --i) {
                if (whileFlags[i - 1].first == brsp->getLabel()) {
                    index = i - 1;
                    break;
                }
            }
            if (index == -1)
                throw SandException("Illegal break statement with wrong break label at line " + p->location());
            
            //isBroke = true;
            for (int i = whileFlags.size(); i != index; --i)
                whileFlags[i - 1].second = true;
        }
    }
    else if (code == NUL) {
        return;
    }
    else
        throw SandException("Illegal statement at line " + p->location());
}

void Interpreter::inlStat(BlockStmntPtr bsp, int* b_index, ASTreePtr p) {
    if (p->getCode() == INFUNC)
        inlStat(bsp, b_index, p, false);
    else
        inlStat(bsp, b_index, p, true);
}

// Inline the statement, replace the corresponding variable name
// bsp stands for the outer function's block statement
// fsp stands for function statment (with new variable name) 
// fdsp stands for the function definition of the function to be inlined
void Interpreter::inlStat(BlockStmntPtr bsp, int* b_index, ASTreePtr p, bool useRet, ASTreePtr other, int other_index) {
    if (p->getCode() == INFUNC) {
        InFuncStmntPtr ifsp = std::static_pointer_cast<InFuncStmnt>(p);
        if (funcs.find(ifsp->getFuncName()) == funcs.end())
            throw SandException("Illegal colon operator at line " + p->location() + ", undefined function");

        FuncDefStmntPtr in_fdsp = funcs[ifsp->getFuncName()];
        if (in_fdsp->parameters()->numChildren() != ifsp->numChildren())
            throw SandException("Incorrect number of function parameter at line " + p->location());

        // implement a while statement
        WhileStmntPtr wsp = makeWhileStmnt();
        wsp->add(makeASTLeaf(makeIdToken(0, "true"))); // add the condition of while statement
        wsp->setLabel("__F" + std::static_pointer_cast<FuncStmnt>(in_fdsp->parameters())->getFuncName() + "_flag");
        BlockStmntPtr new_bsp = makeBlockStmnt();

        ASTreePtr st;
        for (int j = 0; j != in_fdsp->func()->numChildren(); ++j) {
            st = in_fdsp->func()->child(j);
            new_bsp->add(inlPrim(ifsp, in_fdsp, st, useRet, new_bsp));
        }
        new_bsp->add(makeBreakStmnt(std::stoi(ifsp->location()), "__F" + std::static_pointer_cast<FuncStmnt>(in_fdsp->parameters())->getFuncName() + "_flag"));
        wsp->add(new_bsp); // add the body of while statement
        bsp->children.insert(bsp->children.begin() + (*b_index)++, wsp);

        if (useRet) {
            ASTreePtr new_p = makeASTLeaf(makeIdToken(std::stoi(p->location()), 
                        "__F" + std::static_pointer_cast<FuncStmnt>(in_fdsp->parameters())->getFuncName() + "_TEMP" + std::to_string(counter - 1)));
            
            ASTListPtr lp = std::static_pointer_cast<ASTList>(other);
            lp->children.erase(lp->children.begin() + other_index);
            lp->children.insert(lp->children.begin() + other_index, new_p);
        }
        else {
            bsp->children.erase(bsp->children.begin() + *b_index); // delete the inlined function
            --(*b_index);
        }
    }
    else {
        for (int k = 0; k != p->numChildren(); ++k)
            inlStat(bsp, b_index, p->child(k), useRet, p, k);
    }
}

// fsp stands for the function to be inlined (which has its own parameters)
// fdsp stands for the outer function definition (for checking whether the variable name is matching)
ASTreePtr Interpreter::inlPrim(FuncStmntPtr fsp, FuncDefStmntPtr fdsp, ASTreePtr p, bool useRet, BlockStmntPtr bsp) {
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
        //TokenPtr tp = makeIdToken(ori_tp->getLineNumber(), "__F" + ori_fsp->getFuncName() +
        //        "_" + ori_tp->getText() + std::to_string(counter++));
        TokenPtr tp = makeIdToken(ori_tp->getLineNumber(), "__F" + ori_fsp->getFuncName() + "_" + ori_tp->getText());
        ASTLeafPtr lp = makeASTLeaf(tp);
        return lp;
    }
    else if (p->getCode() == EXPR) {
        ExprStmntPtr esp = std::static_pointer_cast<ExprStmnt>(p);
        ExprStmntPtr new_esp = makeExprStmnt();
        new_esp->add(inlPrim(fsp, fdsp, esp->left(), useRet, bsp));
        new_esp->add(esp->op());
        new_esp->add(inlPrim(fsp, fdsp, esp->right(), useRet, bsp));
        return new_esp;
    }
    else if (p->getCode() == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(p);
        AssignStmntPtr new_asp = makeAssignStmnt();
        new_asp->add(inlPrim(fsp, fdsp, asp->var(), useRet, bsp));
        new_asp->add(inlPrim(fsp, fdsp, asp->value(), useRet, bsp));
        return new_asp;
    }
    else if (p->getCode() == IFSTMNT) {
        IfStmntPtr isp = std::static_pointer_cast<IfStmnt>(p);
        IfStmntPtr new_isp = makeIfStmnt();
        new_isp->add(inlPrim(fsp, fdsp, isp->condition(), useRet, bsp));

        BlockStmntPtr then_bsp = makeBlockStmnt();
        BlockStmntPtr ori_then = std::static_pointer_cast<BlockStmnt>(isp->thenBlock());
        for (int i = 0; i != ori_then->numChildren(); ++i) 
            then_bsp->add(inlPrim(fsp, fdsp, ori_then->child(i), useRet, then_bsp));
        new_isp->add(then_bsp);

        if (isp->numChildren() > 2) {
            BlockStmntPtr else_bsp = makeBlockStmnt();
            BlockStmntPtr ori_else = std::static_pointer_cast<BlockStmnt>(isp->elseBlock());
            for (int j = 0; j != ori_else->numChildren(); ++j)
                else_bsp->add(inlPrim(fsp, fdsp, ori_else->child(j), useRet, else_bsp));
            new_isp->add(else_bsp);
        }
        return new_isp;
    }
    else if (p->getCode() == WHILESTMNT) {
        WhileStmntPtr wsp = std::static_pointer_cast<WhileStmnt>(p);
        WhileStmntPtr new_wsp = makeWhileStmnt();
        BlockStmntPtr ori_bsp = std::static_pointer_cast<BlockStmnt>(wsp->body());
        new_wsp->add(inlPrim(fsp, fdsp, wsp->condition(), useRet, bsp));

        BlockStmntPtr while_bsp = makeBlockStmnt();
        for (int i = 0; i != ori_bsp->numChildren(); ++i)
            while_bsp->add(inlPrim(fsp, fdsp, ori_bsp->child(i), useRet, while_bsp));
        new_wsp->add(while_bsp);
        return new_wsp;
    }
    else if (p->getCode() == FUNC) {
        FuncStmntPtr old_fsp = std::static_pointer_cast<FuncStmnt>(p);
        FuncStmntPtr new_fsp = makeFuncStmnt();
        new_fsp->add(old_fsp->child(0));
        for (int i = 1; i != old_fsp->numChildren(); ++i)
            new_fsp->add(inlPrim(fsp, fdsp, old_fsp->child(i), useRet, bsp));
        return new_fsp;
    }
    else if (p->getCode() == RETURN) {
        FuncStmntPtr ori_fsp = std::static_pointer_cast<FuncStmnt>(fdsp->parameters());
        if (useRet) {
            ReturnStmntPtr rsp = std::static_pointer_cast<ReturnStmnt>(p);
            AssignStmntPtr asp = makeAssignStmnt();

            ASTLeafPtr lp = makeASTLeaf(makeIdToken(std::stoi(fsp->location()), "__F" + ori_fsp->getFuncName() + "_TEMP" + std::to_string(counter++)));
            asp->add(lp);
            asp->add(inlPrim(fsp, fdsp, rsp->ret(), useRet, bsp));
            bsp->add(asp);
        }

        return makeBreakStmnt(std::stoi(fsp->location()), "__F" + ori_fsp->getFuncName() + "_flag");
    }
    else
        throw SandException("Illegal statement for colon operator at line " + p->location());
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
        throw SandException("Undefined variable at line " + t->location());
    }
    else if (code == ASSIGN) {
        AssignStmntPtr asp = std::static_pointer_cast<AssignStmnt>(t);
        BasePtr res = eval(asp->value());
        if (res == nullptr)
            throw SandException("Can't assign variable to void at line " + asp->location());
        return res;
    }
    else if (code == EXPR) {
        ExprStmntPtr esp = std::static_pointer_cast<ExprStmnt>(t);
        std::string oper = esp->op()->toString();
        BasePtr l = eval(esp->left());
        BasePtr r = eval(esp->right());

        if (l == nullptr || r == nullptr)
            throw SandException("Void can't be the operand at line " + esp->left()->location());

        if (l->getType() == STR || r->getType() == STR) {
            if (oper == "+") {
                std::string left, right;
                BPTOSTRING(l, left);
                BPTOSTRING(r, right);
                return makeStr(left + right);
            }
            else
                throw SandException("Illegal operations for string at line " + esp->left()->location());
        }
        else if (l->getType() == STR || r->getType() == STR)
            throw SandException("Illegal operatiosn for string and other type at line " 
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
                throw SandException("Unknown operation at line " + esp->left()->location());
        }
    }
    else if (code == FUNC) {
        FuncStmntPtr fsp = std::static_pointer_cast<FuncStmnt>(t);
        std::string lastFuncName = currFuncName;
        currFuncName = fsp->getFuncName();
        if (funcs.find(currFuncName) == funcs.end())
            throw SandException("Undefined function at line " + t->location());

        FuncDefStmntPtr fdsp = funcs[currFuncName];
        BlockStmntPtr bsp = std::static_pointer_cast<BlockStmnt>(funcs[currFuncName]->func());

        // function variable initialization
        if (fdsp->parameters()->numChildren() != fsp->numChildren())
            throw SandException("Incorrect number of function parameter at line " + t->location());

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
                throw SandException("Invalid function parameter at line " + parameter->location());
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

    throw SandException("Unable to evaluate the code at line " + t->location());
}
