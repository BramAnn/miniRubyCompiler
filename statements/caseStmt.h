//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_CASESTMT_H
#define COMPILER21_CASESTMT_H

#include "statement.h"
#include "../expressions/expression.h"
#include "whenStmt.h"

class CaseStmt {
protected:
private:
public:
    Expression *condition;
    WhenStmt *whenStmt;

    CaseStmt(Expression *condition, WhenStmt *whenStmt)
        : condition {condition}
        , whenStmt {whenStmt} {

    }

    ~CaseStmt() {

    }
};


#endif //COMPILER21_CASESTMT_H
