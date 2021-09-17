//
// Created by Bram_ on 8/08/2021.
//

#ifndef COMPILER21_COMPILER_H
#define COMPILER21_COMPILER_H
#include <cstring>
#include <string>
#include "statements/statement.h"


class Compiler {
private:
    std::FILE *input = nullptr;

public:
    Compiler();
    Compiler(const std::string& inputFile);
    Statement* get_root() const;
    void lexOnly();
    void reset();
    void start();
};


#endif //COMPILER21_COMPILER_H
