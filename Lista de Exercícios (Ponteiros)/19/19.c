#include "gc.h"
#include <assert.h>
#include <stdio.h>

/*

Chame GC_MALLOC sempre que quiser chamar malloc. 
Isso inicializa a memória para zero como calloc; 
não há necessidade de limpar explicitamente o resultado.
Se você souber que um objeto não conterá ponteiros para 
o heap coletado pelo lixo e não precisar ser inicializado,
chame GC_MALLOC_ATOMIC em vez disso.

Uma função GC_FREE é fornecida, mas não precisa ser chamada.
Para objetos muito pequenos, 
seu programa provavelmente terá um desempenho melhor
 se você não chamá-lo e deixar que o coletor faça seu trabalho.

Uma função GC_REALLOC se comporta como o realloc da biblioteca C.
Ele aloca memória livre de ponteiro não inicializada
se o objeto original foi alocado dessa maneira.

A seguir temos um exemplo.

O código original pode ser encontrado em:
https://www.hboehm.info/gc/simple_example.html

*/

int main() {
  int i;

  GC_INIT();	/* Optional on Linux/X86; */
  for (i = 0; i < 10000000; ++i) {
     int **p = (int **) GC_MALLOC(sizeof(int *));
     int *q = (int *) GC_MALLOC_ATOMIC(sizeof(int));
     assert(*p == 0);
     *p = (int *) GC_REALLOC(q, 2 * sizeof(int));
     if (i % 100000 == 0) {
       printf("Heap size = %zu\n", GC_get_heap_size());
     }
   }
  return 0;
}