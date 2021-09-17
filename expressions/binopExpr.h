//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_BINOPEXPR_H
#define COMPILER21_BINOPEXPR_H

#include "expression.h"
#include "../lib/enumTokens.h"
#include "../tables/symbolTable.h"

class BinopExpr : public Expression {
protected:
private:
public:
    Expression *leftExpr;
    Expression *rightExpr;
    EnumTokens operation;

    BinopExpr(Expression *leftExpr,  EnumTokens operation, Expression *rightExpr);
    NodeResult interpret(SymbolTable& table);
    ~BinopExpr();

};


#endif //COMPILER21_BINOPEXPR_H
