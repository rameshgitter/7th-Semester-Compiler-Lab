/* Lexical Analyzer for Symbol Table Management */
/* File: symbol_table.l */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern int line_number;
%}

%%

"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"double"    { return DOUBLE; }
"void"      { return VOID; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }

[a-zA-Z_][a-zA-Z0-9_]*  { 
    yylval.string = strdup(yytext); 
    return IDENTIFIER; 
}

[0-9]+                  { 
    yylval.number = atoi(yytext); 
    return NUMBER; 
}

[0-9]+\.[0-9]+          { 
    yylval.number = atoi(yytext); 
    return NUMBER; 
}

";"         { return SEMICOLON; }
","         { return COMMA; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"/"         { return DIVIDE; }
"<"         { return LT; }
">"         { return GT; }
"<="        { return LE; }
">="        { return GE; }
"=="        { return EQ; }
"!="        { return NE; }

\n          { line_number++; }
[ \t]+      { /* skip whitespace */ }

"//".*      { /* skip single-line comments */ }

"/*"([^*]|\*+[^*/])*\*+"/"  { 
    /* skip multi-line comments */ 
    int i;
    for (i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') line_number++;
    }
}

.           { 
    printf("Unknown character: %s at line %d\n", yytext, line_number); 
}

%%

int yywrap() {
    return 1;
}
