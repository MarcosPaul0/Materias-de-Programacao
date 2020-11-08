#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char a, char b, char c) {
    /* mova n discos do pino a para o pino b usando
    o pino c como intermediario                    */
       if (n == 1)
     printf("mova disco %d de %c para %c\n", n, a, b);
   else
   {
     hanoi(n - 1, a, c, b);                            // H1
     printf("mova disco %d de %c para %c\n", n, a, b);
     hanoi(n - 1, c, b, a);                            // H2
   }
}
 
int main(void) {
    int numDiscos;
    scanf("%d", &numDiscos);
    hanoi(numDiscos, 'A', 'B', 'C');
    return 0;
}