#ifndef FUNC_STMNT_H
#define FUNC_STMNT_H

#include "astlist.hpp"

#define FuncStmntPtr std::shared_ptr<FuncStmnt>
#define makeFuncStmnt(i) std::make_shared<FuncStmnt>(i)

class FuncStmnt : public ASTList {
public:
    // child(0) is function name, child(1) to child(n - 1) is parameters
    FuncStmnt(ASTreePtr p);
    std::string getFuncName() const;
    std::string toString() const override;
    int getCode() const override;
};

#endif
