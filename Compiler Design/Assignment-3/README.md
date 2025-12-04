# Lexical Analyzer with Error Detection

## Overview

This enhanced lexical analyzer implements comprehensive token recognition and error detection for C programs using Lex/Flex. It identifies all required tokens and detects various types of lexical errors.

## Features

### Supported Tokens:
1. **Arithmetic Operators**: `+`, `-`, `*`, `/`
2. **Relational Operators**: `==`, `!=`, `<=`, `>=`, `<`, `>`
3. **Logical Operators**: `&&`, `||`, `!`
4. **Bitwise Operators**: `&`, `|`, `^`, `~`, `<<`, `>>`
5. **Assignment Operators**: `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`
6. **Reserved Words**: `int`, `float`, `char`, `for`, `do`, `while`, `if`, `else`
7. **Identifiers**: Valid C identifiers
8. **Integer Constants**: Valid integer numbers
9. **Parentheses**: `(`, `)`
10. **Curly Braces**: `{`, `}`

### Error Detection:
1. **Exceeding length limits**:
   - Identifiers > 31 characters
   - Numbers > 10 digits

2. **Illegal characters**: `@`, `#`, `$`, `` ` ``

3. **Unmatched strings**: Strings without closing quotes

4. **Spelling errors**: Common misspellings of keywords

5. **Invalid character placement**: Mixed invalid characters in numbers/identifiers

6. **Invalid number formats**: Numbers mixed with letters

## Files

### 1. lexer.l (Main Lex File)
The main lexical analyzer specification file containing all patterns and error handling.

### 2. sample_input.c (Test File)
Sample C program containing various tokens and intentional errors for testing.

### 3. Makefile

```makefile
CC = gcc
FLEX = flex
TARGET = lexer
SOURCE = lexer.l
INPUT = sample_input.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(FLEX) -o $(TARGET).c $(SOURCE)
	$(CC) -o $(TARGET) $(TARGET).c -lfl

test: $(TARGET)
	./$(TARGET) < $(INPUT)

clean:
	rm -f $(TARGET) $(TARGET).c

install:
	sudo apt-get update
	sudo apt-get install flex build-essential

help:
	@echo "Available targets:"
	@echo "  all     - Build the lexical analyzer"
	@echo "  test    - Run the analyzer with sample input"
	@echo "  clean   - Remove generated files"
	@echo "  install - Install required dependencies (Ubuntu/Debian)"
	@echo "  help    - Show this help message"

.PHONY: all test clean install help
```

## Installation and Usage

### Prerequisites
- GCC compiler
- Flex (Fast Lexical Analyzer Generator)

### Installation (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install flex build-essential
```

### Compilation and Execution
```bash
# Compile the lexer
flex -o lexer.c lexer.l
gcc -o lexer lexer.c -lfl

# Run with sample input
./lexer < sample_input.c

# Or run with custom input
./lexer < your_program.c
```

### Using Makefile
```bash
# Install dependencies
make install

# Build the lexer
make all

# Test with sample input
make test

# Clean generated files
make clean
```

## Output Format

### Tokens
```
TOKEN: Description        | VALUE: token_value  | TYPE: number | LINE: line_number
```

### Errors
```
ERROR: Error description  | VALUE: token_value  | LINE: line_number
```

### Summary
```
=== ANALYSIS SUMMARY ===
Total tokens recognized: X
Total errors found: Y
Total lines processed: Z
```

## Example Output

```
=== LEXICAL ANALYZER WITH ERROR DETECTION ===
Processing input...

TOKEN: Reserved Word      | VALUE: int          | TYPE: 6  | LINE: 3
TOKEN: Identifier         | VALUE: main         | TYPE: 7  | LINE: 3
TOKEN: Left Parenthesis   | VALUE: (            | TYPE: 9  | LINE: 3
TOKEN: Right Parenthesis  | VALUE: )            | TYPE: 9  | LINE: 3
TOKEN: Left Curly Brace   | VALUE: {            | TYPE: 10 | LINE: 3
...
ERROR: Invalid character(s) in token | VALUE: value$    | LINE: 45
ERROR: Invalid number format         | VALUE: 12$34     | LINE: 45
ERROR: Identifier exceeds maximum length (31) | VALUE: this_is_a_very_long... | LINE: 49
...

=== ANALYSIS SUMMARY ===
Total tokens recognized: 87
Total errors found: 12
Total lines processed: 67
⚠ Lexical errors detected. Please review the output above.
```

## Error Types Detected

| Error Type | Description | Example |
|------------|-------------|---------|
| Invalid Character | Illegal characters in tokens | `value$`, `name@` |
| Long Identifier | Identifier > 31 characters | `very_long_identifier_name...` |
| Long Number | Number > 10 digits | `12345678901234567890` |
| Unmatched String | String without closing quote | `"unmatched string` |
| Spelling Error | Misspelled keywords | `itn`, `flot`, `fi` |
| Invalid Number | Numbers with letters/symbols | `123abc`, `12$34` |

## Customization

You can modify the following parameters in the lexer:

- `MAX_IDENTIFIER_LENGTH`: Maximum identifier length (default: 31)
- `MAX_NUMBER_LENGTH`: Maximum number length (default: 10)
- Add more reserved words to the `reserved_words[]` array
- Add more invalid characters to the `invalid_char` pattern
- Extend error checking patterns as needed

## Testing

The provided sample input includes:
- All types of supported tokens
- All types of lexical errors
- Various edge cases
- Nested constructs (loops, conditionals)
- Multiple error scenarios on the same line

This comprehensive test ensures the analyzer correctly identifies tokens and catches all specified error types.
