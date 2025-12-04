# Makefile for C Lexical Analyzer

CC = gcc
FLEX = flex
CFLAGS = -Wall -g

# Default target
all: lexer

# Generate C code from flex file and compile
lexer: lexer.l
	$(FLEX) lexer.l
	$(CC) $(CFLAGS) -o lexer lex.yy.c -lfl || $(CC) $(CFLAGS) -o lexer lex.yy.c -ll || $(CC) $(CFLAGS) -o lexer lex.yy.c

# Test with sample program
test: lexer sample.c
	./lexer sample.c

# Test with interactive input
interactive: lexer
	./lexer

# Clean generated files
clean:
	rm -f lex.yy.c lexer

# Install flex if needed (Ubuntu/Debian)
install-flex:
	sudo apt-get update
	sudo apt-get install flex

.PHONY: all test interactive clean install-flex