# Symbol Table Management - Complete Guide

## Overview
This implementation creates a symbol table that tracks:
- Variable names
- Data types (int, float, char, double, void)
- Scope information (nested scopes)
- Line numbers
- Checks for multiple declarations in same scope
- Validates variable usage before declaration

## Files Required
1. **symbol_table.l** - LEX file (lexical analyzer)
2. **symbol_table.y** - YACC file (parser with semantic actions)

## Compilation Steps

### Step 1: Generate Parser
```bash
yacc -d symbol_table.y
```
This generates:
- `y.tab.c` - Parser implementation
- `y.tab.h` - Token definitions

### Step 2: Generate Lexer
```bash
lex symbol_table.l
```
This generates:
- `lex.yy.c` - Lexer implementation

### Step 3: Compile Everything
```bash
gcc y.tab.c lex.yy.c -o symbol_table -ll
```

### Step 4: Run the Program
```bash
./symbol_table
```

## Features Implemented

### 1. **Data Type Detection**
- Automatically identifies data types: `int`, `float`, `char`, `double`, `void`
- Stores type information for each variable

### 2. **Scope Management**
- Tracks nested scopes (functions, blocks)
- Scope 0: Global
- Scope increases when entering blocks `{}`
- Removes variables when exiting scope

### 3. **Error Detection**
- **Multiple declarations** in same scope
- **Undeclared variable usage**
- Clear error messages with line numbers

### 4. **Symbol Table Operations**
- `insert_symbol()` - Add new variable
- `lookup_symbol()` - Search in current scope only
- `lookup_symbol_all_scopes()` - Search in all accessible scopes
- `enter_scope()` - Increment scope level
- `exit_scope()` - Remove variables from exiting scope

## Test Cases

### Test Case 1: Basic Declaration
```c
int main() {
    int a, b, c;
    float x, y;
    char ch;
    return 0;
}
```

**Expected Output:**
```
Entering scope: 1
Entering scope: 2
Declared: a (type: int, scope: 2, line: 2)
Declared: b (type: int, scope: 2, line: 2)
Declared: c (type: int, scope: 2, line: 2)
Declared: x (type: float, scope: 2, line: 3)
Declared: y (type: float, scope: 2, line: 3)
Declared: ch (type: char, scope: 2, line: 4)
```

### Test Case 2: Nested Scopes
```c
int main() {
    int x;
    {
        int y;
        float x;
    }
    return 0;
}
```

**Expected Output:**
- `x` declared in scope 2 (outer block)
- `y` declared in scope 3 (inner block)
- `x` declared again in scope 3 (allowed - different scope)
- Variables in scope 3 removed when block exits

### Test Case 3: Multiple Declaration Error
```c
int main() {
    int a;
    float a;
    return 0;
}
```

**Expected Output:**
```
Declared: a (type: int, scope: 2, line: 2)
Error: Variable 'a' already declared in this scope at line 3
```

### Test Case 4: Undeclared Variable Usage
```c
int main() {
    int a;
    b = 10;
    return 0;
}
```

**Expected Output:**
```
Error: Variable 'b' used before declaration at line 3
```

### Test Case 5: Multiple Functions
```c
int add(int a, int b) {
    int sum;
    sum = a + b;
    return 0;
}

float multiply(float x, float y) {
    float result;
    result = x * y;
    return 0;
}
```

**Expected Behavior:**
- Each function has its own scope
- Parameters added to function's scope
- Local variables tracked separately

## Symbol Table Structure

```
SL No | Name      | Data Type | Scope | Line No
------|-----------|-----------|-------|--------
1     | main      | int       | 1     | 1
2     | a         | int       | 2     | 2
3     | b         | int       | 2     | 2
4     | x         | float     | 2     | 3
```

## Key Concepts

### Static Scoping Rules
1. Variables must be declared before use
2. No multiple declarations in same scope
3. Same name can exist in different scopes
4. Inner scope can shadow outer scope

### Scope Levels
- **0**: Global scope (not used in this implementation)
- **1**: Function scope
- **2+**: Nested block scopes

## Common Issues & Solutions

### Issue 1: "yylex undefined"
**Solution:** Include `-ll` flag during compilation

### Issue 2: "y.tab.h not found"
**Solution:** Use `yacc -d` to generate header file

### Issue 3: Segmentation fault
**Solution:** Check string operations, ensure proper memory allocation

## Extensions & Enhancements

### Possible Additions:
1. **Type checking** for expressions
2. **Hash table** implementation for faster lookup
3. **Array** and **pointer** support
4. **Function signature** matching
5. **Semantic analysis** (type compatibility)
6. **Better error recovery**
7. **Symbol table export** to file

## Assignment Requirements Met

✅ **Data type detection** for each variable  
✅ **Symbol table creation** with entries  
✅ **Scope information** tracking  
✅ **Declaration before use** enforcement  
✅ **YACC grammar rules** with semantic actions  
✅ **Multiple declaration** detection  
✅ **Nested scope** support  

## References
- Based on the Symbol Table Management lecture by Samit Biswas
- Implements linked list approach for symbol table
- Follows standard compiler design principles
