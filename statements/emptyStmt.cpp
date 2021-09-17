//
// Created by Bram_ on 17/08/2021.
//

#include "emptyStmt.h"
#include "iostream"

EmptyStmt::EmptyStmt() {
}
EmptyStmt::~EmptyStmt() {

}

SymbolTable& EmptyStmt::interpret(SymbolTable &table) {
    return table;
}