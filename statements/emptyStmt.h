//
// Created by Bram_ on 17/08/2021.
//

#ifndef COMPILER21_EMPTYSTMT_H
#define COMPILER21_EMPTYSTMT_H

#include "statement.h"
#include "../tables/symbolTable.h"

class EmptyStmt : public Statement{

protected:
private:
public:
    EmptyStmt();
    ~EmptyStmt();
    SymbolTable& interpret(SymbolTable& table);

};


#endif //COMPILER21_EMPTYSTMT_H
