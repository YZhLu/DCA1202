#include <stdio.h>      /* printf */
#include <stdlib.h>     /* malloc, qsort */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b) { // função que será chamada para comparação dentro da qsort()
  return ( *(int*)a - *(int*)b );
}

int main () {
    int n; // declara uma variável do tipo `int` e chamada `n` para armazenar a dimensão do vetor.
    float *vector; // declara uma variável do tipo `ponteiro para float` para armazenar o endereço do primeiro elemento do vetor.

    printf("Insira o tamanho do seu vetor: ");
    scanf("%d", &n); // atribui a variável `n` o tamanho do vetor a ser ordenado.

    vector = malloc(n*sizeof(float)); // aloca dinamicamente a memória do vetor.

    for(int i = 0; i<n; i++){ // atribui a cada elemento do vetor o valor indicado pelo usuário.
        printf("Insira o valor %d: ", i + 1);
        scanf("%f", &vector[i]); // atribui o valor indicado pelo usuário à enésima posição do vetor.
    }

    qsort(vector, n, sizeof(float), compare); // faz a chamada da função qsort.

    printf("Eis o teu vetor em ordem crescente: \n[");

    for(int i = 0; i < n - 1; i++){ // imprime o vetor ordenado.
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    free(vector); // libera a memória alocada.

    return 0;
}
