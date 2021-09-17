//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_WHILESTMT_H
#define COMPILER21_WHILESTMT_H

#include "statement.h";
#include "../expressions/expression.h"
#include "../tables/symbolTable.h"

class WhileStmt : public Statement {
protected:
private:
public:

    Expression *condition;
    Statement *stmt;

    WhileStmt(Expression *condition, Statement *stmt);

    ~WhileStmt();

    SymbolTable& interpret(SymbolTable& table);

};


#endif //COMPILER21_WHILESTMT_H
