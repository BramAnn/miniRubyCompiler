//
// Created by Bram_ on 22/08/2021.
//

#ifndef COMPILER21_UNARYOPEXPR_H
#define COMPILER21_UNARYOPEXPR_H

#include "expression.h"
#include "../lib/enumTokens.h"
#include "../tables/symbolTable.h"

class UnaryopExpr : public Expression {

protected:
private:
public:
    EnumTokens operation;
    Expression *expr;

    UnaryopExpr(EnumTokens operation, Expression *expr);
    NodeResult interpret(SymbolTable& table);
    ~UnaryopExpr();
};


#endif //COMPILER21_UNARYOPEXPR_H
