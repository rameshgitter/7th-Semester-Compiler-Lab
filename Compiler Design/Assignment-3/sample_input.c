/* Sample C Program with various tokens and intentional errors */

int main() {
    int x = 10;
    float y = 20.5;
    char ch = 'a';
    
    // Valid operations
    x = x + y;
    if (x > 15) {
        printf("x is greater than 15");
    } else {
        printf("x is not greater than 15");
    }
    
    // Loop constructs
    for (int i = 0; i < 10; i++) {
        do {
            x += 1;
        } while (x < 100);
    }
    
    // Bitwise operations
    int a = 5;
    int b = 3;
    int result = a & b;
    result |= (a ^ b);
    result <<= 2;
    result >>= 1;
    
    // Relational operations
    if (a == b || a != b) {
        if (a <= b && a >= b) {
            printf("Equal values");
        }
    }
    
    // Assignment operations
    a += 5;
    b -= 3;
    result *= 2;
    result /= 4;
    result %= 3;
    
    /* INTENTIONAL ERRORS FOR TESTING */
    
    // Error 1: Invalid characters
    int value$ = 12$34;
    char invalid@ = 'x';
    
    // Error 2: Long identifier (exceeds 31 characters)
    int this_is_a_very_long_identifier_name_that_exceeds_maximum_length = 5;
    
    // Error 3: Long number (exceeds 10 digits)
    int big_number = 12345678901234567890;
    
    // Error 4: Unmatched string
    printf("This is an unmatched string
    
    // Error 5: Spelling errors
    itn count = 0;
    flot price = 99.99;
    fi (count > 0) {
        // do something
    }
    esle {
        // do something else
    }
    
    // Error 6: Invalid number formats
    int mixed1 = 123abc;
    int mixed2 = 45def67;
    
    return 0;
}
