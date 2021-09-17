//
// Created by Bram_ on 19/08/2021.
//

#include "binopComExpr.h"

BinopComExpr::BinopComExpr(Expression *leftExpr, EnumTokens operation, Expression *rightExpr)
    : leftExpr {leftExpr}
    , operation {operation}
    , rightExpr {rightExpr} {

}

BinopComExpr::~BinopComExpr() {

}

NodeResult BinopComExpr::interpret(SymbolTable &table) {

    std::cout << "BinopExpr: interpreted start\n" << std::flush ;
    const auto resultLeft = this->leftExpr->interpret(table);
    const auto resultRight = this->rightExpr->interpret(table);

//    if (std::holds_alternative<bool>(resultLeft) || std::holds_alternative<bool>(resultRight)) {
//        std::cout << "ERROR: TRYING TO BINOP ON BOOLEANS";
//        exit(1);
//    }

    bool resultOperation;

    std::visit([&](auto&& argLeft) {
        std::visit([&](auto&& argRight) {
            using typeLeft = std::decay_t<decltype(argLeft)>;
            using typeRight = std::decay_t<decltype(argRight)>;
            switch (this->operation) {
                case EnumTokens::GT:
                    if (argLeft > argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::GE:
                    if (argLeft >= argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::LT:
                    if (argLeft < argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::LE:
                    if (argLeft <= argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::EQ:
                    if (argLeft == argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::NE:
                    if (argLeft != argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::AND:
                    if (argLeft && argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                case EnumTokens::OR:
                    if (argLeft || argRight) {
                        resultOperation = true;
                    } else {
                        resultOperation = false;
                    }
                    break;
                default:
                    printf("BINOPCOMPEXPR BROKEN DEFAULT CASE");
            }

            }, resultRight);
        }, resultLeft);

    std::cout << "BinopComExpr: interpreted end \n" << std::flush;
    return resultOperation;

}