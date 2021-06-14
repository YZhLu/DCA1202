#include <stdio.h>

int main() {
    int i, j, *p, *q;
    //p = i;
    q = &j;
    p = &*&i;
    //i = (*&)j;
    i = *&j;
    i = *&*&j;
    //q = *p;
    i = (*p)++ + *q;
    int a = (2) + (3);

    printf("%d %d %p %p", i, j, p, q);
} 