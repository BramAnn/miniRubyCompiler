//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_UNTILSTMT_H
#define COMPILER21_UNTILSTMT_H

#include "statement.h"
#include "../expressions/expression.h"

class UntilStmt : public Statement {
protected:
private:
public:
    Expression *condition;
    Statement *stmt;

    UntilStmt(Expression *condition, Statement *stmt);

    ~UntilStmt();

    SymbolTable& interpret(SymbolTable& table);

};


#endif //COMPILER21_UNTILSTMT_H
