#ifndef BREAK_STMNT_H
#define BREAK_STMNT_H

#include "astleaf.hpp"

#define BreakStmntPtr std::shared_ptr<BreakStmnt>
#define makeBreakStmnt(i) std::make_shared<BreakStmnt>(i)

class BreakStmnt : public ASTLeaf {
public:
    BreakStmnt(int line);
    int getCode() const override;
};

#endif
