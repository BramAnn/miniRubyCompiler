//
// Created by Bram_ on 14/08/2021.
//

#include "binopExpr.h"
#include "../tables/symbolTable.h"
#include <iostream>

BinopExpr::BinopExpr(Expression *leftExpr, EnumTokens operation, Expression *rightExpr)
    : leftExpr {leftExpr}
    , operation {operation}
    , rightExpr {rightExpr} {
}

BinopExpr::~BinopExpr() {

}

NodeResult BinopExpr::interpret(SymbolTable& table) {
    std::cout << "BinopExpr: interpreted start\n" << std::flush ;
    const auto resultLeft = this->leftExpr->interpret(table);
    const auto resultRight = this->rightExpr->interpret(table);

    if (std::holds_alternative<bool>(resultLeft) || std::holds_alternative<bool>(resultRight)) {
        std::cout << "========== TYPE CHECKING =========\n";
        std::cout << "ERROR: TRYING TO BINOP ON BOOLEANS\n";
        std::cout << "==================================\n";
        exit(1);
    }

    NodeResult resultOperation;

    std::visit([&](auto&& argLeft) {
        std::visit([&](auto&& argRight) {
            using typeLeft = std::decay_t<decltype(argLeft)>;
            using typeRight = std::decay_t<decltype(argRight)>;
            switch (this->operation) {
                case EnumTokens::PLUS:
                    resultOperation = argLeft + argRight;
                    break;
                case EnumTokens::MINUS:
                    resultOperation = argLeft - argRight;
                    break;
                case EnumTokens::MUL:
                    resultOperation = argLeft * argRight;
                    break;
                case EnumTokens::DIV:
                    if (argRight == 0) {
                        std::cout << "ERROR: DIVIDING BY ZERO\n";
                        exit(1);
                    } else {
                        resultOperation = argLeft / argRight;
                    }
                    break;
                default:
                    printf("BINOPEXPR BROKEN DEFAULT CASE");
            }

        }, resultRight);
    }, resultLeft);

    std::cout << "BinopExpr: interpreted end \n" << std::flush;
    std::cout << "BinopExpr calculated value: " << std::get<int32_t>(resultOperation) << "\n";
    return resultOperation;

}
