//
// Created by Bram_ on 17/08/2021.
//

#ifndef COMPILER21_ASSIGNEXPR_H
#define COMPILER21_ASSIGNEXPR_H

#include "../tables/symbolTable.h"
#include "expression.h"
#include "../lib/enumTokens.h"
#include "idExpr.h"
#include <iostream>

class AssignExpr : public Expression {
protected:
private:
public:
    IdExpr *identifier;
    Expression *expr;
    EnumTokens operation;

    AssignExpr(IdExpr *identifier, EnumTokens operation, Expression *expr);
    ~AssignExpr();
    NodeResult interpret(SymbolTable& table);
};


#endif //COMPILER21_ASSIGNEXPR_H
