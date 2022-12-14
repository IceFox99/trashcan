#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast/astree.hpp"
#include "ast/astleaf.hpp"
#include "ast/assign_stmnt.hpp"
#include "ast/expr_stmnt.hpp"
#include <unordered_map>

class Interpreter {
public:
    void inter(ASTreePtr p);
private:
    BasePtr eval(ASTreePtr t);
    bool isTrue(ASTreePtr c);
    std::unordered_map<std::string, BasePtr> vars;
};

#endif
