//
// Created by Bram_ on 14/08/2021.
//

#include "idExpr.h"
#include <string>



IdExpr::IdExpr(std::string identifier)
    : identifier {identifier} {

}

IdExpr::~IdExpr() {

}

NodeResult IdExpr::interpret(SymbolTable& table) {
    std::cout << "IdExpr: interpreted start \n";
    NodeResult value = table.retrieveVariable(this->identifier);
    if (table.doesVariableExist(this->identifier) != 0) {
        NodeResult value = table.retrieveVariable(this->identifier);
        return value;
    } else {
        std::cout << "ERROR: UNDEFINED VARIABLE";
        exit(1);
    }
    std::cout << "IdExpr: interpreted stop \n";
}

std::string IdExpr::getIdentifier() {
    return this->identifier;
}
