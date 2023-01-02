#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast/astree.hpp"
#include "ast/astleaf.hpp"
#include "ast/assign_stmnt.hpp"
#include "ast/expr_stmnt.hpp"
#include "ast/funcdef_stmnt.hpp"
#include <unordered_map>

#define VarStack std::unordered_map<std::string, BasePtr>
#define FuncStack std::unordered_map<std::string, FuncDefStmntPtr>

class Interpreter {
public:
    void inter(ASTreePtr p);
private:
    BasePtr eval(ASTreePtr t);
    bool isTrue(ASTreePtr c);

    VarStack vars; // Variables for global namespace
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<int, BasePtr>>> funcVars; // Variables for function namespace
    VarStack retVars; // Variables for function return value
    FuncStack funcs; // Function block statement for each function

    unsigned depth = 0; // namespace flag
    std::string currFuncName;
    bool isReturned = false;
};

#endif
