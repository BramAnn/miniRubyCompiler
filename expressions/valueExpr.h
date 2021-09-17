//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_VALUEEXPR_H
#define COMPILER21_VALUEEXPR_H


#include "expression.h"
#include <string>
#include "../tables/symbolTable.h"

class ValueExpr : public Expression {
protected:
private:
public:
    int32_t int_val = NULL;
    bool bool_val = NULL;
    NodeResult value;

    ValueExpr(int32_t int_val);
    ValueExpr(bool bool_val);
    NodeResult interpret(SymbolTable& table);
    ~ValueExpr();
};


#endif //COMPILER21_VALUEEXPR_H
