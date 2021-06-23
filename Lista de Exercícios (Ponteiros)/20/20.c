#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "gc.h"

void* malloc(size_t size);
void* GC_malloc(size_t size);

void mallocTest(void) {
    char *string;

    string = malloc(sizeof(char) * 5);
    if (string == NULL) {
        return;
    }

    string[0] = 'D';
    string[1] = 'C';
    string[2] = 'A';
    string[3] = '1';
    string[4] = '0';
    printf("%s\n", string);
    free(string);
}

void GC_mallocTest(void) {
    char *string;

    string = GC_malloc(sizeof(char) * 5);
    if (string == NULL) {
        return;
    }

    string[0] = 'D';
    string[1] = 'C';
    string[2] = 'A';
    string[3] = '2';
    string[4] = '2';
    printf("%s\n", string);
    GC_free(string);
}

int main(){
    clock_t time = clock(), timeMalloc, timeGC_Malloc;
    float execTimeMalloc, execTimeGC_Malloc;

    printf("Tempo atual: %f seconds", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n\nIniciando mallocTest()");
    timeMalloc = clock();
    mallocTest();
    execTimeMalloc = (clock() - timeMalloc) / (double) CLOCKS_PER_SEC;
    printf("\nTempo de execução de 14.c: %f seconds\n", execTimeMalloc);

    printf("\nTempo atual: %f seconds", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n\nIniciando GC_mallocTest()");
    timeGC_Malloc = clock();
    GC_mallocTest();
    execTimeGC_Malloc = (clock() - timeGC_Malloc)/ (double) CLOCKS_PER_SEC;
    printf("\nTempo de execução de 15.c: %f seconds\n", execTimeGC_Malloc);

    printf("\n|>>>>>>________________________________________________<<<<<<|\n");
    printf("\n »Tempo de execução de 'mallocTest()' » sem GC: %f seconds\n", execTimeMalloc);
    printf("\n »Tempo de execução de 'GC_mallocTest()' » com GC: %f seconds\n", execTimeGC_Malloc);
    printf("\n »»Tempo total: %f seconds\n", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n|<<<<<<________________________________________________>>>>>>|\n");

    return 0;
}
