#ifndef BLOCK_STMNT_H
#define BLOCK_STMNT_H

#include "astlist.hpp"

#define BlockStmntPtr std::shared_ptr<BlockStmnt>
#define makeBlockStmnt std::make_shared<BlockStmnt>

class BlockStmnt : public ASTList {
public:
    int getCode() const override;
};

#endif
