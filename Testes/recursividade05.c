#include <stdio.h>
#include <stdlib.h>

int funcaoF(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return 2 * funcaoF(n - 1) + 3 * funcaoF(n - 2);
}

int main() {
    printf("O resultados deu %d.", funcaoF(5));

    return 0;
}