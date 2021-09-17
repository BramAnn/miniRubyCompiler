//
// Created by Bram_ on 16/08/2021.
//

#ifndef COMPILER21_LITERALEXPR_H
#define COMPILER21_LITERALEXPR_H

#include "expression.h"
#include "../tables/symbolTable.h"

class LiteralExpr : public Expression{

protected:
private:
public:
    Expression *expr;

    LiteralExpr(Expression *expr);
    ~LiteralExpr();
    NodeResult interpret(SymbolTable& table);

};


#endif //COMPILER21_LITERALEXPR_H
