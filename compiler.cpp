//
// Created by Bram_ on 8/08/2021.
//

#include "compiler.h"
#include <iostream>
//#include "generated/lex.yy.c"
//#include "generated/y.tab.c"

extern int yylex();
extern int yylineno;
extern int yyparse();
extern char* yytext;
extern void yyrestart(std::FILE* f);
extern Statement *root;

char *tokens[] = {
        "SEMICOLON", "UNDEF", "DEF", "LPAREN", "RPAREN", "END", "RETURN",
        "INTEGER", "IDENTIFIER", "IF", "THEN", "ELSIF", "ELSE", "UNLESS",
        "WHILE", "DO", "UNTIL", "CASE", "WHEN", "COMMA", "ASSIGN",
        "PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
        "ANDASSIGN", "ORASSIGN", "PLUS", "MINUS", "MUL", "DIV", "GT",
        "GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT", "BOOLEAN"
};


Compiler::Compiler() {
    std::cout << "This is w/o file constructor speaking \n";
}

Compiler::Compiler(const std::string& inputFile) {
    std::cout << "This is file constructor speaking \n";
    this->input = std::fopen(inputFile.c_str(), "r");
    std::cout << "FILEINPUT CONTENT: ", this->input, "\n";
    yyrestart(this->input);
}

void Compiler::lexOnly() {
    std::cout << "Start lexing \n";

    int ntoken, vtoken;

    ntoken = yylex();
    while(ntoken) {
        std::cout << ntoken;
        std::cout << "\n";
        ntoken = yylex();
    }
}
void Compiler::reset() {
    std::rewind(this->input);
    //cmp::parse_flags.Reset();
    //utils::memory::delete_var(root);
}
void Compiler::start() {
    std::cout << "Start parsing \n";
    const int parseResult = yyparse();
}

Statement* Compiler::get_root() const {
    return root;
}
