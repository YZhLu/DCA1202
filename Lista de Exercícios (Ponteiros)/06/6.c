#include <stdio.h>

int main() {

    int pulo[5];

    printf("%p, %p, %d, %d", pulo+2, &pulo[2], *(pulo + 2), pulo[2]);

    return 0;
}