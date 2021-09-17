//
// Created by Bram_ on 13/08/2021.
//

#include "symbolTable.h"


SymbolTable::SymbolTable() {

}

SymbolTable::~SymbolTable() {

}

void SymbolTable::insertVariable(std::string id, NodeResult value) {
    this->variableTable.insert_or_assign(id, value);
}

NodeResult SymbolTable::retrieveVariable(std::string id) {
    NodeResult result = this->variableTable.find(id)->second;
    return result;
}

int SymbolTable::doesVariableExist(std::string id) {
    return this->variableTable.count(id);
}