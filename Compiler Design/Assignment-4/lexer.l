%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}

%%

"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
"void"          { return VOID; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"main"          { return MAIN; }

"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"%"             { return MODULO; }
"++"            { return INCREMENT; }
"--"            { return DECREMENT; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
":"             { return COLON; }
"]"             { return RBRACKET; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.string = strdup(yytext);
    return IDENTIFIER;
}

[0-9]+ {
    yylval.number = atoi(yytext);
    return NUMBER;
}

[0-9]*\.[0-9]+ {
    yylval.number = atof(yytext);
    return NUMBER;
}

\"[^\"]*\" {
    yylval.string = strdup(yytext);
    return STRING_LITERAL;
}

'[^']' {
    yylval.string = strdup(yytext);
    return STRING_LITERAL;
}

"//"[^\n]*      { }

"/*"([^*]|"*"+[^*/])*"*"+"/" {
    char* ptr = yytext;
    while (*ptr) {
        if (*ptr == '\n') yylineno++;
        ptr++;
    }
}

[ \t]+          { }

\n              { yylineno++; }

.               {
    printf("Lexical Error: Unrecognized character '%c' at line %d\n", yytext[0], yylineno);
    return yytext[0];
}

%%
int yywrap() {
    return 1;
}

