/*
2.Crie um registro (struct) ALUNO que contenha os seguintes campos:
  
    int matricula;
    char nome[50];
    int dia\_nasc;
    int mes\_nasc;
    ano\_nasc;
    float nota;

Escreva um programa que leia o número n de alunos a serem cadastrados. Em seguida, um vetor V com n 
posições deve ser alocado dinamicamente usando uma função que retorna um ponteiro do tipo ALUNO.
O programa deve preencher o vetor V e imprimir o registro dos alunos aprovados, isto é, com nota 
maior ou igual a 6,0. Para executar tais tarefas devem ser criadas funções para:

(a) Alocar memoria dinamicamente para um vetor do tipo ALUNO;
(b) Preencher o vetor de alunos.
(c) Imprimir o vetor de alunos [aprovados].
(d) Preencher o registro de um aluno.
(e) Imprimir o registro de um aluno.
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int matricula;
    char nome[50];
    int dia;    //pelo menos a minha IDE (Visual Studio Code) nao aceitou colocar "\_"
    int mes;
    int ano;
    float nota;

} ALUNO;    

//interpretei a funcao (c), de imprimir vetor de alunos, como sendo para alunos aprovados. 
//ja que havia duvida entre salvar os aprovados em um novo vetor, ou imprimi-los ao checar,
//optei pelo segundo caso.

ALUNO* alocaVetor(int quantidade);
void preencheVetor(ALUNO* vetor, int quantidade);
void imprimeVetor(ALUNO* vetor, int quantidade);
void preencheRegistro(ALUNO* vetor, int posicao);
void imprimeRegistro(ALUNO* vetor, int posicao);


int main (void) {

    int quantidade;
    ALUNO* vetor;

    system("cls");

    do {
        printf("Insira a quantidade de alunos: ");
        scanf("%d", &quantidade);
    } while (quantidade < 1);

    vetor = alocaVetor(quantidade);
    preencheVetor(vetor, quantidade);
    imprimeVetor(vetor, quantidade);
    
    free(vetor);
    
    printf("\n\nPrograma encerrado.");
    
    return 0;
}


ALUNO* alocaVetor(int quantidade) {

    return malloc(quantidade*sizeof(ALUNO));

}


void preencheVetor(ALUNO* vetor, int quantidade) {

    printf("\nPreenchendo os dados dos alunos.\n");

    for (int i=0; i<quantidade; i++) {

        preencheRegistro(vetor, i);
    }
}


void preencheRegistro(ALUNO* vetor, int posicao) {
    //supondo um usuario inteligente

    printf("Numero de matricula do %do aluno: ", posicao+1);
    scanf("%d", &vetor[posicao].matricula);
    printf("Nome: ");
    scanf(" %[^\n]", vetor[posicao].nome);
    printf("Data de nascimento: \nDia: ");
    scanf("%d", &vetor[posicao].dia);
    printf("Mes: ");
    scanf("%d", &vetor[posicao].mes);
    printf("Ano: ");
    scanf("%d", &vetor[posicao].ano);
    printf("Nota: ");
    scanf("%f", &vetor[posicao].nota);

    printf("\n");
}

void imprimeVetor(ALUNO* vetor, int quantidade) {
    int contador=0;

    printf("Os alunos aprovados sao:");
    //determinar numero de aprovacoes e imprimir em seguida
    for (int i=0; i<quantidade; i++) {  
        if (vetor[i].nota >= 6) {

            imprimeRegistro(vetor, i);
            contador++;
        }
    }

    if (contador == 0) {
        printf(" nao houveram aprovacoes.");
    }
}

void imprimeRegistro(ALUNO* vetor, int posicao) {

    printf("\n\n%d. Numero de matricula aluno: %d", posicao+1, vetor[posicao].matricula);
    printf("\n   Nome: %s", vetor[posicao].nome);
    printf("\n   Data de nascimento: %d/%d/%d", vetor[posicao].dia, vetor[posicao].mes, vetor[posicao].ano);
    printf("\n   Nota: %.2f", vetor[posicao].nota);

}