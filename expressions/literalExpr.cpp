//
// Created by Bram_ on 16/08/2021.
//

#include "literalExpr.h"
#include <iostream>


LiteralExpr::LiteralExpr(Expression *expr)
    : expr {expr} {

}

NodeResult LiteralExpr::interpret(SymbolTable& table) {
    std::cout << "LiteralExpr: interpreting start \n";
    NodeResult value = this->expr->interpret(table);
    //std::cout << "LiteralExpr value leaf: " << std::get<int32_t>(value) << "\n";
    return value;
    std::cout << "LiteralExpr: interpreting stop \n";

}

LiteralExpr::~LiteralExpr(){}




