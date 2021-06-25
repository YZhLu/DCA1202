#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void*, const void*);
void my_qsort (void *pont, int qtd, int tam, int (*func)(const void*, const void*));
void swap(const void*, const void*);

int main() {
    clock_t time = clock(), time14, time15;

    int n;
    float *vector, execTime14, execTime15;

    n = 10000;
    printf("%d é o tamanho do seu vetor\n", n); 

    vector = malloc(n*sizeof(float)); 

    for(int i = 0; i<n; i++){ 
        vector[i] = n - i;
    }

    printf("Eis o teu vetor: \n[");

    for(int i = 0; i < n - 1; i++){ 
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    printf("\nTempo atual: %f seconds", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n\nIniciando 14.c");
    
    time14 = clock();

    qsort(vector, n, sizeof(float), compare); 

    printf("\nEis o teu vetor em ordem crescente: \n[");

    for(int i = 0; i < n - 1; i++){ 
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    execTime14 = (clock() - time14) / (double) CLOCKS_PER_SEC;
    printf("\nTempo de execução de 14.c: %f seconds\n", execTime14);

    printf("\nReordenando teu vetor: \n");
    for(int i = 0; i<n; i++){ 
        vector[i] = n - i;
    }
    printf("Eis o teu vetor: \n[");

    for(int i = 0; i < n - 1; i++){ 
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    printf("\nTempo atual: %f seconds", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n\nIniciando 15.c");
    
    time15 = clock();

    my_qsort(vector, n, sizeof(float), compare); 

    printf("\nEis o teu vetor em ordem crescente: \n[");

    for(int i = 0; i < n - 1; i++){ 
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    execTime15 = (clock() - time15)/ (double) CLOCKS_PER_SEC;
    printf("\nTempo de execução de 15.c: %f seconds\n", execTime15);

    free(vector); 

    printf("\n|>>>>>>______________________________________________<<<<<<|\n");
    printf("\n »Tempo de execução de 14.c 'qsort()': %f seconds\n", execTime14);
    printf("\n »Tempo de execução de 15.c 'my_qsort()': %f seconds\n", execTime15);
    printf("\n »»Tempo total: %f seconds\n", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n|<<<<<<______________________________________________>>>>>>|\n");

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
