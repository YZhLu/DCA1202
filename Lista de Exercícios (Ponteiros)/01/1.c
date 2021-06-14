#include <stdio.h>
int main() 
{
  int i=3, j=5;
  int *p, *q;
  p = &i;
  q = &j;

  printf("A expressão `p == &i` retorna o valor `%d`\n",(p == &i));
  printf("A expressão `*p - *q` retorna o valor `%d`\n",(*p - *q));
  printf("A expressão `**&p` retorna o valor `%d`\n",(**&p));
  printf("A expressão `3 - *p/(*q) + 7` retorna o valor `%d`\n",(3 - *p/(*q) + 7));
  
  return 0;
}