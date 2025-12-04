# C Subset Parser - Usage Instructions

## Files Created
1. **parser.y** - YACC specification file
2. **lexer.l** - LEX specification file

## Compilation Steps

```bash
# Step 1: Generate lexer from LEX file
flex lexer.l

# Step 2: Generate parser from YACC file
yacc -d parser.y

# Step 3: Compile the generated C files
gcc lex.yy.c y.tab.c -o c_parser 

# Step 4: Run the parser
./c_parser
```

## Sample C Programs to Test

### Sample Program 1 (Valid Program)
```c
int global_var;
float global_array[10];

int add(int a, int b) {
    int result;
    result = a + b;
    return result;
}

int main() {
    int x, y, sum;
    float average;

    x = 10;
    y = 20;
    sum = add(x, y);

    if (sum > 25) {
        average = sum / 2.0;
    } else {
        average = 0.0;
    }

    while (x < 100) {
        x = x + 10;
    }

    for (int i = 0; i < 5; i++) {
        global_array[i] = i * 2.5;
    }

    return 0;
}
```

### Sample Program 2 (With Syntax Errors)
```c
int main() {
    int x;
    y = 10;  // Error: y not declared

    if x > 5 {  // Error: missing parentheses
        x = x + 1;
    }

    while (x < 10  // Error: missing closing parenthesis
        x++;
    }

    return 0;
```

## Features Supported

### 1. Main Function
- `int main()` or `void main()`
- Compound statement body

### 2. Statements

#### Local/Global Declarations
- Variable declarations: `int x, y;`
- Array declarations: `int arr[10];`
- Global and local scope support

#### Assignment Statements
- Simple assignment: `x = 5;`
- Array assignment: `arr[i] = value;`
- Compound expressions

#### Conditional Statements
- If statements: `if (condition) statement`
- If-else statements: `if (condition) statement else statement`

#### Iterative Statements
- While loops: `while (condition) statement`
- For loops: `for (init; condition; update) statement`

#### Function Calls
- Function calls with arguments: `func(arg1, arg2);`
- Function calls without arguments: `func();`

### 3. User Defined Functions
- Function declarations with parameters
- Function definitions with body
- Return statements

## Error Detection

The parser detects and reports:
1. **Syntax Errors** - Malformed statements, missing punctuation
2. **Undeclared Variables** - Use of variables before declaration
3. **Line Numbers** - All errors reported with line numbers
4. **Variable Redeclaration** - Warnings for duplicate declarations

## Symbol Table

The parser maintains a symbol table that tracks:
- Variable names
- Variable types (int, float, char, array, parameter)
- Declaration line numbers
- Scope information

## Testing the Parser

1. Save the YACC code as `parser.y`
2. Save the LEX code as `lexer.l`
3. Follow the compilation steps above
4. Run the parser and enter your C code
5. Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to end input
6. Review the parsing results and symbol table

## Expected Output Example

For a valid program:
```
Variable declared: x at line 3
Variable declared: y at line 3
Assignment to x at line 5
Assignment to y at line 6
If statement at line 8
While loop at line 12
Main function parsed at line 2
Parsing completed successfully!

--- Symbol Table ---
Name            Type            Line
----            ----            ----
y               variable        3
x               variable        3
-------------------
```

For syntax errors:
```
Error: Undeclared variable 'z' used at line 4
Syntax Error at line 6: syntax error near 'if'
```

This parser provides a solid foundation for analyzing C subset programs with comprehensive error detection and symbol table management.
