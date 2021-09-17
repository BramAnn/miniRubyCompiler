//
// Created by Bram_ on 13/08/2021.
//

#include "printStmt.h"

PrintStmt::PrintStmt(Expression *expr)
    : expr {expr} {

}

PrintStmt::~PrintStmt() {

}

SymbolTable& PrintStmt::interpret(SymbolTable& table) {
    NodeResult value = this->expr->interpret(table);

    if (!std::holds_alternative<bool>(value)){
        std::cout << "========== PRINT ========== \n";
        std::cout << std::get<int32_t>(value);
        std::cout << "\n=========================== \n";
    } else {
        if (std::get<bool>(value)) {
            std::cout << "========== PRINT ========== \n";
            std::cout << "true";
            std::cout << "\n=========================== \n";

        } else {
            std::cout << "========== PRINT ========== \n";
            std::cout << "false";
            std::cout << "\n=========================== \n";
        }

    }


    return table;
}
