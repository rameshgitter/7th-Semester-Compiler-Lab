%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Token definitions */
#define ARITHMETIC_OP 1
#define RELATIONAL_OP 2
#define LOGICAL_OP 3
#define BITWISE_OP 4
#define ASSIGNMENT_OP 5
#define RESERVED_WORD 6
#define IDENTIFIER 7
#define INTEGER_CONST 8
#define PARENTHESES 9
#define CURLY_BRACES 10
#define LEXICAL_ERROR 11

/* Error types */
#define ERR_INVALID_CHAR 1
#define ERR_LONG_IDENTIFIER 2
#define ERR_LONG_NUMBER 3
#define ERR_UNMATCHED_STRING 4
#define ERR_SPELLING_ERROR 5
#define ERR_INVALID_NUMBER 6

int line_number = 1;
int token_count = 0;
int error_count = 0;

/* Maximum lengths */
#define MAX_IDENTIFIER_LENGTH 31
#define MAX_NUMBER_LENGTH 10

/* Function prototypes */
void print_token(int token_type, char* token_value, char* description);
void print_error(int error_type, char* token_value);
int is_reserved_word(char* word);
int check_spelling_similarity(char* word);

/* Reserved words array */
char* reserved_words[] = {"int", "float", "char", "for", "do", "while", "if", "else"};
int num_reserved_words = 8;
%}

/* Regular expression definitions */
letter          [a-zA-Z_]
digit           [0-9]
identifier      {letter}({letter}|{digit})*
integer         {digit}+
whitespace      [ \t]+
newline         \n

/* Arithmetic operators */
arithmetic      [+\-*/]

/* Relational operators */
relational      (==|!=|<=|>=|<|>)

/* Logical operators */
logical         (&&|\|\||!)

/* Bitwise operators */
bitwise         (&|\||\^|~|<<|>>)

/* Assignment operators */
assignment      (=|\+=|-=|\*=|\/=|%=|&=|\|=|\^=|<<=|>>=)

/* Invalid characters that shouldn't appear in C programs */
invalid_char    [@#$`]

%%

{whitespace}    { /* Ignore whitespace */ }

{newline}       { line_number++; }

{arithmetic}    { 
                    print_token(ARITHMETIC_OP, yytext, "Arithmetic Operator");
                    token_count++;
                }

{relational}    { 
                    print_token(RELATIONAL_OP, yytext, "Relational Operator");
                    token_count++;
                }

{logical}       { 
                    print_token(LOGICAL_OP, yytext, "Logical Operator");
                    token_count++;
                }

{bitwise}       { 
                    print_token(BITWISE_OP, yytext, "Bitwise Operator");
                    token_count++;
                }

{assignment}    { 
                    print_token(ASSIGNMENT_OP, yytext, "Assignment Operator");
                    token_count++;
                }

"("             { 
                    print_token(PARENTHESES, yytext, "Left Parenthesis");
                    token_count++;
                }

")"             { 
                    print_token(PARENTHESES, yytext, "Right Parenthesis");
                    token_count++;
                }

"{"             { 
                    print_token(CURLY_BRACES, yytext, "Left Curly Brace");
                    token_count++;
                }

"}"             { 
                    print_token(CURLY_BRACES, yytext, "Right Curly Brace");
                    token_count++;
                }

{identifier}    {
                    /* Check identifier length */
                    if (strlen(yytext) > MAX_IDENTIFIER_LENGTH) {
                        print_error(ERR_LONG_IDENTIFIER, yytext);
                        error_count++;
                    }
                    /* Check if it's a reserved word */
                    else if (is_reserved_word(yytext)) {
                        print_token(RESERVED_WORD, yytext, "Reserved Word");
                        token_count++;
                    }
                    else {
                        print_token(IDENTIFIER, yytext, "Identifier");
                        token_count++;
                    }
                }

{integer}       {
                    /* Check number length */
                    if (strlen(yytext) > MAX_NUMBER_LENGTH) {
                        print_error(ERR_LONG_NUMBER, yytext);
                        error_count++;
                    }
                    else {
                        print_token(INTEGER_CONST, yytext, "Integer Constant");
                        token_count++;
                    }
                }

\"[^\"]*\"      {
                    /* Matched string - this is valid, but we're not processing strings in this analyzer */
                    /* Just ignore for now */
                }

\"[^\"]*        {
                    /* Unmatched string */
                    print_error(ERR_UNMATCHED_STRING, yytext);
                    error_count++;
                }

[0-9]+{letter}+[0-9]*{letter}* {
                    /* Invalid number format (like 12abc34) */
                    print_error(ERR_INVALID_NUMBER, yytext);
                    error_count++;
                }

{digit}+{invalid_char}+{digit}* {
                    /* Numbers with invalid characters (like 12$34) */
                    print_error(ERR_INVALID_NUMBER, yytext);
                    error_count++;
                }

{letter}({letter}|{digit})*{invalid_char}+({letter}|{digit})* {
                    /* Identifiers with invalid characters */
                    print_error(ERR_INVALID_CHAR, yytext);
                    error_count++;
                }

{invalid_char}  {
                    /* Single invalid characters */
                    print_error(ERR_INVALID_CHAR, yytext);
                    error_count++;
                }

[a-zA-Z]+       {
                    /* Check for possible spelling errors in identifiers/keywords */
                    if (check_spelling_similarity(yytext)) {
                        print_error(ERR_SPELLING_ERROR, yytext);
                        error_count++;
                    }
                    else {
                        /* Treat as identifier if length is valid */
                        if (strlen(yytext) > MAX_IDENTIFIER_LENGTH) {
                            print_error(ERR_LONG_IDENTIFIER, yytext);
                            error_count++;
                        }
                        else {
                            print_token(IDENTIFIER, yytext, "Identifier");
                            token_count++;
                        }
                    }
                }

.               {
                    /* Any other character */
                    printf("WARNING: Unrecognized character '%s' at line %d\n", yytext, line_number);
                }

%%

/* Function to check if a word is a reserved word */
int is_reserved_word(char* word) {
    for (int i = 0; i < num_reserved_words; i++) {
        if (strcmp(word, reserved_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Function to check spelling similarity with reserved words */
int check_spelling_similarity(char* word) {
    /* Simple check for common misspellings */
    char* common_misspellings[] = {"itn", "flot", "chr", "fi", "esle", "wile", "od"};
    int num_misspellings = 7;
    
    for (int i = 0; i < num_misspellings; i++) {
        if (strcmp(word, common_misspellings[i]) == 0) {
            return 1;
        }
    }
    
    /* Check for single character differences with reserved words */
    for (int i = 0; i < num_reserved_words; i++) {
        int len1 = strlen(word);
        int len2 = strlen(reserved_words[i]);
        
        /* If lengths differ by more than 1, skip */
        if (abs(len1 - len2) > 1) continue;
        
        int differences = 0;
        int min_len = (len1 < len2) ? len1 : len2;
        
        /* Count character differences */
        for (int j = 0; j < min_len; j++) {
            if (word[j] != reserved_words[i][j]) {
                differences++;
            }
        }
        
        /* Add length difference */
        differences += abs(len1 - len2);
        
        /* If only one difference, it's likely a spelling error */
        if (differences == 1) {
            return 1;
        }
    }
    
    return 0;
}

/* Function to print tokens */
void print_token(int token_type, char* token_value, char* description) {
    printf("TOKEN: %-20s | VALUE: %-15s | TYPE: %d | LINE: %d\n", 
           description, token_value, token_type, line_number);
}

/* Function to print errors */
void print_error(int error_type, char* token_value) {
    printf("ERROR: ");
    switch (error_type) {
        case ERR_INVALID_CHAR:
            printf("Invalid character(s) in token");
            break;
        case ERR_LONG_IDENTIFIER:
            printf("Identifier exceeds maximum length (%d)", MAX_IDENTIFIER_LENGTH);
            break;
        case ERR_LONG_NUMBER:
            printf("Number exceeds maximum length (%d)", MAX_NUMBER_LENGTH);
            break;
        case ERR_UNMATCHED_STRING:
            printf("Unmatched string literal");
            break;
        case ERR_SPELLING_ERROR:
            printf("Possible spelling error in keyword/identifier");
            break;
        case ERR_INVALID_NUMBER:
            printf("Invalid number format");
            break;
    }
    printf(" | VALUE: %-15s | LINE: %d\n", token_value, line_number);
}

int main() {
    printf("=== LEXICAL ANALYZER WITH ERROR DETECTION ===\n");
    printf("Processing input...\n\n");
    
    yylex();
    
    printf("\n=== ANALYSIS SUMMARY ===\n");
    printf("Total tokens recognized: %d\n", token_count);
    printf("Total errors found: %d\n", error_count);
    printf("Total lines processed: %d\n", line_number);
    
    if (error_count == 0) {
        printf("✓ No lexical errors found!\n");
    } else {
        printf("⚠ Lexical errors detected. Please review the output above.\n");
    }
    
    return 0;
}

int yywrap() {
    return 1;
}
