%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char* yytext;

void yyerror(const char* s);

typedef struct symbol {
    char* name;
    char* type;
    int line;
    struct symbol* next;
} symbol_t;

symbol_t* symbol_table = NULL;

void add_symbol(char* name, char* type, int line);
int symbol_exists(char* name);

%}

%union {
    char* string;
    int number;
}

%token <string> IDENTIFIER
%token <number> NUMBER
%token <string> STRING_LITERAL

%token INT FLOAT CHAR VOID
%token IF ELSE WHILE FOR
%token RETURN
%token MAIN

%token ASSIGN
%token EQ NE LT LE GT GE
%token AND OR NOT
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token INCREMENT DECREMENT

%token SEMICOLON COMMA
%token LPAREN RPAREN
%token LBRACE RBRACE
%token LBRACKET RBRACKET
%token COLON

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT
%right ASSIGN
%nonassoc LOWER_THAN_ELSE

%start program

%type <string> type_specifier
%type <string> primary_expression

%%

program:
    translation_unit
    {
    }
    ;

translation_unit:
    external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
    function_definition
    | declaration
    ;

function_definition:
    declaration_specifiers declarator compound_statement
    {
        printf("Function definition completed at line %d\n", yylineno);
    }
    | declarator compound_statement
    {
        printf("Function definition (no return type) at line %d\n", yylineno);
    }
    ;

declaration:
    declaration_specifiers init_declarator_list SEMICOLON
    ;

declaration_specifiers:
    type_specifier
    ;

type_specifier:
    VOID    { $$ = "void"; }
    | CHAR  { $$ = "char"; }
    | INT   { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    ;

init_declarator_list:
    init_declarator
    | init_declarator_list COMMA init_declarator
    ;

init_declarator:
    declarator
    | declarator ASSIGN assignment_expression
    {
        /* handle initialized declarator like: int a = 5; */
        printf("Initialized declarator at line %d\n", yylineno);
    }
    ;

declarator:
    direct_declarator
    ;

direct_declarator:
    IDENTIFIER
    {
        add_symbol($1, "variable", yylineno);
        printf("Variable declared: %s at line %d\n", $1, yylineno);
    }
    | IDENTIFIER LBRACKET NUMBER RBRACKET
    {
        add_symbol($1, "array", yylineno);
        printf("Array declared: %s[%d] at line %d\n", $1, $3, yylineno);
    }
    | IDENTIFIER LPAREN parameter_list RPAREN
    {
        add_symbol($1, "function", yylineno);
        printf("Function declarator: %s at line %d\n", $1, yylineno);
    }
    | IDENTIFIER LPAREN RPAREN
    {
        add_symbol($1, "function", yylineno);
        printf("Function declarator: %s at line %d\n", $1, yylineno);
    }
    | MAIN LPAREN RPAREN
    {
        printf("Main function declarator at line %d\n", yylineno);
    }
    ;

parameter_list:
    parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;

parameter_declaration:
    declaration_specifiers declarator
    ;

compound_statement:
    LBRACE RBRACE
    | LBRACE block_item_list RBRACE
    ;

block_item_list:
    block_item
    | block_item_list block_item
    ;

block_item:
    declaration
    | statement
    ;

/* Use matched / unmatched statements to resolve dangling-else */
statement:
    matched_statement
    | unmatched_statement
    ;

labeled_statement:
    IDENTIFIER COLON statement
    ;

expression_statement:
    SEMICOLON
    | expression SEMICOLON
    ;

matched_statement:
    compound_statement
    | expression_statement
    | iteration_statement
    | jump_statement
    | IF LPAREN expression RPAREN matched_statement ELSE matched_statement
    {
        printf("If-else statement at line %d\n", yylineno);
    }
    ;

unmatched_statement:
    IF LPAREN expression RPAREN statement
    {
        printf("If statement at line %d\n", yylineno);
    }
    | IF LPAREN expression RPAREN matched_statement ELSE unmatched_statement
    ;

iteration_statement:
    WHILE LPAREN expression RPAREN matched_statement
    {
        printf("While loop at line %d\n", yylineno);
    }
    | FOR LPAREN expression_statement expression_statement RPAREN matched_statement
    {
        printf("For loop at line %d\n", yylineno);
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN matched_statement
    {
        printf("For loop at line %d\n", yylineno);
    }
    | FOR LPAREN declaration expression_statement RPAREN matched_statement
    {
        printf("For loop with declaration at line %d\n", yylineno);
    }
    | FOR LPAREN declaration expression_statement expression RPAREN matched_statement
    {
        printf("For loop with declaration at line %d\n", yylineno);
    }
    ;

jump_statement:
    RETURN SEMICOLON
    {
        printf("Return statement at line %d\n", yylineno);
    }
    | RETURN expression SEMICOLON
    {
        printf("Return statement with value at line %d\n", yylineno);
    }
    ;

expression:
    assignment_expression
    | expression COMMA assignment_expression
    ;

assignment_expression:
    conditional_expression
    | unary_expression assignment_operator assignment_expression
    {
        printf("Assignment at line %d\n", yylineno);
    }
    ;

assignment_operator:
    ASSIGN
    ;

conditional_expression:
    logical_or_expression
    ;

logical_or_expression:
    logical_and_expression
    | logical_or_expression OR logical_and_expression
    ;

logical_and_expression:
    equality_expression
    | logical_and_expression AND equality_expression
    ;

equality_expression:
    relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NE relational_expression
    ;

relational_expression:
    additive_expression
    | relational_expression LT additive_expression
    | relational_expression GT additive_expression
    | relational_expression LE additive_expression
    | relational_expression GE additive_expression
    ;

additive_expression:
    multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;

multiplicative_expression:
    unary_expression
    | multiplicative_expression MULTIPLY unary_expression
    | multiplicative_expression DIVIDE unary_expression
    | multiplicative_expression MODULO unary_expression
    ;

unary_expression:
    postfix_expression
    | INCREMENT unary_expression
    | DECREMENT unary_expression
    | unary_operator unary_expression
    ;

unary_operator:
    PLUS
    | MINUS
    | NOT
    ;

postfix_expression:
    primary_expression
    {
        if ($1 != NULL) {
            if (!symbol_exists($1)) {
                printf("Error: Undeclared variable '%s' used at line %d\n", $1, yylineno);
            }
        }
    }
    | postfix_expression LBRACKET expression RBRACKET
    {
        printf("Array access at line %d\n", yylineno);
    }
    | postfix_expression LPAREN RPAREN
    {
        printf("Function call (no args) at line %d\n", yylineno);
    }
    | postfix_expression LPAREN argument_expression_list RPAREN
    {
        printf("Function call with args at line %d\n", yylineno);
    }
    | postfix_expression INCREMENT
    | postfix_expression DECREMENT
    ;

primary_expression:
    IDENTIFIER { $$ = $1; }
    | NUMBER { $$ = NULL; }
    | STRING_LITERAL { $$ = NULL; }
    | LPAREN expression RPAREN { $$ = NULL; }
    ;

argument_expression_list:
    assignment_expression
    | argument_expression_list COMMA assignment_expression
    ;

%%

void yyerror(const char* s) {
    printf("Syntax Error at line %d: %s near '%s'\n", yylineno, s, yytext);
}

void add_symbol(char* name, char* type, int line) {
    symbol_t* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Warning: Variable '%s' redeclared at line %d (previously declared at line %d)\n", 
                   name, line, current->line);
            return;
        }
        current = current->next;
    }
    
    symbol_t* new_symbol = (symbol_t*)malloc(sizeof(symbol_t));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    new_symbol->line = line;
    new_symbol->next = symbol_table;
    symbol_table = new_symbol;
}

int symbol_exists(char* name) {
    symbol_t* current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print_symbol_table() {
    printf("\n--- Symbol Table ---\n");
    printf("Name\t\tType\t\tLine\n");
    printf("----\t\t----\t\t----\n");
    
    symbol_t* current = symbol_table;
    while (current != NULL) {
        printf("%-15s %-15s %d\n", current->name, current->type, current->line);
        current = current->next;
    }
    printf("-------------------\n");
}

int main() {
    printf("C Subset Syntax Analyzer\n");
    printf("========================\n");
    
    printf("Enter your C code (Ctrl+D to end input):\n");
    /* Pre-populate symbol table with common stdlib functions to avoid false 'undeclared' errors */
    add_symbol("printf", "function", 0);
    add_symbol("scanf", "function", 0);
    add_symbol("puts", "function", 0);
    
    if (yyparse() == 0) {
        printf("\nParsing completed successfully!\n");
        print_symbol_table();
    } else {
        printf("\nParsing failed due to syntax errors.\n");
    }
    
    return 0;
}