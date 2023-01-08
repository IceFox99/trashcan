#ifndef IF_STMNT_H
#define IF_STMNT_H

#include "astlist.hpp"

#define IfStmntPtr std::shared_ptr<IfStmnt>
#define makeIfStmnt(i) std::make_shared<IfStmnt>(i)

class IfStmnt : public ASTList {
public:
    ASTreePtr condition() const;
    ASTreePtr thenBlock() const;
    ASTreePtr elseBlock() const;
    std::string toString() const override;
    int getCode() const override;
};

#endif
