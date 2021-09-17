//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_RETURNSTMT_H
#define COMPILER21_RETURNSTMT_H

#include "statement.h"
#include "../expressions/expression.h"
class ReturnStmt : public Statement{
protected:
private:
public:
    Expression *exp;

    ReturnStmt(Expression *exp);

    ~ReturnStmt();
};


#endif //COMPILER21_RETURNSTMT_H
