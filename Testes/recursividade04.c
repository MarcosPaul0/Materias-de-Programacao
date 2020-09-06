#include <stdio.h>
#include <stdlib.h>

int funcaoH(int m, int n) {
    if (n == 1) {
        return m + 1;
    }
    if (m == 1) {
        return n+1;
    }
    return funcaoH(m, n - 1) + funcaoH(m - 1, n);
}

int main() {
    printf("O resultado é %d", funcaoH(3, 3));

    return 0;
}