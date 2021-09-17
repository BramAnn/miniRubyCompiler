//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_PRINTSTMT_H
#define COMPILER21_PRINTSTMT_H

#include <iostream>
#include "../expressions/expression.h"
#include "../tables/symbolTable.h"
#include "statement.h"

class PrintStmt : public Statement {
protected:
private:
public:
    Expression *expr;

    PrintStmt(Expression *expr);
    ~PrintStmt();
    SymbolTable& interpret(SymbolTable& table);
};


#endif //COMPILER21_PRINTSTMT_H
