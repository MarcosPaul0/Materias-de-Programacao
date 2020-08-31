#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, num2;
    printf("Digite um numero inteiro: ");
    scanf("%i", &num);
    num2 = num;
    printf("%i", num2);
    for (num; num > 0; num--) {
        for (num2; num2 > 0; num2--) {
            printf("#");
        }
    }
    return 0;
}