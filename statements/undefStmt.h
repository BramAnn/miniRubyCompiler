//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_UNDEFSTMT_H
#define COMPILER21_UNDEFSTMT_H

#include "statement.h"
#include "../expressions/idExpr.h"

class UndefStmt : public Statement{
protected:
private:
public:
    IdExpr *idExpr;
    UndefStmt(IdExpr *idExpr);
    ~UndefStmt();
};


#endif //COMPILER21_UNDEFSTMT_H
