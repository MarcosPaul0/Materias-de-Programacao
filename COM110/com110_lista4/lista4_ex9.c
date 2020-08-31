#include <stdio.h>
#include <stdlib.h>

int main() {
    float percentage, up_percentage, car_speed, track_speed;
    char answer;
    do {printf("Digite a velocidade maxiam da via: ");
        scanf("%f", &track_speed);
        printf("Digite a velocidade do veiculo: ");
        scanf("%f", &car_speed);
        percentage = (car_speed / track_speed) * 100;
        if (percentage <= 100) {
            printf("Dentro do Limite");
        }
        if (percentage > 100 && percentage <= 120) {
            up_percentage = percentage - 100;
            printf("Ultrapassou %.0f%% do limite, multa de R$ 85,13.", up_percentage);
        }
        if (percentage > 120 && percentage <= 150) {
            up_percentage = percentage - 100;
            printf("Ultrapassou %.0f%% do limite, multa de R$ 127,69.", up_percentage);
        }
        if (percentage > 150) {
            up_percentage = percentage - 100;
            printf("Ultrapassou %.0f%% do limite multa, de R$ 574,62.", up_percentage);
        }
        printf("\nDeseja repetir? [s/n]");
        scanf(" %c", &answer);
    } while (answer == 's');

    return 0;
}
