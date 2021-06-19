#include <stdio.h>
//posso fz a quem pertence aquele espaco?
int main() {
    unsigned int x;
    unsigned char *px;

    printf("step 0\nXXXXXXXXX\n\nDECLARANDO AS VARIÁVEIS\n");
    printf("&x = %p\n", &x);
    printf("*&x = %d\n", *&x);
    printf("x = %d\n", x);
    printf("px = %p\n", px);
    printf("&px = %p\n", &px);
    printf("*&px = %p\n", *&px);
    printf("*px = %d\n", *px);
    printf("&*px = %p\n", *&px);

    printf("\nstep 1 \nXXXXXXXXX\n\nINICIANDO AS VARIÁVEIS\n");
    printf("x = 3\npx = &x\n\n&&&&&&&&\n\n");
    x = 3;
    px = &x;
    printf("x = %d\n", x);
    printf("px = %p\n", px);
    printf("&px = %p\n", &px);
    printf("*&px = %p\n", *&px);
    printf("*px = %d\n", *px);

    printf("\nstep 2 \nXXXXXXXXX\n");
    *px = 1;
    printf("*px = %d\n", *px);
    printf("x = %d\n", x);
    printf("step 3 \nXXXXXXXXX\n");
    px++;
    printf("x = %d\n", x);
    printf("px++ = %p\n", px);
    printf("*px++ = %d\n", *px);
    printf("step 4 \nXXXXXXXXX\n");
    *px = 1;
    printf("x = %d\n", x);
    printf("*px++ = %d\n", *px);
    printf("x = %d\n", x);

    return 0;
}