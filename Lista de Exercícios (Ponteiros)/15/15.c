#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);
void my_qsort (void *pont, int qtd, int tam, int (*func)(const void*, const void*));
void swap(const void*, const void*);

int main() {
    int n;
    float *vector;

    printf("Insira o tamanho do seu vetor: ");
    scanf("%d", &n); 

    vector = malloc(n*sizeof(float)); 

    for(int i = 0; i<n; i++){ 
        printf("Insira o valor %d: ", i + 1);
        scanf("%f", &vector[i]);
    }

    my_qsort(vector, n, sizeof(float), compare); 

    printf("Eis o teu vetor em ordem crescente: \n[");

    for(int i = 0; i < n - 1; i++){ 
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    free(vector); 

    return 0;
}

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void swap(const void *a, const void *b){
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}

void my_qsort (void *pont, int qtd, int tam, int (*func)(const void*, const void*)){
    int i, j, res;
    for(i = 0; i < qtd-1; i++){
        for(j = 0; j < (qtd-1); j++){
            res = (func)((pont + (j*tam)), (pont + ((j+1)*tam)));
            if(res > 0) swap((pont + (j*tam)), (pont + ((j+1)*tam)));
        }
    }
}
