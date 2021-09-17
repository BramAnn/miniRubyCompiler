statements = statements/statement.cpp statements/compoundStmt.cpp statements/undefStmt.cpp statements/defStmt.cpp statements/returnStmt.cpp statements/expressionStmt.cpp statements/emptyStmt.cpp statements/printStmt.cpp statements/ifStmt.cpp statements/unlessStmt.cpp statements/whileStmt.cpp statements/untilStmt.cpp
expressions = expressions/expression.cpp expressions/binopExpr.cpp expressions/unaryopExpr.cpp expressions/binopComExpr.cpp expressions/idExpr.cpp expressions/valueExpr.cpp expressions/literalExpr.cpp expressions/assignExpr.cpp expressions/idPassthroughExpr.cpp
tables = tables/symbolTable.cpp

compiler: lex.yy.c y.tab.c
	g++ -g base.cpp $(statements) $(expressions) $(tables) generated/lex.yy.c generated/y.tab.c main.cpp lexer.cpp -w -ll -o export/compiler -std=c++17

all: lex.yy.c y.tab.c
	g++ -g base.cpp $(statements) $(expressions) $(tables) generated/lex.yy.c generated/y.tab.c main.cpp compiler.cpp -w -ll -o export/compiler -std=c++17

lex.yy.c: y.tab.c
	lex -o generated/lex.yy.c lib/ruby.l

y.tab.c:
	bison -v -o generated/y.tab.c -d lib/ruby.grm

clean:
	rm -rf generated/lex.yy.c generated/y.tab.c generated/y.tab.h export/compiler export/compiler.dSYM