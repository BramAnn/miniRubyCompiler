//
// Created by Bram_ on 14/08/2021.
//

#include "whileStmt.h"


WhileStmt::WhileStmt(Expression *condition, Statement *stmt)
    : condition{condition}
    , stmt{stmt} {
}

WhileStmt::~WhileStmt(){

}

SymbolTable& WhileStmt::interpret(SymbolTable& table) {
    bool condition;

    do{
        const auto value = this->condition->interpret(table);
        condition = std::visit([](auto&& arg) { return bool(arg); }, value);

        if (condition) {
            this->stmt->interpret(table);
        }
    } while(condition);

    return table;
}

