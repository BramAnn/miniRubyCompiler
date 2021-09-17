# miniRubyCompiler
Compiler and interpreter that is able to compile and interpret a limited set of ruby instructions

## Requirements:

This program requires flex, bison and c++ version 17+.

## Building:

**make all:** automatically generates lex and bison files and compiles the c program. Produces the executable: *compiler*

## Running:

make all will export the executable to export/compiler.
./export/compiler <input file>

## Supported features:

- Variables: 
  - int
  - bool
- expressions/operations:
  - =, != , &=, +=, -=, *=, /=
  - +, -, *, /
- Statements:
  - if, else, elseif
  - unless
  - then
  - while, do
  - until
  - \<, >, \>=, <=, &&, ||, !