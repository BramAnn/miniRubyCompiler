//
// Created by Bram_ on 6/08/2021.
//

#include "compiler.h"
#include <cstring>
#include <iostream>



bool debugFlag = false;
std::string inputFile;

int main(int argc, char *argv[]) {
    debugFlag = true;
    if (argc >= 1) {
        std::cout << "Setting inputfile: ";
        inputFile = argv[1];
        std::cout << inputFile;
        std::cout << "\n";
    } else {
        std::cout << "missing input file";
        return 1;
    }
    SymbolTable table;
    Compiler com(inputFile);
    com.start();
    Statement *rootNode = com.get_root();
    rootNode->interpret(table);
    return 0;
}
