#ifndef ASTLEAF_H
#define ASTLEAF_H

#include "astree.hpp"
#include "../token.hpp"

#define ASTLeafPtr std::shared_ptr<ASTLeaf>
#define makeASTLeaf(t) std::make_shared<ASTLeaf>(t)

class ASTLeaf : public ASTree {
public:
     ASTLeaf(TokenPtr t);
     ASTreePtr child(int i) const override;
     int numChildren() const override;
     std::string location() const override;
     std::string toString() const override;
     //void optimize() override;
     TokenPtr token() const;
     int getCode() const override;
protected:
    TokenPtr t;
};

#endif
