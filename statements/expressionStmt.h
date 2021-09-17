//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_EXPRESSIONSTMT_H
#define COMPILER21_EXPRESSIONSTMT_H

#include "statement.h"
#include "../expressions/expression.h"
#include "../tables/symbolTable.h"

class ExpressionStmt : public Statement {
protected:
private:
public:
    Expression *expr;
    ExpressionStmt(Expression *expr);
    ~ExpressionStmt();
    SymbolTable& interpret(SymbolTable& table);
};



#endif //COMPILER21_EXPRESSIONSTMT_H
