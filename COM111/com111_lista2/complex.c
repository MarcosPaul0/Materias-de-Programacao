#include "stdio.h"
#include "stdlib.h"
#include "complex.h"

struct numComplexo {
    float a;
    float b;
};

complexo* criaComplexo(float a, float b) {
    complexo *num = (complexo*) malloc(sizeof(complexo));
    if (num == NULL) {
        return 0;
    }

    num->a = a;
    num->b = b;

    return num;
}

complexo* somaComplexa(complexo* p1, complexo* p2) {    // (a + bi) + (c + di) = (a + c) + (b + d)i
    complexo *soma = (complexo*) malloc(sizeof(complexo));
    if (soma == NULL) {
        return 0;
    }

    soma->a = p1->a + p2->a;
    soma->b = p1->b + p2->b;

    return soma;
}

complexo* subComplexa(complexo* p1, complexo* p2) {    // (a + bi) − (c + di) = (a − c) + (b − d)i
    complexo *sub = (complexo*) malloc(sizeof(complexo));
    if (sub == NULL) {
        return 0;
    }

    sub->a = p1->a - p2->a;
    sub->b = p1->b - p2->b;

    return sub;
}

complexo* multComplexa(complexo* p1, complexo* p2) {    // (a + bi)(c + di) = (ac − bd) + (bc + ad)i
    complexo *mult = (complexo*) malloc(sizeof(complexo));
    if (mult == NULL) {
        return 0;
    }

    mult->a = (p1->a * p2->a) - (p1->b * p2->b);
    mult->b = (p1->b * p2->a) + (p1->a * p2->b);

    return mult;
}

complexo* divComplexa(complexo* p1, complexo* p2) {    // (a + bi)/(c + di) = ((ac + bd)/(c2 + d2)) + ((bc − ad)/(c2 + d))i
    complexo *div = (complexo*) malloc(sizeof(complexo));
    if (div == NULL) {
        return 0;
    }

    div->a = ((p1->a * p2->a + p1->b * p2->b) / (p2->a * 2 + p2->b * 2));
    div->b = ((p1->b * p2->a - p1->a * p2->b) / (p2->a * 2 + p2->b));

    return div;
}

void imprimeNumComplex(complexo* resultado) {
    printf("%.2f + %.2fi", resultado->a, resultado->b);
}

void liberaComplexo(complexo* p) {
    free(p);
}