#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int **m, int l, int c);
int** initMatrix(int **m, int nl, int nc);
int** multiplyMatrix(int **ma, int **mb, int **mc, int n1, int c1, int c2);
void printMatrix(int **m, int l, int c);

int main(void) {
    int nl1, nc1, nl2, nc2;
    int **m1, **m2, **m3;

    while (nc1 != nl2) {

        printf("Insira o número de linhas da primeira Matriz: ");
        scanf("%d", &nl1);
        printf("Insira o número de colunas da primeira Matriz: ");
        scanf("%d", &nc1);
        printf("Insira o número de linhas da segunda Matriz: ");
        scanf("%d", &nl2);
        printf("Insira o número de colunas da segunda Matriz: ");
        scanf("%d", &nc2);

        if (nc1 != nl2) {
            printf("««Operação Inválida««\n");
            printf("O numero de colunas da primeira matriz deve ser igual ao do número de linhas da segunda matriz.\n\nTente novamente!\n");
        }
    }
    
    printf("Insira os elementos da primeira matriz:\n");
    m1 = createMatrix(m1, nl1, nc1);
    m1 = initMatrix(m1, nl1, nc1);
    printf("\nEis a primeira matriz:");
    printMatrix(m1, nl1, nc1);

    printf("Insira os elementos da segunda matriz:\n");
    m2 = createMatrix(m2, nl2, nc2);
    m2 = initMatrix(m2, nl2, nc2);
    printf("\nEis a segunda matriz:");
    printMatrix(m2, nl2, nc2);

    m3 = multiplyMatrix(m1, m2, m3, nl1, nc1, nc2);
    printf("\nEis a matriz de produto entre a primeira e segunda matriz:");
    printMatrix(m3, nl1, nc2);

    free(m1[0]);
    free(m1);
    free(m2[0]);
    free(m2);
    free(m3[0]);
    free(m3);

    return 0;
}

int** createMatrix(int **m, int nl, int nc) {
    
    m = malloc(nl * sizeof(int*));
    m[0] = malloc(nc * nl * sizeof(int));

    for (int i = 1; i < nl; i++) {
        m[i] = m[i-1] + nc;
    }

    return m;
    
}

int** initMatrix(int **m, int nl, int nc) {
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            scanf("%d", &m[l][c]);
        }
    }

    return m;
}

int** multiplyMatrix(int **ma, int **mb, int **mc, int nla, int nca, int ncb) {
    int acc = 0;
    
    mc = createMatrix(mc, nla, ncb);
    
    for (int l = 0; l < nla; l++) {

        for (int c = 0; c < ncb; c++) {
            mc[l][c] = 0;
            for (int n = 0; n < nca; n++) {  
                acc += ma[l][n] * mb[n][c];
                
            }
            mc[l][c] = acc;
            acc = 0;
        }
    }

    return mc;
}

void printMatrix(int **m, int nl, int nc) {

    printf("\n[");
    for (int l = 0; l < nl - 1; l++) {
        //printf("[");
        for (int c = 0; c < nc; c++) {
            printf("%d", m[l][c]);
            printf(", ");
        }
        printf("\n ");
    }

    for (int c = 0; c < nc -1; c++) {
        printf("%d", m[nl-1][c]);
        printf(", ");
    }
    printf("%d]\n\n", m[nl-1][nc - 1]);
}
