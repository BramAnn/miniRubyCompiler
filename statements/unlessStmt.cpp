//
// Created by Bram_ on 14/08/2021.
//

#include "unlessStmt.h"


UnlessStmt::UnlessStmt(Expression *condition, Statement *false_stmt, Statement *true_stmt)
: condition{condition}
, false_stmt {false_stmt}
, true_stmt {true_stmt} {

}

UnlessStmt::~UnlessStmt() {

}

SymbolTable& UnlessStmt::interpret(SymbolTable &table) {
    const auto value = this->condition->interpret(table);
    const bool condition = std::visit([](auto&& arg){
        return bool(arg);}, value);

    if(!condition){
        this->false_stmt->interpret(table);
    } else if (this->true_stmt) {
        this->true_stmt->interpret(table);
    }
    return table;
}