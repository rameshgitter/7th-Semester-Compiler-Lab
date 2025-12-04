// test2.c - C program with various syntax errors
// This program should generate multiple error messages

int global_var;

// Function with missing return type (should cause error in strict parsing)
multiply(int a, int b) {
    int result;
    result = a * b;
    return result;
}

int main() {
    // Local declarations
    int x, y;
    
    // Error 1: Using undeclared variable 'z'
    x = 10;
    y = 20;
    z = 30;  // ERROR: z not declared
    
    // Error 2: Missing parentheses in if condition
    if x > 5 {  // ERROR: should be if (x > 5)
        y = y + 1;
    }
    
    // Error 3: Using undeclared array
    arr[0] = 100;  // ERROR: arr not declared
    
    // Error 4: Missing closing parenthesis in while loop
    while (x < 100 {  // ERROR: missing closing parenthesis
        x = x + 10;
    }
    
    // Error 5: Using undeclared variable in assignment
    undeclared_var = x + y;  // ERROR: undeclared_var not declared
    
    // Error 6: Missing semicolon
    int new_var  // ERROR: missing semicolon
    new_var = 50;
    
    // Error 7: Invalid function call (function doesn't exist)
    result = nonexistent_function(x, y);  // ERROR: function not declared
    
    // Error 8: Using variable before declaration in same scope
    another_var = 100;  // ERROR: another_var used before declaration
    int another_var;
    
    // Error 9: Missing closing brace for if statement
    if (y > 10) {
        x = x + 5;
    // ERROR: missing closing brace
    
    // Error 10: Incorrect for loop syntax
    for (int i = 0; i < 5; i+ {  // ERROR: i+ should be i++, missing )
        x = x + i;
    }
    
    return 0;
}

// Error 11: Function definition after main (valid in C but may cause issues)
int divide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}
