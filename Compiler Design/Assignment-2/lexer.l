%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Token counter */
int token_count = 0;

/* Function to print tokens */
void print_token(const char* token_type, const char* lexeme) {
    printf("%-20s : %s\n", token_type, lexeme);
    token_count++;
}
%}

/* Regular expression definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
WHITESPACE  [ \t]+
NEWLINE     \n

%%

"int"		{ print_token("RESERVED_WORD", yytext); }
"float"		{ print_token("RESERVED_WORD", yytext); }
"char"		{ print_token("RESERVED_WORD", yytext); }
"for"		{ print_token("RESERVED_WORD", yytext); }
"do"		{ print_token("RESERVED_WORD", yytext); }
"while"		{ print_token("RESERVED_WORD", yytext); }
"if"		{ print_token("RESERVED_WORD", yytext); }
"else"		{ print_token("RESERVED_WORD", yytext); }

"++"		{ print_token("ARITHMETIC_OP", yytext); }
"--"		{ print_token("ARITHMETIC_OP", yytext); }
"+"		{ print_token("ARITHMETIC_OP", yytext); }
"-"		{ print_token("ARITHMETIC_OP", yytext); }
"*"		{ print_token("ARITHMETIC_OP", yytext); }
"/"		{ print_token("ARITHMETIC_OP", yytext); }
"%"		{ print_token("ARITHMETIC_OP", yytext); }

"<="		{ print_token("RELATIONAL_OP", yytext); }
">="		{ print_token("RELATIONAL_OP", yytext); }
"=="		{ print_token("RELATIONAL_OP", yytext); }
"!="		{ print_token("RELATIONAL_OP", yytext); }
"<"		{ print_token("RELATIONAL_OP", yytext); }
">"		{ print_token("RELATIONAL_OP", yytext); }

"&&"		{ print_token("LOGICAL_OP", yytext); }
"||"		{ print_token("LOGICAL_OP", yytext); }
"!"		{ print_token("LOGICAL_OP", yytext); }

"<<"		{ print_token("BITWISE_OP", yytext); }
">>"		{ print_token("BITWISE_OP", yytext); }
"&"		{ print_token("BITWISE_OP", yytext); }
"|"		{ print_token("BITWISE_OP", yytext); }
"^"		{ print_token("BITWISE_OP", yytext); }
"~"		{ print_token("BITWISE_OP", yytext); }

"<<="		{ print_token("ASSIGNMENT_OP", yytext); }
">>="		{ print_token("ASSIGNMENT_OP", yytext); }
"+="		{ print_token("ASSIGNMENT_OP", yytext); }
"-="		{ print_token("ASSIGNMENT_OP", yytext); }
"*="		{ print_token("ASSIGNMENT_OP", yytext); }
"/="		{ print_token("ASSIGNMENT_OP", yytext); }
"%="		{ print_token("ASSIGNMENT_OP", yytext); }
"&="		{ print_token("ASSIGNMENT_OP", yytext); }
"|="		{ print_token("ASSIGNMENT_OP", yytext); }
"^="		{ print_token("ASSIGNMENT_OP", yytext); }
"="		{ print_token("ASSIGNMENT_OP", yytext); }

"("		{ print_token("LEFT_PAREN", yytext); }
")"		{ print_token("RIGHT_PAREN", yytext); }
"{"		{ print_token("LEFT_BRACE", yytext); }
"}"		{ print_token("RIGHT_BRACE", yytext); }
"["		{ print_token("LEFT_BRACKET", yytext); }
"]"		{ print_token("RIGHT_BRACKET", yytext); }
";"		{ print_token("SEMICOLON", yytext); }
","		{ print_token("COMMA", yytext); }

{INTEGER}	{ print_token("INTEGER_CONSTANT", yytext); }
{IDENTIFIER}	{ print_token("IDENTIFIER", yytext); }

{WHITESPACE}	{ /* Skip whitespace */ }
{NEWLINE}	{ /* Skip newlines */ }

.		{ printf("UNKNOWN_TOKEN     : %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main(int argc, char* argv[]) {
    FILE *input_file;
    
    printf("=== C LEXICAL ANALYZER ===\n");
    printf("Analyzing C program for tokens...\n\n");
    
    if (argc > 1) {
        input_file = fopen(argv[1], "r");
        if (!input_file) {
            printf("Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = input_file;
        printf("Input file: %s\n", argv[1]);
    } else {
        printf("Reading from standard input (type your C code):\n");
        printf("Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to end input\n\n");
    }
    
    printf("TOKEN_TYPE           : LEXEME\n");
    printf("----------------------------------------\n");
    
    /* Start lexical analysis */
    yylex();
    
    printf("----------------------------------------\n");
    printf("Total tokens found: %d\n", token_count);
    
    if (argc > 1) {
        fclose(input_file);
    }
    
    return 0;
}