#include <stdio.h>

int main() {
    int a, b, sum;
    float average;
    char grade;
    
    a = 10;
    b = 20;
    sum = a + b;
    
    if (sum > 25) {
        average = sum / 2.0;
        grade = 'A';
    } else {
        average = 0.0;
        grade = 'F';
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Count: %d\n", i);
    }
    
    while (a != b) {
        a++;
        b--;
    }
    
    do {
        sum += 10;
    } while (sum <= 100);
    
    // Bitwise operations
    int x = 8, y = 4;
    int result = x & y;
    result |= (x << 2);
    result ^= ~y;
    
    return 0;
}