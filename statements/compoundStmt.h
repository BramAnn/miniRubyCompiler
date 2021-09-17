//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_COMPOUNDSTMT_H
#define COMPILER21_COMPOUNDSTMT_H

#include "statement.h"

class CompoundStmt : public Statement {
protected:
private:
public:
    Statement *stmt_1 = NULL;
    Statement *stmt_2 = NULL;

    CompoundStmt(Statement *stmt_1, Statement *stmt_2);
    ~CompoundStmt();
    SymbolTable& interpret(SymbolTable& table);




};


#endif //COMPILER21_COMPOUNDSTMT_H
