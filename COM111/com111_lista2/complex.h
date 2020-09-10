typedef struct numComplexo complexo;

complexo* criaComplexo(float a, float b);

complexo* somaComplexa(complexo* p1, complexo* p2);

complexo* subComplexa(complexo* p1, complexo* p2);

complexo* multComplexa(complexo* p1, complexo* p2);

complexo* divComplexa(complexo* p1, complexo* p2);

void imprimeNumComplex(complexo* resultado);

void liberaComplexo(complexo* p);