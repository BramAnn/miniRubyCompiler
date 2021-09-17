%{
/*
ruby.lex: lex-file for ruby
*/
#include "../base.h"
#include "../statements/statement.h"
#include "../expressions/expression.h"
#include "../expressions/idExpr.h"
#include "../expressions/expressionList.h"
#include "y.tab.h"

  /* Keep track of current position of lex for error messages, i.e.
     the position just *after* the last token read */
  int line_nr = 1;
  int col_nr = 1;

  int lexLine = 1;
  int tokPos = 0;
  int lexPos = 1;

  void adjust() {
      tokPos = lexPos;
      lexPos += yyleng;
  }

%}
%option nounput yylineno

%%


";"                       {adjust(); return SEMICOLON;};

"undef"                   {adjust(); return UNDEF;};
"def"                     {adjust(); return DEF;};

"("                       {adjust(); return LPAREN;};
")"                       {adjust(); return RPAREN;};

"end"                     {adjust(); return END;};
"return"                  {adjust(); return RETURN;};

"elsif"                   {adjust(); return ELSIF;};
"if"                      {adjust(); return IF;};
"then"                    {adjust(); return THEN;};
"else"                    {adjust(); return ELSE;};

"unless"                  {adjust(); return UNLESS;};

"while"                   {adjust(); return WHILE;};
"do"                      {adjust(); return DO;};

"until"                   {adjust(); return UNTIL;};

"case"                    {adjust(); return CASE;};
"when"                    {adjust(); return WHEN;};

","                       {adjust(); return COMMA;};

"="                       {adjust(); return ASSIGN;};
"+="                      {adjust(); return PLUSASSIGN;};
"-="                      {adjust(); return MINUSASSIGN;};
"*="                      {adjust(); return MULASSIGN;};
"/="                      {adjust(); return DIVASSIGN;};

"&&="                     {adjust(); return ANDASSIGN;};
"||="                     {adjust(); return ORASSIGN;};

"+"                       {adjust(); return PLUS;};
"-"                       {adjust(); return MINUS;};
"*"                       {adjust(); return MUL;};
"/"                       {adjust(); return DIV;};

">"                       {adjust(); return GT;};
">="                      {adjust(); return GE;};
"<"                       {adjust(); return LT;};
"<="                      {adjust(); return LE;};
"=="                      {adjust(); return EQ;};
"!="                      {adjust(); return NE;};

"&&"                      {adjust(); return AND;};
"||"                      {adjust(); return OR;};
"!"                       {adjust(); return NOT;};

"true"                      {adjust();
                            yylval.boolean = true;
                            return BOOLEAN;};

"false"                     {adjust();
                            yylval.boolean = false;
                            return BOOLEAN;};

"print"                     {adjust();
                            return PRINT;};

"\n"                      {lexLine++; tokPos=0; lexPos=1; return SEMICOLON;};
[ \t]                     {lexPos++;};/* ignore whitespace */

[a-zA-Z_][a-zA-Z_0-9]*    { adjust();
                            char* s = (char*) malloc(yyleng+1);
                            strcpy(s,yytext);
                            yylval.id = s;
                            return IDENTIFIER; }

[0-9]*([0-9]|"_")*[0-9]+  { adjust(); yylval.num = atoi(yytext); return INTEGER;}

"#".*                 {};/* ignore comments */

.      {
  printf("=========\n");
  if (yytext[0] < ' '){ /* non-printable char */
    /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@');
  }
  else {
    if (yytext[0] > '~') {
      /* non-printable char printed as octal int padded with zeros, eg \012*/
      /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
    }
    else {
      /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
    }
  }
  /* lex read exactly one char; the illegal one */
  fprintf(stderr," at line %d column %d\n", lexLine, lexPos);
  printf("=========\n");

  //yyterminate();
			       }

%%



/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/
int yywrap(){
  return (1);
}

void yyerror (const char *s) {
	printf("========= SYNTAX ERROR ========\n");
	if (yytext[0] < ' '){ /* non-printable char */
        /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@');
      }
      else {
        if (yytext[0] > '~') {
          /* non-printable char printed as octal int padded with zeros, eg \012*/
          /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
        }
        else {
          /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
        }
      }
      /* lex read exactly one char; the illegal one */
      fprintf(stderr," at line %d column %d\n", lexLine, tokPos);
      //yyterminate();
      	printf("===============================\n");
}

