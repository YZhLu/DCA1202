#include <stdio.h>

int main() {

    char x1[4];
    int x2[4];
    float x3[4];
    double x4[4];

    printf("%4s %15s %15s %15s %15s", "", "char x", "int x", "float x", "double x");
    printf("\n%-5s %p, %p, %p, %p", "x   |", x1, x2, x3, x4);
    printf("\n%5s %p, %p, %p, %p", "x+1 |", x1+1, x2+1, x3+1, x4+1);
    printf("\n%5s %p, %p, %p, %p", "x+2 |", x1+2, x2+2, x3+2, x4+2);
    printf("\n%5s %p, %p, %p, %p", "x+3 |", x1+3, x2+3, x3+3, x4+3);
    
    return 0;
}