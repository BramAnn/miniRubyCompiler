//
// Created by Bram_ on 18/08/2021.
//

#ifndef COMPILER21_IDPASSTHROUGHEXPR_H
#define COMPILER21_IDPASSTHROUGHEXPR_H

#include "expression.h"
#include "idExpr.h"
#include "../tables/symbolTable.h"
#include <string>

class IdPassthroughExpr : public Expression {

protected:
private:
public:
    IdExpr *expr;
    std::string identifier;

    IdPassthroughExpr(IdExpr *expr);
    ~IdPassthroughExpr();
    NodeResult interpret(SymbolTable& table);
    std::string getIdentifier();


};


#endif //COMPILER21_IDPASSTHROUGHEXPR_H
