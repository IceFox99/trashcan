#ifndef EXPR_STMNT_H
#define EXPR_STMNT_H

#include "astlist.hpp"

#define ExprStmntPtr std::shared_ptr<ExprStmnt>
#define makeExprStmnt(i) std::make_shared<ExprStmnt>(i)

class ExprStmnt : public ASTList {
public:
    ASTreePtr left() const;
    ASTreePtr op() const;
    ASTreePtr right() const;
    int getCode() const override;
};

#endif
