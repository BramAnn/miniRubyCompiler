//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_WHENSTMT_H
#define COMPILER21_WHENSTMT_H

#include "statement.h"
#include "expressions/expression.h"

class WhenStmt : public  Statement{

protected:
private:
public:
    Expression *condition;
    Statement *isTrue_stmt;
    Statement *goto_stmt;

    WhenStmt(Expression *condition, Statement *isTrue_stmt, Statement *goto_stmt)
        : condition {condition}
        , isTrue_stmt {isTrue_stmt}
        , goto_stmt {goto_stmt} {

    }

    ~WhenStmt() {

    }

};


#endif //COMPILER21_WHENSTMT_H
