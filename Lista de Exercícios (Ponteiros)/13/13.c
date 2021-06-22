#include <stdio.h>
#include <stdlib.h>

int main(){

    float *vector;
    int n, aux;

    printf("Insira o tamanho do seu vetor: ");
    scanf("%d", &n);

    vector = malloc(n*sizeof(float));

    for(int i = 0; i<n; i++){
        printf("Insira o valor %d: ", i + 1);
        scanf("%f", &vector[i]);
    }

    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
    printf("Eis o teu vetor em ordem crescente: \n[");

    for(int i = 0; i < n - 1; i++){
        printf("%f", vector[i]);
        printf(", ");
    }
    printf("%f]\n", vector[n - 1]);

    free(vector);
}
