//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_EXPRESSION_H
#define COMPILER21_EXPRESSION_H

#include "../base.h"
#include "../tables/symbolTable.h"

class Expression : public Base{
protected:
private:
public:
    Expression() ;
    virtual ~Expression();
    virtual NodeResult interpret(SymbolTable& table);
};


#endif //COMPILER21_EXPRESSION_H
