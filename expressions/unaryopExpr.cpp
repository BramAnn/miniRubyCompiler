//
// Created by Bram_ on 22/08/2021.
//

#include "unaryopExpr.h"


UnaryopExpr::UnaryopExpr(EnumTokens operation, Expression *expr)
    : operation{operation}
    , expr {expr}{

}

UnaryopExpr::~UnaryopExpr() {

}

NodeResult UnaryopExpr::interpret(SymbolTable &table) {
    NodeResult resultExpr = this->expr->interpret(table);

    if (std::holds_alternative<int>(resultExpr) && (operation == EnumTokens::NOT)) {
        std::cout << "ERROR: TRYING TO UNARY OPERAND NOT ON INTEGER";
        exit(1);
    }
    if (std::holds_alternative<bool>(resultExpr) && ( operation == EnumTokens::MINUS)) {
        std::cout << "ERROR: TRYING TO UNARY OPERAND MINUS ON BOOLEAN";
        exit(1);
    }

    switch (operation) {
        case EnumTokens::MINUS:
            return std::get<int32_t>(resultExpr) * -1;
            break;
        case EnumTokens::NOT:
            return !std::get<bool >(resultExpr);
            break;
        default:
            break;
    }
}