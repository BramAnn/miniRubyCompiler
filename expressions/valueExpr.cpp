//
// Created by Bram_ on 14/08/2021.
//

#include "valueExpr.h"
#include <string>
#include <iostream>
#include "../tables/symbolTable.h"



ValueExpr::ValueExpr(int32_t int_val)
    : value {int_val}{

}

ValueExpr::ValueExpr(bool bool_val)
    : value {bool_val} {
}

NodeResult ValueExpr::interpret(SymbolTable& table) {
    std::cout << "ValueExpr: interpreting start \n";
    std::cout << "ValueExpr: interpreting stop \n";
    return this->value;
}

ValueExpr::~ValueExpr() {

}