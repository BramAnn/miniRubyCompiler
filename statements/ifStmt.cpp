//
// Created by Bram_ on 13/08/2021.
//

#include "ifStmt.h"


IfStmt::IfStmt(Expression *condition, Statement *true_stmt, Statement *false_stmt)
    : condition {condition}
    , true_stmt {true_stmt}
    , false_stmt {false_stmt} {

}

IfStmt::~IfStmt() {

}

SymbolTable& IfStmt::interpret(SymbolTable &table) {
    const auto boolCondition = this->condition->interpret(table);
    const bool boolCond = std::visit([](auto&& arg) {
        return bool(arg);
    }, boolCondition);


    if (boolCond) {
        this->true_stmt->interpret(table);
    } else if (this->false_stmt){
        this->false_stmt->interpret(table);
    }

    return table;
}