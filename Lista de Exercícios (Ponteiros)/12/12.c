#include <stdio.h>

void comprarBTC (int *balance, int compra) {
   
    *balance = *balance + compra;
    *(balance + 1) = *(balance + 1) - compra;

    printf("Total BTC = %d\n", *balance);
    printf("Compre mais que ainda da tempo!\n");

}

void venderUSD (int *balance, int venda) {
    
    *balance = *balance + venda;
    *(balance + 1) = *(balance + 1) - venda;
    
    printf("Total USD = %d\n", *balance);
    printf("Venda mais que ainda da tempo!\n");
}

int main()
{
    int operation; 
    int usd=100;
    int balance[2] = {100, 100};
    void (*pf_array[]) (int* , int) = {comprarBTC, venderUSD};
    
    printf("Digite a operação desejada: \n");
    scanf("%d", &operation);
    (*pf_array[operation])(&balance, usd);
   
    return 0;
}

