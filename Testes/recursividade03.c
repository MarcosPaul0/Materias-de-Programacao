#include <stdio.h>
#include <stdlib.h>

int mamc(int m, int n) {
    if (n == 0) {
        return m;
    }
    return mamc(n, m % n);
}

int main() {
    int num1, num2;
    do
    {
        printf("Digite dois números inteiros válidos:");
        scanf(" %d", &num1);
        scanf(" %d", &num2);
    } while (num1 < 0 || num2 < 0);
    
    printf("O maior múltiplo comum entre %d e %d é [%d].", num1, num2, mamc(num1,num2));
    return 0;
}