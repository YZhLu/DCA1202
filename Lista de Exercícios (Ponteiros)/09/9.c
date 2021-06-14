#include <stdio.h>

int main() {

    char x1[4];
    int x2[4];
    float x3[4];
    double x4[4];

    printf("%p, %p, %p, %p", x1, x2, x3, x4);
    printf("\n%p, %p, %p, %p", x1+1, x2+1, x3+1, x4+1);
    printf("\n%p, %p, %p, %p", x1+2, x2+2, x3+2, x4+2);
    printf("\n%p, %p, %p, %p", x1+3, x2+3, x3+3, x4+3);
    
    return 0;
}