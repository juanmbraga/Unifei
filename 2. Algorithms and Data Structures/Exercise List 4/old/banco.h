
#include <stdio.h>
#include <stdlib.h>

#define SE 0
#define XP 1    //Caixa Preferencial
#define XC 2    //Caixa Convencional
#define NP 3    //Negocio Preferencial
#define NC 4    //Negocio Convencional



// disponibilizar "Fila" para uso na main
typedef struct descritor Fila;



///   Prototipos das funcoes principais   ///

// cria fila generica para "senhas" (0) ou "filas" (1)
Fila* criaFila(int tipo); 
//retornos: NULL= erro ou tipo incorreto; !NULL= sucesso 

// gera uma fila de senhas do tamanho recebido
int geraSenhas(Fila* fila, int atendimentos);
//retornos: 1= nao existe; -1= nenhum atendimento; 2= fila de perfil errado; 0= sucesso

// Recebe vetor com filas, retira senhas e as insere noutras (atualizando o numero de atendimentos)
int retirarSenhas(Fila* filas[], int atendimentos[]);
//retornos: -1= filas nao existem; 0= sucesso



///   Prototipos das funcoes secundarias   ///

// libera as filas, os descritores e os dados
int liberaFila(Fila* fila);   
//retornos: 1= nao existe; 0= sucesso

// retorna o tamanho de uma fila (-1 = fila nao existe)
int tamanhoFila(Fila* fila);      
//retornos: -1=nao existe; (>=0)= tamanho 

// adiciona um elemento ao final de uma fila
int enfileirar(Fila* fila, int dado);     
//retornos: 1= nao existe; 2= senha invalida; 0= sucesso

// remove o primeiro item da fila 
int desenfileirar(Fila* fila);        
//retornos: 1= nao existe; 2= vazia;    
//(poderia retornar o valor desenfileirado, economizando o "consultaInicio")

// retorna o primeiro valor na fila
int consultaInicio(Fila* fila); 
//retornos: (>0)= senha; 0=vazia; -1= nao existe
//(poderia tambem ser construida uma string com as letras da senha, mas ja que o printf na main e inevitavel, optei por retornar apenas a senha)

// imprime todos os valores presentes na fila
void imprimirFila(Fila* fila);
//sem retornos

//  padrao: variaveis comecam com minusculas, e tipos definidos com maiusculas