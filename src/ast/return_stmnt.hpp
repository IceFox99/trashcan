#ifndef RETURN_STMNT_H
#define RETURN_STMNT_H

#include "astlist.hpp"

#define ReturnStmntPtr std::shared_ptr<ReturnStmnt> 
#define makeReturnStmnt(i) std::make_shared<ReturnStmnt>(i)

class ReturnStmnt : public ASTList {
public:
    ASTreePtr ret() const;
    std::string toString() const override;
    int getCode() const override;
};

#endif
