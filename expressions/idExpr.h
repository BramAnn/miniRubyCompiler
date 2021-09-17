//
// Created by Bram_ on 14/08/2021.
//

#ifndef COMPILER21_IDEXPR_H
#define COMPILER21_IDEXPR_H

#include "expression.h"
#include "../tables/symbolTable.h"
#include <string>

class IdExpr : public Expression {
protected:
private:
public:
    std::string identifier;

    IdExpr(std::string identifier);
    ~IdExpr();

    NodeResult interpret(SymbolTable& table);
    std::string getIdentifier();
};


#endif //COMPILER21_IDEXPR_H
