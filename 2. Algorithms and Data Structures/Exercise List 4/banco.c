
#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

typedef struct elemento Elemento;
struct elemento {
    int dado;
    Elemento* proximo;
};

typedef struct descritor Fila;
struct descritor {
    char perfil[2];
    Elemento* inicio;
    Elemento* fim;
    int quantidade;
};


int geraSenhas(Fila* fila, int atendimentos){

    // verifica se fila existe
    if(fila == NULL){
        return 1;
    }

    // checar entrada de usuario e se deseja nao alocar nada
    if(atendimentos <= 0){
        return -1;  //caso a pessoa queira sair (definir no loop do menu)
    }

    // garantir que senhas estao sendo inseridas na fila correspondente 
    if(fila->perfil[0] != 'S'){
        return 2;
    }

    // enfileirar as senhas na lista 
    for(int i=1; i <= atendimentos; i++){
        enfileirar(fila, i);
    }

    return 0;
}


Fila* criaFila(int tipo){

    // valida o tipo
    if(tipo < 0 || tipo > 4){  
        return NULL;
    }

    // aloca um descritor
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if(fila != NULL){

        // definir o tipo de lista baseado na escolha do usuario
        switch (tipo) {
            case 0: 
                fila->perfil[0] = 'S';
                fila->perfil[1] = 'E';
                break;
            case 1:
                fila->perfil[0] = 'X';
                fila->perfil[1] = 'P';
                break;
            case 2:
                fila->perfil[0] = 'X';
                fila->perfil[1] = 'C';
                break;
            case 3:
                fila->perfil[0] = 'N';
                fila->perfil[1] = 'P';
                break;
            case 4:
                fila->perfil[0] = 'N';
                fila->perfil[1] = 'C';
                break;
            default:
                free(fila);
                return NULL;
        } 

        // inicializa os dados do descritor 
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->quantidade = 0;
    }

    return fila;
}                        


int liberaFila(Fila* fila){

    // verifica se fila existe
    if(fila == NULL){
        return 1;
    }

    // elemento temporario
    Elemento* atual;

    // limpar item por item
    while(fila->inicio != NULL){
        atual = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        fila->quantidade--;

        // limpar o elemento
        //free(atual->dado);    // nao mais necessario
        free(atual);
    }

    // limpar o descritor
    free(fila);

    return 0;
}


int tamanhoFila(Fila* fila){
    
    // verifica se fila existe
    if(fila == NULL){
        return -1;
    }
    
    // retorna o valor salvo da quantidade
    return fila->quantidade;
}


Elemento* criaElemento(){

    
    return (Elemento*) malloc(sizeof(Elemento));;
}


int enfileirar(Fila* fila, int senha){

    // verifica se fila existe
    if(fila == NULL){
        return 1;
    }

    // como programador pode inventar de passar manualmente, verificar senha
    if(senha < 1){
        return 2;
    }

    // alocar novo elemento
    Elemento* no = criaElemento();
    if(no == NULL){
        return -1;
    }

    // inserir a senha
    no->dado = senha;

    // se a fila estiver vazia
    if(fila->inicio == NULL){

        //  inserir o item no inicio da fila
        no->proximo = fila->inicio;
        fila->inicio = no;
        
    } else {

        // insira apos o ultimo item
        fila->fim->proximo = no;

    }

    // adicione o novo endereco do fim no descritor
    fila->fim = no;

    fila->quantidade++;
    
    return 0;
}


int desenfileirar(Fila* fila){

    // verifica se fila existe
    if(fila == NULL){
        return 1;
    }

    // verifica se lista esta vazia
    if(fila->inicio == NULL){
        return 2;
    }

    // retira o primeiro elemento da lista
    Elemento* no = NULL;
    no = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    fila->quantidade--;

    // libera o elemento retirado e seu dado interno
    //free(no->dado);   //nao mais necessario
    free(no);

    // se o elemento removido era o unico
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    return 0;
}


int consultaInicio(Fila* fila){

    // verifica se fila existe
    if(fila == NULL){
        return -1;
    }

    // verifica se fila esta vazia
    if(fila->quantidade == 0){
        return 0;
    }

    // quando for fila para senhas (apenas esta se inicia com S, e como a funcao de criar ja limita, e possivel economizar uma comparacao aqui)
    if(fila->perfil[0] == 'S'){

        return fila->inicio->dado;

    } 

    // quando for uma das filas de espera 
    // (presume-se que a funcao criaFila impediu a criacao de filas com codigo maior que 1 e menor que 1)
    return fila->inicio->dado;
}


void imprimirFila(Fila* fila){

    // verifica se fila existe
    if(fila == NULL){
        printf("\n\nFila nao existe! Tecle enter para continuar...");
        getchar();
        getchar();
        return;
    }

    // nao foi pedido para imprimir a lista de senhas (como apenas esta inicia com 'S', a comparacao adicional e dispensada)
    if(fila->perfil[0] == 'S'){
        return;
    }

    // verifica se a lista esta vazia
    if(fila->quantidade == 0){
        printf("\n\nA fila esta vazia! Tecle enter para continuar...");
        getchar();
        getchar();
        return;   //dispensa o uso de else
    }

    // imprimir as senhas uma a uma
    Elemento* atual = fila->inicio;

    printf("\n\nFila de senhas:\n");
    while(atual != NULL){
        
        printf("\n%c%c%d", fila->perfil[0], fila->perfil[1], atual->dado);
        
        atual = atual->proximo;
    }

    printf("\n\nFim da fila. Tecle enter para continuar...");
    getchar();
    getchar();
        
    return;
}


int retirarSenhas(Fila* filas[], int atendimentos[]){

    // verificar existencia das filas
    for(int i=0; i<5; i++){
        // caso alguma nao existir
        if(filas[i] == NULL){
            printf("\nFila(s) nao existe(m). Tecle enter para sair...");
            getchar();
            getchar();
            return -1;
        }
    }

    // determinar quantidade de senhas para o loop e declarar variaveis
    int senha, opcao, opcao2, tamanho = tamanhoFila(filas[SE]);

    for(int i=0; i<tamanho; i++){
        //limpar a tela
        system("clear");

        // informar a quantidade restante de senhas
        printf("\n[Senhas restantes: %d]", tamanho);

        // determinar o tipo de atendimento 
        printf("\nEscolha o tipo de atendimento: ");
        printf("\n\t1. Caixa");
        printf("\n\t2. Negocial");
        do{
            printf("\nOpcao: ");
            scanf("%d", &opcao);
        } while(opcao < 1 && opcao > 2);

        // determinar o perfil do usuario
        printf("\nAgora escolha o seu perfil: ");
        printf("\n\t1. Preferencial");
        printf("\n\t2. Convencional");
        do{
            printf("\nOpcao: ");
            scanf("%d", &opcao2);
        } while(opcao2 < 1 && opcao2 > 2);

        // definir o tipo de caixa e perfil
        if(opcao == 1 && opcao2 == 1){  //Caixa Preferencial
            opcao = XP;
        }
        else if(opcao == 1 && opcao2 == 2){ //Caixa Convencional
            opcao = XC;
        }
        else if(opcao == 2 && opcao2 == 1){ //Negocio Preferencial
            opcao = NP;
        }
        else if(opcao == 2 && opcao2 == 2){ //Negocio Convencional
            opcao = NC;
        }

        // ler a senha da fila
        senha = consultaInicio(filas[SE]);

        // inserir em uma das filas de espera e retirar da fila de senhas
        printf("A sua senha e: %c%c%d", filas[opcao]->perfil[0], filas[opcao]->perfil[1], senha);
        enfileirar(filas[opcao], senha);
        desenfileirar(filas[SE]);
        tamanho--;

        // atualizar quantia de senhas retiradas
        if(opcao == XP || opcao == XC){
            atendimentos[0]++;
        } else {
            atendimentos[1]++;
        }
        // Uma vez sendo obrigatorio retirar chamar todas as senhas, segundo a proposta, posso ja calcular o resultado na retirada.

        // imprimir fila correspondente
        imprimirFila(filas[opcao]);

        // repetir solicitacao a proxima chamada ate o penultimo
        if(i<tamanho-1){
            printf("\nTecle ENTER para solicitar a proxima senha...");
            getchar();
            getchar();
        }
    }

    printf("\n\nSenhas retiradas com sucesso! Tecle ENTER para retornar ao menu...");
    getchar();
    getchar();

    return 0;
}