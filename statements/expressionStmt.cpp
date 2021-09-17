//
// Created by Bram_ on 13/08/2021.
//

#include "expressionStmt.h"
#include <iostream>

ExpressionStmt::ExpressionStmt(Expression *expr)
    : expr{expr} {

}

ExpressionStmt::~ExpressionStmt() {

}

SymbolTable& ExpressionStmt::interpret(SymbolTable& table) {
    std::cout << "ExpressionStmt: interpreted start\n";
    //std::cout << "KLASSETYPE: " << typeid(*this->expr).name() << "\n";
    auto value = this->expr->interpret(table);
    std::cout << "ExpressionStmt: interpreted stop\n";
    return table;
}