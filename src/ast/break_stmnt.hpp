#ifndef BREAK_STMNT_H
#define BREAK_STMNT_H

#include "astleaf.hpp"

#define BreakStmntPtr std::shared_ptr<BreakStmnt>
#define makeBreakStmnt(i, l) std::make_shared<BreakStmnt>(i, l)

class BreakStmnt : public ASTLeaf {
public:
    BreakStmnt(int line, const std::string& label = "");
    int getCode() const override;
    void setLabel(const std::string& str);
    std::string getLabel() const;
    std::string toString() const override;
private:
    std::string label;
};

#endif
