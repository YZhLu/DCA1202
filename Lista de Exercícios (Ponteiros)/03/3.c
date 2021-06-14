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

    printf("%d %d %p %p", i, j, p, q);
} 