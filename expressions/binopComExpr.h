//
// Created by Bram_ on 19/08/2021.
//

#ifndef COMPILER21_BINOPCOMEXPR_H
#define COMPILER21_BINOPCOMEXPR_H

#include "expression.h"
#include "../lib/enumTokens.h"
#include "../tables/symbolTable.h"

class BinopComExpr : public Expression {

protected:
private:
public:
    Expression *leftExpr;
    Expression *rightExpr;
    EnumTokens operation;

    BinopComExpr(Expression *leftExpr, EnumTokens operation, Expression *rightExpr);
    ~BinopComExpr();
    NodeResult interpret(SymbolTable& table) ;

};


#endif //COMPILER21_BINOPCOMEXPR_H
