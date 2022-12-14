#ifndef ASTREE_H
#define ASTREE_H

#include <vector>
#include <memory>
#include <string>
#include "obj.hpp"

class ASTree;

#define ASTreePtr std::shared_ptr<ASTree>
#define ASTreePtrVec std::vector<ASTreePtr>
    
class ASTree {
public:
    ASTree();
    virtual ASTreePtr child(int i) const = 0;
    virtual int numChildren() const = 0;
    virtual std::string location() const = 0;
    virtual std::string toString() const = 0;
    //virtual void optimize() = 0;
    virtual int getCode() const = 0;
    virtual ~ASTree();
};

#endif
