#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Digite dois numeros inteiros: ");
    scanf("%i%i", &num1, &num2);

    if (num1 < num2) {
        for (num1; num1 <= num2; num1++) {
            printf("%i  ", num1);
        }
    }
    else
    {
        for (num2; num2 <= num1; num2++) {
            printf("%i  ", num2);
        }
    }
    
    return 0;
}