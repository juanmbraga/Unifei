
//Defining type, for it would not be accesible to use in main
typedef struct complexo complex;


//função para criar e alocar is numeros imaginários//
complex* makeComplex(float a, float b);

//função que libera a alocação de memória do num
void freeComplex(complex* num);

//função que imprime um numero complexo
void printComplex(complex* num);

//função de soma dos numeros complexos
void sumComplex(complex* num1, complex* num2, complex* result);

//função de subtração dos numeros complexos
void subtractComplex(complex* num1, complex* num2, complex* result);

//função de multiplicação dos números complexos
void multiplyComplex(complex* num1, complex* num2, complex* result);

//função de divisão dos numeros complexos
void divideComplex(complex* num1, complex* num2, complex* result);