#include <utility>
#include "parser.hpp"
#include "ast/code.hpp"
#include "ast/null_stmnt.hpp"
#include "ast/block_stmnt.hpp"
#include "ast/assign_stmnt.hpp"
#include "ast/expr_stmnt.hpp"
#include "ast/while_stmnt.hpp"
#include "ast/if_stmnt.hpp"
#include "ast/return_stmnt.hpp"
#include "ast/funcdef_stmnt.hpp"
#include "ast/func_stmnt.hpp"

/**
 * This is the EBNF of the grammar, parse function will
 * return a statement each time.
 *
 * primary: "(" expr ")" | func | NUMBER | IDENTIFIER | STRING
 * expr: primary { OP primary }
 * func: IDENTIFIER "(" { expr "," } [ expr ] ")"
 * func_def: "func" IDENTIFIER ( "(" { IDENTIFIER "," } [ IDENTIFIER ] ")" block | "=" IDENTIFIER { OP IDENTIFIER } )
 * return: "return" expr
 * block: "{" { statement } "}"
 * statement: "if" "(" expr ")" ( block | statement ) [ "else" ( block | statement ) ]  
 *          | "while" "(" expr ")" ( block | statement )
 *          | ( expr | return ) ";" | func_def | ":" func ";"
 */

const std::unordered_set<std::string> Parser::reserved { ",", ";", "{", "}", Token::SEOL, \
        "if", "else", "while", "func", "return" };
const std::unordered_map<std::string, Parser::Precedence> Parser::operators { \
    std::make_pair("=", Precedence(1, false)), \
    std::make_pair("==", Precedence(2, true)), \
    std::make_pair(">", Precedence(2, true)), \
    std::make_pair("<", Precedence(2, true)), \
    std::make_pair("<=", Precedence(2, true)), \
    std::make_pair(">=", Precedence(2, true)), \
    std::make_pair("+", Precedence(3, true)), \
    std::make_pair("-", Precedence(3, true)), \
    std::make_pair("*", Precedence(4, true)), \
    std::make_pair("/", Precedence(4, true)), \
    std::make_pair("%", Precedence(4, true)) \
};

Parser::Parser() = default;

// @finished
ASTreePtr Parser::parse(Lexer& l) {
    TokenPtr t = l.peek(0);
    if (t->isEOF())
        throw SandException("Parsing end of file", t);

    if (t->isIdentifier()) {
        std::string id = t->getText();
        if (id == "while")
            return expectWhile(l);
        else if (id == "if")
            return expectIf(l);
        else if (id == "func")
            return expectFuncDef(l);
        else if (id == ";") {
            TokenPtr temp = l.read();
            return makeNullStmnt(temp->getLineNumber());
        }
    }

    ASTreePtr res;
    if (t->isIdentifier() && t->getText() == "return")
        res = expectReturn(l);
    else if (t->isIdentifier() && t->getText() == ":") {
        l.read();
        res = makeInFuncStmnt(std::static_pointer_cast<FuncStmnt>(expectFunc(l)));
    }
    else
        res = expectExpr(l);

    TokenPtr end = l.read();
    if (!end->isIdentifier() || end->getText() != ";")
        throw SandException("Missing end specifier in expression", end);

    return res;
}

// @finished
ASTreePtr Parser::expectPrimary(Lexer& l) {
    TokenPtr t = l.peek(0);
    if (t->isEOF())
        throw SandException("Parsing end of file", t);

    if (t->isIdentifier() && t->getText() == "(") {
        // Left parenthesis
        l.read();
        
        // Expression
        ASTreePtr res = expectExpr(l);

        // Right parenthesis
        TokenPtr trp = l.read();
        if (!trp->isIdentifier() || trp->getText() != ")")
            throw SandException("Missing right parenthesis in expression", trp);

        return res;
    }
    else if (t->isNumber() || t->isString()) {
        return makeASTLeaf(l.read());
    }
    else if (t->isIdentifier()) {
        if (reserved.find(t->getText()) != reserved.end())
            throw SandException("Can't use keywords as identifier", t);
        TokenPtr temp = l.peek(1);
        if (temp->isIdentifier() && temp->getText() == "(")
            return expectFunc(l);

        return makeASTLeaf(l.read());
    }
    else
        throw SandException("Improper primary", t);
}

// @finished
ASTreePtr Parser::expectExpr(Lexer& l) {
    TokenPtr t = l.peek(0);
    if (t->isEOF())
        throw SandException("Parsing end of file", t);

    // first primary
    if (t->isIdentifier() && t->getText() == ")")
        throw SandException("Null expression", t);

    ASTreePtr t1 = expectPrimary(l);
    t = l.peek(0);
    if (!t->isIdentifier() || operators.find(t->getText()) == operators.end())
        return t1;
    
    ExprStmntPtr res;

    // op + primary
    std::string lastOp; // Last operator
    TokenPtr tempOp = l.read();
    lastOp = tempOp->getText();
    if (lastOp == "=") {
        AssignStmntPtr ass = makeAssignStmnt();
        if (t1->toString() == "true" || t1->toString() == "false")
            throw SandException("Can't use true or false as variable name at " + t1->location());
        ass->add(t1);
        ass->add(expectExpr(l));
        return ass;
    }

    ExprStmntPtr lastList; // last List
    ExprStmntPtr rootList; // root list for non-right associative operator
    res = makeExprStmnt();
    res->add(t1);
    res->add(makeASTLeaf(tempOp)); // add the operator
    res->add(expectPrimary(l)); // add next primary
    lastList = res;
    if (!operators.at(lastOp).leftAssoc)
        rootList = res;
    else
        rootList = nullptr;
    
    t = l.peek(0);
    while (t->isIdentifier() && operators.find(t->getText()) != operators.end()) {
        // if the last operator is right associative or precedence is higher than last one
        if (!operators.at(t->getText()).leftAssoc 
                || operators.at(t->getText()).value > operators.at(lastOp).value) { 
            ExprStmntPtr subList = makeExprStmnt();
            subList->add(lastList->child(2));
            TokenPtr tempOp = l.read();
            if (lastOp != "=" && tempOp->getText() == "=")
                throw SandException("Illegal assignment", t);
            lastOp = tempOp->getText();
            subList->add(makeASTLeaf(tempOp)); // add the operator
            subList->add(expectPrimary(l)); // add next primary
            lastList->pop();
            lastList->add(subList);
            lastList = subList;
            if (!operators.at(lastOp).leftAssoc) // assign rootList
                rootList = lastList;
        } 
        else { // if precedence is lower than or equal to last one
            ExprStmntPtr upList = makeExprStmnt();
            if (!rootList) {
                upList->add(res);
                TokenPtr tempOp = l.read();
                lastOp = tempOp->getText();
                upList->add(makeASTLeaf(tempOp)); // add the operator
                upList->add(expectPrimary(l));
                res = upList;
            }
            else {
                upList->add(rootList->child(2));
                TokenPtr tempOp = l.read();
                lastOp = tempOp->getText();
                upList->add(makeASTLeaf(tempOp)); // add the operator
                upList->add(expectPrimary(l));
                rootList->pop();
                rootList->add(upList);
            }
            lastList = upList;
        }
        t = l.peek(0);
    }
    
    return res;
}

// @finished
ASTreePtr Parser::expectBlock(Lexer& l) {
    TokenPtr tp = l.peek(0);
    if (tp->isEOF())
        throw SandException("Parsing end of file", tp);

    //ASTListPtr res = makeASTList();
    BlockStmntPtr res = makeBlockStmnt();

    // left bracket 
    TokenPtr tlb = l.read();
    if (!tlb->isIdentifier() || tlb->getText() != "{")
        throw SandException("Missing left bracket in block", tlb);
    
    // statement
    TokenPtr t = l.peek(0);
    if (t->isIdentifier() && t->getText() == "}") {
        l.read();
        //return makeASTList();
        return res;
    }
    while (!(t->isIdentifier() && t->getText() == "}")) {
        res->add(parse(l));
        t = l.peek(0);
    }

    // right bracket
    TokenPtr trb = l.read();
    if (!trb->isIdentifier() || trb->getText() != "}")
        throw SandException("Missing right bracket in block", trb);

    //if (res->numChildren() == 1)
    //    return res->child(0);
    return res;
}

// @finished
ASTreePtr Parser::expectIf(Lexer& l) {
    IfStmntPtr ip = makeIfStmnt();

    // If identifier
    TokenPtr tIf = l.read();
    if (!tIf->isIdentifier() || tIf->getText() != "if")
        throw SandException("Not a if identifier", tIf);

    // Left parenthesis
    TokenPtr tlp = l.read();
    if (!tlp->isIdentifier() || tlp->getText() != "(")
        throw SandException("Missing left parenthesis in if statement", tlp);

    // Expression
    ASTreePtr cond = expectExpr(l);
    ip->add(cond);

    // Right parenthesis
    TokenPtr trp = l.read();
    if (!trp->isIdentifier() || trp->getText() != ")")
        throw SandException("Missing right parenthesis in if loop", trp);

    // Block
    TokenPtr t1 = l.peek(0);
    if (t1->isIdentifier() && t1->getText() == "{")
        ip->add(expectBlock(l));
    else
        ip->add(parse(l));

    // Optional else block
    TokenPtr opt = l.peek(0);
    if (opt->isIdentifier() && opt->getText() == "else") {
        l.read();
        TokenPtr t2 = l.peek(0);
        if (t2->isIdentifier() && t2->getText() == "{")
            ip->add(expectBlock(l));
        else
            ip->add(parse(l));
    }

    return ip;
}

// @finished
ASTreePtr Parser::expectWhile(Lexer& l) {
    WhileStmntPtr wp = makeWhileStmnt();
    
    // While identifier
    TokenPtr tWhile = l.read();
    if (!tWhile->isIdentifier() || tWhile->getText() != "while")
        throw SandException("Not a while identifier", tWhile);

    // Left parenthesis
    TokenPtr tlp = l.read();
    if (!tlp->isIdentifier() || tlp->getText() != "(")
        throw SandException("Missing left parenthesis in while loop", tlp);

    // Expression
    wp->add(expectExpr(l));

    // Right parenthesis
    TokenPtr trp = l.read();
    if (!trp->isIdentifier() || trp->getText() != ")")
        throw SandException("Missing right parenthesis in while loop", trp);

    // Block
    TokenPtr t = l.peek(0);
    if (t->isIdentifier() && t->getText() == "{")
        wp->add(expectBlock(l));
    else
        wp->add(parse(l));

    return wp;
}

ASTreePtr Parser::expectFunc(Lexer& l)
{
    TokenPtr t = l.peek(0);
    if (t->isEOF())
        throw SandException("Parsing end of file", t);
    
    FuncStmntPtr f;
    // function name
    if (t->isIdentifier() && reserved.find(t->getText()) == reserved.end())
        f = makeFuncStmnt(makeASTLeaf(l.read()));
    else
        throw SandException("Illegal function name", t);

    // Left parenthesis
    t = l.peek(0);
    if (t->isIdentifier() && t->getText() == "(")
        l.read();
    else
        throw SandException("Missing left parenthesis in function call", t);

    // Test if no parameter
    t = l.peek(0);
    if (t->isIdentifier() && t->getText() == ")") {
        l.read();
        return f;
    }

    // Parameters
    while (!t->isIdentifier() || t->getText() != ")") {
        f->add(expectExpr(l));

        t = l.peek(0);

        if (t->isIdentifier() && t->getText() == ",") {
            l.read();
            t = l.peek(0);
        }
        else if (t->isIdentifier() && t->getText() == ")") {
            l.read();
            return f;
        }
        else
            throw SandException("Illegal parameter in function call", t);
    }

    return f;
}

ASTreePtr Parser::expectFuncDef(Lexer& l)
{
    TokenPtr t = l.peek(0);
    if (t->isEOF())
        throw SandException("Parsing end of file", t);
    
    // check "func" specifier
    if (t->isIdentifier() && t->getText() == "func")
        l.read();
    else
        throw SandException("Illegal function definition", t);

    // function name
    FuncDefStmntPtr f = makeFuncDefStmnt(expectFunc(l));
    
    // function body
    f->add(expectBlock(l));

    return f;
}

ASTreePtr Parser::expectReturn(Lexer& l)
{
    TokenPtr t = l.peek(0);
    if (t->isEOF())
        throw SandException("Parsing end of file", t);

    ReturnStmntPtr ret = makeReturnStmnt();
    if (t->isIdentifier() && t->getText() == "return") {
        l.read();
        ret->add(expectExpr(l));
        return ret;
    }
    else
        throw SandException("Improper return statement", t);
}
