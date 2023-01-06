#ifndef FUNC_STMNT_H
#define FUNC_STMNT_H

#include "astlist.hpp"

#define FuncStmntPtr std::shared_ptr<FuncStmnt>
#define makeFuncStmnt(i) std::make_shared<FuncStmnt>(i)
#define InFuncStmntPtr std::shared_ptr<InFuncStmnt>
#define makeInFuncStmnt(i) std::make_shared<InFuncStmnt>(i)

class FuncStmnt : public ASTList {
public:
    // child(0) is function name, child(1) to child(n - 1) is parameters
    FuncStmnt() = default;
    FuncStmnt(ASTreePtr p);
    FuncStmnt(const FuncStmnt& fs) = default;
    std::string getFuncName() const;
    std::string toString() const override;
    int getCode() const override;
};

// Inline function statement
class InFuncStmnt : public FuncStmnt {
public:
    InFuncStmnt(FuncStmntPtr p);
    int getCode() const override;
    std::string toString() const override;
};

#endif
