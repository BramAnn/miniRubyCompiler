//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_IFSTMT_H
#define COMPILER21_IFSTMT_H

#include "statement.h"
#include "../expressions/expression.h"
#include "../tables/symbolTable.h"

class IfStmt : public Statement{
protected:
private:
public:
    Expression *condition;
    Statement *true_stmt, *false_stmt;

    IfStmt(Expression *condition, Statement *true_stmt, Statement *false_stmt = nullptr);

    ~IfStmt();

    SymbolTable& interpret(SymbolTable& table);

};


#endif //COMPILER21_IFSTMT_H
