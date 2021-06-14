#include <stdio.h>

int main() {
    
    int mat[4], *p, x;

    p = mat + 1; 
    //p = mat++;
    //p = ++mat;
    x = (*mat)++;
    return 0;
}