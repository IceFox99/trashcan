#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast/astree.hpp"
#include "ast/astleaf.hpp"
#include "ast/assign_stmnt.hpp"
#include "ast/expr_stmnt.hpp"
#include "ast/funcdef_stmnt.hpp"
#include "ast/block_stmnt.hpp"
#include <unordered_map>

#define VarStack std::unordered_map<std::string, BasePtr>
#define FuncStack std::unordered_map<std::string, FuncDefStmntPtr>

class Interpreter {
public:
    void inter(ASTreePtr p);
private:
    BasePtr eval(ASTreePtr t);
    bool isTrue(ASTreePtr c);
    //ASTreePtr inlPrim(FuncStmntPtr fsp, FuncDefStmntPtr fdsp, ASTreePtr p, bool useRet, bool* addBreak = nullptr);
    ASTreePtr inlPrim(FuncStmntPtr fsp, FuncDefStmntPtr fdsp, ASTreePtr p, bool useRet, BlockStmntPtr bsp);
    void inlStat(BlockStmntPtr bsp, int* b_index, ASTreePtr p);
    void inlStat(BlockStmntPtr bsp, int* b_index, ASTreePtr p, bool useRet, ASTreePtr other = nullptr, int other_index = 0);
    //void inlStat(BlockStmntPtr bsp, int* b_index, FuncStmntPtr fsp, FuncDefStmntPtr fdsp, int fd_index, bool keepRet);

    VarStack vars; // Variables for global namespace
    //std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<int, BasePtr>>> funcVars; // Variables for function namespace
    std::unordered_map<std::string, std::unordered_map<int, std::unordered_map<std::string, BasePtr>>> funcVars; // Variables for function namespace
    VarStack retVars; // Variables for function return value
    FuncStack funcs; // Function block statement for each function

    // flags for function scope
    unsigned depth = 0; // namespace flag
    std::string currFuncName;
    bool isReturned = false;

    // flags for while statement
    std::vector<std::pair<std::string, bool> > whileFlags; // first is while label, second is break flag
    
    // flag for naming temporary variables
    int counter = 0;
};

#endif
