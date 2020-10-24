
/////////////////////////////
/// PROTÓTIPO DAS FUNÇÕES //
///////////////////////////

//redefinir tipo para possibilitar uso na main
typedef struct complexo complex;

//função para criar e alocar is numeros imaginários//
complex* criarComplexo(float a, float b);

//função que libera a alocação de memória do num
void liberaComplexo (complex* num);

//função que imprime um numero complexo
void imprimeComplexo(complex* num);

//função de soma dos numeros complexos
complex* somaComplexo (complex* num1, complex* num2);

//função de subtração dos numeros complexos
complex* subtraiComplexo (complex* num1, complex* num2);

//função de multiplicação dos números complexos
complex* multiplicaComplexo (complex* num1, complex* num2);

//função de divisão dos numeros complexos
complex* divideComplexo (complex* num1, complex* num2);