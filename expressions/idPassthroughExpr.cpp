//
// Created by Bram_ on 18/08/2021.
//

#include "idPassthroughExpr.h"


IdPassthroughExpr::IdPassthroughExpr(IdExpr *expr)
    : expr {expr}{

}

IdPassthroughExpr::~IdPassthroughExpr() {

}

NodeResult IdPassthroughExpr::interpret(SymbolTable &table) {
    std::cout << "IdPassthroughExpr: interpreting start \n";
    this->identifier = this->expr->getIdentifier();
    NodeResult value = this->expr->interpret(table);
    std::cout << "IdPassthroughExpr interpreting stop \n";
    return value;
}

std::string IdPassthroughExpr::getIdentifier() {
    return this->identifier;
}
