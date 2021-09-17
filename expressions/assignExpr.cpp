//
// Created by Bram_ on 17/08/2021.
//

#include "assignExpr.h"



AssignExpr::AssignExpr(IdExpr *identifier, EnumTokens operation, Expression *expr)
    : identifier {identifier}
    , operation {operation}
    , expr {expr} {

}

AssignExpr::~AssignExpr(){

}

NodeResult AssignExpr::interpret(SymbolTable& table) {
    std::cout << "AssignExpr: interpret start \n";
    const auto value = this->expr->interpret(table);

    NodeResult newValue;

    if (operation == EnumTokens::ASSIGN) {
        table.insertVariable(this->identifier->identifier, value);
//    } else if (operation == EnumTokens::ANDASSIGN ) {
//        if (std::holds_alternative<bool>(value)) {
//            if (std::get<bool>(value)) {
//                table.insertVariable(this->identifier->identifier, value);
//            }
//        } else {
//            if (std::get<int32_t>(value)){
//                table.insertVariable(this->identifier->identifier, value);
//            }
//        }
//    } else if (operation == EnumTokens::ORASSIGN)    {
//        if (std::holds_alternative<bool>(value)) {
//            if (!std::get<bool>(value)) {
//                table.insertVariable(this->identifier->identifier, value);
//            }
//        } else {
//            if (!std::get<int32_t>(value)){
//                table.insertVariable(this->identifier->identifier, value);
//            }
//        }
    }else {
        const auto currentValue = table.retrieveVariable(this->identifier->identifier);
        if (std::holds_alternative<bool>(value) || std::holds_alternative<bool>(currentValue)) {
            std::cout << "ERROR: TRYING TO BINOP ASSIGN ON BOOLEANS";
            exit(1);
        }

        switch(operation) {
            case EnumTokens::PLUSASSIGN:
                newValue = std::get<int32_t>(currentValue) + std::get<int32_t>(value);
                break;
            case EnumTokens::MINUSASSIGN:
                newValue = std::get<int32_t>(currentValue) - std::get<int32_t>(value);
                break;
            case EnumTokens::MULASSIGN:
                newValue = std::get<int32_t>(currentValue) * std::get<int32_t>(value);
                break;
            case EnumTokens::DIVASSIGN:
                int curVal = std::get<int32_t>(currentValue);
                int val = std::get<int32_t>(value);

                if (val == 0) {
                    std::cout << "ERROR: DIVIDING BY ZERO";
                    exit(1);
                }

                newValue =  curVal / val ;
                break;
        }
        table.insertVariable(this->identifier->identifier, newValue);

    }



    std::cout << "AssignExpr: interpret stop \n";
    return value;
}
