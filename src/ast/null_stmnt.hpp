#ifndef NULL_STMNT_H
#define NULL_STMNT_H

#include "astleaf.hpp"

#define NullStmntPtr std::shared_ptr<NullStmnt>
#define makeNullStmnt(i) std::make_shared<NullStmnt>(i)

class NullStmnt : public ASTLeaf {
public:
    NullStmnt(int line);
    int getCode() const override;
};

#endif
