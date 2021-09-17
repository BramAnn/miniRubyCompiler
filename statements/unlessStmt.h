//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_UNLESSSTMT_H
#define COMPILER21_UNLESSSTMT_H

#include "statement.h"
#include "../expressions/expression.h"
#include "../tables/symbolTable.h"

class UnlessStmt : public Statement{
protected:
private:
public:
    Expression *condition;
    Statement *false_stmt;
    Statement *true_stmt;

    UnlessStmt(Expression *condition, Statement *false_stmt, Statement *true_stmt = nullptr);

    ~UnlessStmt() ;

    SymbolTable& interpret(SymbolTable& table) ;
};


#endif //COMPILER21_UNLESSSTMT_H
