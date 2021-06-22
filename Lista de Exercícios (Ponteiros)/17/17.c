#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addVectors(int *v1, int *v2, int *v3, int n);

int main() {
    int *vector1, *vector2, *addVector, n;

    printf("Insira o tamanho dos vetores: \n");
    scanf("%d",&n);

    vector1 = malloc(n * sizeof(int));
    vector2 = malloc(n * sizeof(int));

    printf("Insira os elementos do primeiro vetor: \n");
    for(int i=0; i<n ;i++){
        scanf("%d", &vector2[i]);
    }

    printf("Insira os elementos do segundo vetor: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &vector1[i]);
    }
    printf("\n");

    addVectors(vector1, vector2, addVector,n);

    free(vector2);
    free(vector1);
    
    return 0;
}

void addVectors(int *v1, int *v2, int *addVector, int n) {
    addVector = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        addVector[i] = v1[i] + v2[i];
    }
    printf("Eis a soma dos dois vetores: ");
    for(int i=0; i<n; i++){
        printf("%d  ", addVector[i]);
    }
    printf("\n");
}