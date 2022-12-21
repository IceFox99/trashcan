#ifndef FUNCDEF_STMNT_H
#define FUNCDEF_STMNT_H

#include "astlist.hpp"
#include "func_stmnt.hpp"

#define FuncDefStmntPtr std::shared_ptr<FuncDefStmnt>
#define makeFuncDefStmnt(i) std::make_shared<FuncDefStmnt>(i)

class FuncDefStmnt : public ASTList {
public:
    // child(0) is FuncStmnt, child(1) is BlockStmnt
    FuncDefStmnt(ASTreePtr f);
    ASTreePtr parameters() const;
    ASTreePtr func() const;
    std::string toString() const override;
    int getCode() const override;
};

#endif
