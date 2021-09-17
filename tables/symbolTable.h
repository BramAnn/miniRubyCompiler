//
// Created by Bram_ on 13/08/2021.
//

#ifndef COMPILER21_SYMBOLTABLE_H
#define COMPILER21_SYMBOLTABLE_H

#include <iostream>
#include <optional>
#include <variant>
#include <map>

using NodeResult = std::variant<int32_t, bool>;

class SymbolTable {
protected:

private:
    std::map<std::string, NodeResult> variableTable;
    std::map<std::string, NodeResult> functionTable;


public:
    SymbolTable();
    ~SymbolTable();
    void insertVariable(std::string id, NodeResult value);
    NodeResult retrieveVariable(std::string id);
    int doesVariableExist(std::string id);

};


#endif //COMPILER21_SYMBOLTABLE_H
