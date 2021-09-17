//
// Created by Bram_ on 13/08/2021.
//

#include "compoundStmt.h"
#include <iostream>

CompoundStmt::CompoundStmt(Statement *stmt_1, Statement *stmt_2)
    : stmt_1 {stmt_1}
    , stmt_2 {stmt_2} {
    //std::cout << "KLASSETYPE1: " << typeid(*this->stmt_1).name() << "\n";
    //std::cout << "KLASSETYPE2: " << typeid(*this->stmt_2).name() << "\n";

}

CompoundStmt::~CompoundStmt() {

}

SymbolTable& CompoundStmt::interpret(SymbolTable& table){

    this->stmt_1->interpret(table);
//    std::cout << "KLASSETYPE: " << typeid(*this->stmt_2).name() << "\n";
    this->stmt_2->interpret(table);

//    std::cout << "COMPSTMT: interpreted stop\n";
    return table;
}