#include <stdio.h>
int main() {
    int i=3, j=5;
    int *p, *q; // * is used in the declaration:
                // p and q are pointers to an integer, since (after dereferencing),
                // *p is an integer
    p = &i;     // & takes the address of i
    // now *p == 3, since p == &i and therefore *p == i
    q = &j;     // & takes the address of j
    // now *p == 5, since p == &j and therefore *p == j

    printf("A expressão `p == &i` retorna o valor `%d`\n",(p == &i));
    printf("A expressão `*p - *q` retorna o valor `%d`\n",(*p - *q));
    printf("A expressão `**&p` retorna o valor `%d`\n",(**&p));
    printf("A expressão `3 - *p/(*q) + 7` retorna o valor `%d`\n",(3 - *p/(*q) + 7));
    
    return 0;
}