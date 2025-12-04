/*
Consider the following assignment for Lexical Analysis:

Implement a lexical analyzer using C program for the following types of tokens:
a) Arithmetic, Relational, Logical, Bitwise and Assignment Operators of C.
b) Reserved words:int, float,char, for, while, if, else etc.
c) Identifier.
d) Integer Constants.
e) Parentheses, Curly braces
Design a complete transition diagram for the whole. Follow the ideas of yylex, yytext, yyleng, yylineno etc. as stated in the class.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int yylineno = 1;
char yytext[256];
int yyleng;

const char* keywords[] = {
    "int", "float", "char", "if", "else", "for", "while", NULL
};

int isKeyword(const char* s) {
    for (int i = 0; keywords[i]; i++)
        if (strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}

void emit(const char* tok) {
    printf("%-20s  \"%s\"  (Line %d)\n", tok, yytext, yylineno);
}

// Read next non-whitespace (counting newlines)
int nextChar(FILE* fp) {
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') yylineno++;
        if (!isspace(c)) return c;
    }
    return EOF;
}

void ungetChar(int c, FILE* fp) {
    if (c == EOF) return;
    if (c == '\n') yylineno--;
    ungetc(c, fp);
}

void lex(FILE* fp) {
    int c;
    while ((c = nextChar(fp)) != EOF) {
        int pos = 0;
        yytext[pos++] = c;

        // Identifier or Keyword
        if (isalpha(c) || c == '_') {
            while (isalnum(c = fgetc(fp)) || c == '_') {
                yytext[pos++] = c;
            }
            ungetChar(c, fp);
            yytext[pos] = '\0'; yyleng = pos;
            emit(isKeyword(yytext) ? "KEYWORD" : "IDENTIFIER");
            continue;
        }

        // Integer constant
        if (isdigit(c)) {
            while (isdigit(c = fgetc(fp))) {
                yytext[pos++] = c;
            }
            ungetChar(c, fp);
            yytext[pos] = '\0'; yyleng = pos;
            emit("INT_CONST");
            continue;
        }

        // Comments
        if (c == '/') {
            int nxt = fgetc(fp);
            if (nxt == '/') {
                // line comment
                while ((nxt = fgetc(fp)) != EOF && nxt != '\n');
                yylineno++;
                continue;
            } else if (nxt == '*') {
                // block comment
                int prev = 0;
                while ((nxt = fgetc(fp)) != EOF) {
                    if (nxt=='\n') yylineno++;
                    if (prev=='*' && nxt=='/') break;
                    prev = nxt;
                }
                continue;
            } else {
                ungetChar(nxt, fp);
                // fall-through to operator logic
            }
        }

        // Operators & Delimiters
        // build up yytext[] further if multi-char op
        #define PEEK() fgetc(fp)
        #define UNP(c) ungetChar(c, fp)
        #define TRY(two, name)                          \
            do {                                        \
                int _n = PEEK();                        \
                if (_n == two[1]) {                     \
                    yytext[pos++] = _n;                 \
                    yytext[pos] = '\0';                 \
                    emit(name);                         \
                    break;                              \
                } else {                                \
                    UNP(_n);                            \
                    yytext[pos] = '\0';                 \
                    emit(name);                         \
                    break;                              \
                }                                       \
            } while(0)

        // A little switch for ops
        switch (c) {
          case '+': TRY("++", "ARITH_OP"); break;
          case '-': TRY("--", "ARITH_OP"); break;
          case '*':
            // could also be *=
            TRY("*=", "ARITH_OP"); break;
          case '%': TRY("%=", "ARITH_OP"); break;
          case '=': TRY("==", "REL_OP"); break;
          case '<':
            { int n = PEEK();
              if (n=='<' ) {
                yytext[pos++] = n;
                // maybe <<= ?
                int m = PEEK();
                if (m=='=') yytext[pos++] = m;
                else UNP(m);
                yytext[pos]=0; emit("BITWISE/ASSIGN_OP");
              } else {
                UNP(n);
                TRY("<=", "REL_OP");
              }
            } break;
          case '>':
            { int n = PEEK();
              if (n=='>' ) {
                yytext[pos++] = n;
                // maybe >>=
                int m = PEEK();
                if (m=='=') yytext[pos++] = m;
                else UNP(m);
                yytext[pos]=0; emit("BITWISE/ASSIGN_OP");
              } else {
                UNP(n);
                TRY(">=", "REL_OP");
              }
            } break;
          case '!': TRY("!=", "REL_OP"); break;
          case '&': TRY("&&", "LOGICAL_OP"); break;
          case '|': TRY("||", "LOGICAL_OP"); break;
          case '^': yytext[pos]=0; emit("BITWISE_OP"); break;
          case '~': yytext[pos]=0; emit("BITWISE_OP"); break;
          case '(': case ')':
            yytext[pos]=0; emit("PAREN"); break;
          case '{': case '}':
            yytext[pos]=0; emit("BRACE"); break;
          default:
            yytext[pos]=0;
            printf("UNKNOWN_TOKEN  \"%s\"  (Line %d)\n", yytext, yylineno);
        }
        #undef PEEK
        #undef UNP
        #undef TRY
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source.c>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    lex(fp);
    fclose(fp);
    return 0;
}

