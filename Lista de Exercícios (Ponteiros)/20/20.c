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

    string[0] = 'Y';
    string[1] = 'Z';
    string[2] = 'h';
    string[3] = 'L';
    string[4] = 'u';
    printf("%s\n", string);
    free(string);
}

void GC_mallocTest(void) {
    char *string;
    
    string = GC_malloc(sizeof(char) * 5);
    if (string == NULL) {
        return;
    }

    string[0] = 'Y';
    string[1] = 'Z';
    string[2] = 'h';
    string[3] = 'L';
    string[4] = 'u';
    printf("%s\n", string);
    GC_free(string);
}

int main(){
    int count = 1000000;
    clock_t time = clock(), timeMalloc, timeGC_Malloc;
    float execTimeMalloc, execTimeGC_Malloc;

    printf("Tempo atual: %f seconds", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n\nIniciando mallocTest()");
    timeMalloc = clock();
    for (int i = 0; i < count; i++) {
        mallocTest();
    }
    
    execTimeMalloc = (clock() - timeMalloc) / (double) CLOCKS_PER_SEC;
    printf("\nTempo de execução de mallocTes(): %f seconds\n", execTimeMalloc);

    printf("\nTempo atual: %f seconds", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n\nIniciando GC_mallocTest()");
    GC_INIT();
    timeGC_Malloc = clock();
    for (int i = 0; i < count; i++) {
         GC_mallocTest();
    }
    execTimeGC_Malloc = (clock() - timeGC_Malloc)/ (double) CLOCKS_PER_SEC;
    printf("\nTempo de execução de GC_mallocTest(): %f seconds\n", execTimeGC_Malloc);

    printf("\n|>>>>>>_______________________________________________________<<<<<<|\n");
    printf("\n »Tempo de execução de 'mallocTest()' » sem GC: %f seconds\n", execTimeMalloc);
    printf("\n »Tempo de execução de 'GC_mallocTest()' » com GC: %f seconds\n", execTimeGC_Malloc);
    printf("\n »»Tempo total: %f seconds\n", (clock() - time) / (double) CLOCKS_PER_SEC);
    printf("\n|<<<<<<_______________________________________________________>>>>>>|\n");

    return 0;
}
