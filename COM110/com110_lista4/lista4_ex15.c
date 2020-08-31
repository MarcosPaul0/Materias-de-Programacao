#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Digite dois numero inteiros: ");
    scanf("%i%i", &num1, &num2);

    if (num1 >= num2) {
        for (num2; num2 < num1; num2++) {
            printf("%i x 1 = %i\n", num2, num2);
            printf("%i x 2 = %i\n", num2, num2 * 2);
            printf("%i x 3 = %i\n", num2, num2 * 3);
            printf("%i x 4 = %i\n", num2, num2 * 4);
            printf("%i x 5 = %i\n", num2, num2 * 5);
            printf("%i x 6 = %i\n", num2, num2 * 6);
            printf("%i x 7 = %i\n", num2, num2 * 7);
            printf("%i x 8 = %i\n", num2, num2 * 8);
            printf("%i x 9 = %i\n", num2, num2 * 9);
            printf("%i x 10 = %i\n", num2, num2 * 10);
            printf("\n\n");
        }
    }
    if (num1 < num2) {
        for (num1; num1 <= num2; num1++) {
            printf("%i x 1 = %i\n", num1, num1);
            printf("%i x 2 = %i\n", num1, num1 * 2);
            printf("%i x 3 = %i\n", num1, num1 * 3);
            printf("%i x 4 = %i\n", num1, num1 * 4);
            printf("%i x 5 = %i\n", num1, num1 * 5);
            printf("%i x 6 = %i\n", num1, num1 * 6);
            printf("%i x 7 = %i\n", num1, num1 * 7);
            printf("%i x 8 = %i\n", num1, num1 * 8);
            printf("%i x 9 = %i\n", num1, num1 * 9);
            printf("%i x 10 = %i\n", num1, num1 * 10);
            printf("\n\n");
        }
    }

    return 0;
}