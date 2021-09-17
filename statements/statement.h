//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_STATEMENT_H
#define COMPILER21_STATEMENT_H

#include "../base.h"
#include "../tables/symbolTable.h"

class Statement : public Base {
protected:
private:
public:
    Statement();
    virtual ~Statement();
    virtual SymbolTable& interpret(SymbolTable& table);
};


#endif //COMPILER21_STATEMENT_H
