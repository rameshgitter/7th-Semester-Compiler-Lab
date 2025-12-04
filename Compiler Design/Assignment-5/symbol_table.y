/* Symbol Table Management using YACC */
/* File: symbol_table.y */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Symbol Table Structure */
typedef struct SymbolTable {
    char name[50];
    char datatype[20];
    int scope;
    int line_no;
    struct SymbolTable *next;
} SymbolTable;

/* Global Variables */
SymbolTable *symbol_table_head = NULL;
int current_scope = 0;
int line_number = 1;
char current_datatype[20];

/* Function Declarations */
void yyerror(const char *s);
int yylex();
void insert_symbol(char *name, char *datatype, int scope, int line);
int lookup_symbol(char *name, int scope);
int lookup_symbol_all_scopes(char *name);
void display_symbol_table();
void enter_scope();
void exit_scope();
void remove_scope(int scope);

%}

%union {
    char *string;
    int number;
    struct {
        char *type;
        int is_pointer;
        int is_array;
    } expr_attr;
}

%token <string> IDENTIFIER
%token <number> NUMBER
%token INT FLOAT CHAR DOUBLE VOID
%token IF ELSE WHILE FOR RETURN
%token SEMICOLON COMMA LBRACE RBRACE LPAREN RPAREN
%token ASSIGN PLUS MINUS MULTIPLY DIVIDE
%token LT GT LE GE EQ NE

%type <string> type
%type <expr_attr> expression simple_expression additive_expression term factor

%%

program:
    function_list
    {
        printf("\n=== Symbol Table ===\n");
        display_symbol_table();
    }
    ;

function_list:
    function_list function
    | function
    ;

function:
    type IDENTIFIER LPAREN parameter_list RPAREN
    {
        enter_scope();
        insert_symbol($2, $1, current_scope, line_number);
    }
    compound_statement
    {
        exit_scope();
    }
    ;

parameter_list:
    /* empty */
    | parameter_declaration_list
    ;

parameter_declaration_list:
    parameter_declaration
    | parameter_declaration_list COMMA parameter_declaration
    ;

parameter_declaration:
    type IDENTIFIER
    {
        insert_symbol($2, $1, current_scope, line_number);
    }
    ;

compound_statement:
    LBRACE 
    {
        enter_scope();
    }
    declaration_list statement_list RBRACE
    {
        exit_scope();
    }
    ;

declaration_list:
    /* empty */
    | declaration_list declaration
    ;

declaration:
    type identifier_list SEMICOLON
    | type IDENTIFIER LBRACE NUMBER RBRACE SEMICOLON {
        // Array declaration type checking
        char arr_type[64];
        snprintf(arr_type, sizeof(arr_type), "%s[%d]", $1, $4);
        if (lookup_symbol($2, current_scope) == 1) {
            printf("Error: Array '%s' already declared in this scope at line %d\n", $2, line_number);
        } else {
            insert_symbol($2, arr_type, current_scope, line_number);
            printf("Declared array: %s (type: %s, scope: %d, line: %d)\n", $2, arr_type, current_scope, line_number);
        }
    }
    ;

type:
    INT     { $$ = strdup("int"); strcpy(current_datatype, "int"); }
    | FLOAT { $$ = strdup("float"); strcpy(current_datatype, "float"); }
    | CHAR  { $$ = strdup("char"); strcpy(current_datatype, "char"); }
    | DOUBLE { $$ = strdup("double"); strcpy(current_datatype, "double"); }
    | VOID  { $$ = strdup("void"); strcpy(current_datatype, "void"); }
    ;

identifier_list:
    IDENTIFIER
    {
        if (lookup_symbol($1, current_scope) == 1) {
            printf("Error: Variable '%s' already declared in this scope at line %d\n", 
                   $1, line_number);
        } else {
            insert_symbol($1, current_datatype, current_scope, line_number);
            printf("Declared: %s (type: %s, scope: %d, line: %d)\n", 
                   $1, current_datatype, current_scope, line_number);
        }
    }
    | identifier_list COMMA IDENTIFIER
    {
        if (lookup_symbol($3, current_scope) == 1) {
            printf("Error: Variable '%s' already declared in this scope at line %d\n", 
                   $3, line_number);
        } else {
            insert_symbol($3, current_datatype, current_scope, line_number);
            printf("Declared: %s (type: %s, scope: %d, line: %d)\n", 
                   $3, current_datatype, current_scope, line_number);
        }
    }
    ;

statement_list:
    /* empty */
    | statement_list statement
    ;

statement:
    expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | return_statement
    ;

expression_statement:
    SEMICOLON
    | expression SEMICOLON
    ;

expression:
    IDENTIFIER ASSIGN expression
    {
        if (lookup_symbol_all_scopes($1) == 0) {
            printf("Error: Variable '%s' used before declaration at line %d\n", $1, line_number);
        } else {
            // Assignment type checking
            SymbolTable *temp = symbol_table_head;
            char *lhs_type = NULL;
            int lhs_is_pointer = 0, lhs_is_array = 0;
            while (temp != NULL) {
                if (strcmp(temp->name, $1) == 0) {
                    lhs_type = temp->datatype;
                    if (strchr(lhs_type, '*')) lhs_is_pointer = 1;
                    if (strchr(lhs_type, '[')) lhs_is_array = 1;
                    break;
                }
                temp = temp->next;
            }
            if (lhs_type && strcmp(lhs_type, $3.type) != 0) {
                printf("Type Error: Assignment type mismatch at line %d ('%s' vs '%s')\n", line_number, lhs_type, $3.type);
            } else if (lhs_is_pointer != $3.is_pointer) {
                printf("Type Error: Pointer assignment mismatch at line %d\n", line_number);
            } else if (lhs_is_array != $3.is_array) {
                printf("Type Error: Array assignment mismatch at line %d\n", line_number);
            }
        }
        $$.type = $3.type;
        $$.is_pointer = $3.is_pointer;
        $$.is_array = $3.is_array;
    }
    | simple_expression { $$.type = $1.type; $$.is_pointer = $1.is_pointer; $$.is_array = $1.is_array; }
    ;

simple_expression:
    additive_expression { $$.type = $1.type; $$.is_pointer = $1.is_pointer; $$.is_array = $1.is_array; }
    | additive_expression relop additive_expression {
        if (strcmp($1.type, $3.type) != 0) {
            printf("Type Error: Sub-expressions have different types at line %d ('%s' vs '%s')\n", line_number, $1.type, $3.type);
        }
        $$.type = strdup("int"); // Relational ops result in int (bool)
        $$.is_pointer = 0;
        $$.is_array = 0;
    }
    ;

relop:
    LT | GT | LE | GE | EQ | NE
    ;

additive_expression:
    term { $$.type = $1.type; $$.is_pointer = $1.is_pointer; $$.is_array = $1.is_array; }
    | additive_expression PLUS term {
        if (strcmp($1.type, $3.type) != 0) {
            printf("Type Error: Addition operands have different types at line %d ('%s' vs '%s')\n", line_number, $1.type, $3.type);
        }
        $$.type = $1.type;
        $$.is_pointer = $1.is_pointer;
        $$.is_array = $1.is_array;
    }
    | additive_expression MINUS term {
        if (strcmp($1.type, $3.type) != 0) {
            printf("Type Error: Subtraction operands have different types at line %d ('%s' vs '%s')\n", line_number, $1.type, $3.type);
        }
        $$.type = $1.type;
        $$.is_pointer = $1.is_pointer;
        $$.is_array = $1.is_array;
    }
    ;

term:
    factor { $$.type = $1.type; $$.is_pointer = $1.is_pointer; $$.is_array = $1.is_array; }
    | term MULTIPLY factor {
        if (strcmp($1.type, $3.type) != 0) {
            printf("Type Error: Multiplication operands have different types at line %d ('%s' vs '%s')\n", line_number, $1.type, $3.type);
        }
        $$.type = $1.type;
        $$.is_pointer = $1.is_pointer;
        $$.is_array = $1.is_array;
    }
    | term DIVIDE factor {
        if (strcmp($1.type, $3.type) != 0) {
            printf("Type Error: Division operands have different types at line %d ('%s' vs '%s')\n", line_number, $1.type, $3.type);
        }
        $$.type = $1.type;
        $$.is_pointer = $1.is_pointer;
        $$.is_array = $1.is_array;
    }
    ;

factor:
    IDENTIFIER {
        if (lookup_symbol_all_scopes($1) == 0) {
            printf("Error: Variable '%s' used before declaration at line %d\n", $1, line_number);
            $$.type = strdup("error");
            $$.is_pointer = 0;
            $$.is_array = 0;
        } else {
            SymbolTable *temp = symbol_table_head;
            char *id_type = NULL;
            int is_pointer = 0, is_array = 0;
            while (temp != NULL) {
                if (strcmp(temp->name, $1) == 0) {
                    id_type = temp->datatype;
                    if (strchr(id_type, '*')) is_pointer = 1;
                    if (strchr(id_type, '[')) is_array = 1;
                    break;
                }
                temp = temp->next;
            }
            $$.type = id_type ? strdup(id_type) : strdup("error");
            $$.is_pointer = is_pointer;
            $$.is_array = is_array;
        }
    }
    | NUMBER { $$.type = strdup("int"); $$.is_pointer = 0; $$.is_array = 0; }
    | LPAREN expression RPAREN { $$.type = $2.type; $$.is_pointer = $2.is_pointer; $$.is_array = $2.is_array; }
    ;

selection_statement:
    IF LPAREN expression RPAREN statement {
        if (strcmp($3.type, "int") != 0) {
            printf("Type Error: Condition in IF must be int at line %d, got '%s'\n", line_number, $3.type);
        }
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        if (strcmp($3.type, "int") != 0) {
            printf("Type Error: Condition in IF-ELSE must be int at line %d, got '%s'\n", line_number, $3.type);
        }
    }
    ;

iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        if (strcmp($3.type, "int") != 0) {
            printf("Type Error: Condition in WHILE must be int at line %d, got '%s'\n", line_number, $3.type);
        }
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
        if (strcmp($5.type, "int") != 0) {
            printf("Type Error: Condition in FOR must be int at line %d, got '%s'\n", line_number, $5.type);
        }
    }
    ;

return_statement:
    RETURN SEMICOLON
    | RETURN expression SEMICOLON
    ;

%%

/* Symbol Table Functions */

void insert_symbol(char *name, char *datatype, int scope, int line) {
    SymbolTable *new_entry = (SymbolTable *)malloc(sizeof(SymbolTable));
    strcpy(new_entry->name, name);
    strcpy(new_entry->datatype, datatype);
    new_entry->scope = scope;
    new_entry->line_no = line;
    new_entry->next = symbol_table_head;
    symbol_table_head = new_entry;
}

int lookup_symbol(char *name, int scope) {
    SymbolTable *temp = symbol_table_head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0 && temp->scope == scope) {
            return 1; // Found in current scope
        }
        temp = temp->next;
    }
    return 0; // Not found in current scope
}

int lookup_symbol_all_scopes(char *name) {
    SymbolTable *temp = symbol_table_head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return 1; // Found in some scope
        }
        temp = temp->next;
    }
    return 0; // Not found at all
}

void display_symbol_table() {
    SymbolTable *temp = symbol_table_head;
    printf("\n%-5s %-20s %-15s %-10s %-10s\n", 
           "SL No", "Name", "Data Type", "Scope", "Line No");
    printf("-----------------------------------------------------------\n");
    
    int count = 1;
    while (temp != NULL) {
        printf("%-5d %-20s %-15s %-10d %-10d\n", 
               count++, temp->name, temp->datatype, temp->scope, temp->line_no);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n");
}

void enter_scope() {
    current_scope++;
    printf("Entering scope: %d\n", current_scope);
}

void exit_scope() {
    printf("Exiting scope: %d\n", current_scope);
    remove_scope(current_scope);
    current_scope--;
}

void remove_scope(int scope) {
    SymbolTable *temp = symbol_table_head;
    SymbolTable *prev = NULL;
    
    while (temp != NULL) {
        if (temp->scope == scope) {
            if (prev == NULL) {
                symbol_table_head = temp->next;
                free(temp);
                temp = symbol_table_head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_number, s);
}

int main() {
    printf("Enter your code (Ctrl+D to end):\n");
    yyparse();
    return 0;
}
