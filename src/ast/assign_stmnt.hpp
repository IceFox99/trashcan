#ifndef ASSIGN_STMNT_H
#define ASSIGN_STMNT_H

#include "astlist.hpp"

#define AssignStmntPtr std::shared_ptr<AssignStmnt>
#define makeAssignStmnt(i) std::make_shared<AssignStmnt>(i)

class AssignStmnt : public ASTList {
public:
    //AssignStmnt();
    //AssignStmnt(ASTreePtrVec c);
    ASTreePtr var() const;
    ASTreePtr value() const;
    std::string toString() const override;
    int getCode() const override;
};

#endif
