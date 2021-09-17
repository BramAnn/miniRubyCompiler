//
// Created by Bram_ on 15/08/2021.
//

#ifndef COMPILER21_DEFSTMT_H
#define COMPILER21_DEFSTMT_H

#include "statement.h"
#include "../expressions/expressionList.h"
#include "../expressions/idExpr.h"

class DefStmt : public Statement {
protected:
private:
public:
    Statement *code;
    IdExpr *functionName;
    ExpressionList *functionArgs;

    DefStmt(IdExpr *functionName, ExpressionList *functionArgs, Statement *code );
    ~DefStmt();
};


#endif //COMPILER21_DEFSTMT_H
