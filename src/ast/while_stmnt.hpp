#ifndef WHILE_STMNT_H
#define WHILE_STMNT_H

#include "astlist.hpp"

#define WhileStmntPtr std::shared_ptr<WhileStmnt>
#define makeWhileStmnt(i) std::make_shared<WhileStmnt>(i)

class WhileStmnt : public ASTList {
public:
    ASTreePtr condition() const;
    ASTreePtr body() const;
    std::string toString() const override;
    int getCode() const override;

    void setLabel(const std::string& str);
    std::string getLabel() const;
private:
    std::string label = "";
};

#endif
