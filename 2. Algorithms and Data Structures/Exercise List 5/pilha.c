#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

// definicao do tipo elemento
struct elemento{
    char dado;
    Elemento *proximo;
};

//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    Elemento* topo;
    int quantidade;
};


Pilha* criarPilha(void){
    // Alocar dinamicamente 
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    // Inicializar em caso de sucesso na alocacao
    if(pilha != NULL){
        pilha->topo = NULL;
        pilha->quantidade = 0;        
    }

    // Retorne o endereco alocado
    return pilha;
}


int liberarPilhas(Pilha* pilha[3]){

    // Repetir para todos as possiveis pilhas
    for(int i=0; i<3; i++){

        // Caso a pilha ja esteja vazia
        if(pilha[i] == NULL){
            continue;
        }

        int atual;

        // Liberar todos os elementos
        while(pilha[i]->topo != NULL){
            atual = pilha[i]->topo;
            pilha[i]->topo = pilha[i]->topo->proximo;
            free(atual);
        }

        free(pilha[i]);
    }

    return 0;
}


int tamanhodaPilha(Pilha* pilha){
    // Checa a existencia da fila
    if (pilha == NULL)
        return -1;

    return pilha->quantidade;
}


Elemento* criarElemento(){
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    return no;
}


int empilhar(Pilha* pilha, char dado){
    // Checa a existencia da fila
    if (pilha == NULL){
        return -1;
    }

    // Verificar ordem alfabetica (A<E<I<O<U)
    if(consultarTopoPilha(pilha) < dado){
        return 1;
    }

    // Inserir elemento 
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    // Em caso de erro ao alocar
    if(no == NULL){
        return -1;
    }

    // Atribuir valores e inserir na pilha
    no->dado = dado;
    no->proximo = pilha->topo;
    pilha->topo = no;
    pilha->quantidade++;

    return 0;
}


char desenpilhar(Pilha* pilha){
    // Checar existencia ou se pilha esta limpa
    if(pilha == NULL || pilha->quantidade == 0){
        return 0;
    }

    char dado;
    Elemento* no;

    // Salva dado temporariamente
    dado = pilha->topo->dado;

    // Remove e libera primeiro item
    no = pilha->topo;
    pilha->topo = no->proximo;
    free(no);
    pilha->quantidade--;

    // Convenientemente retorna o dado
    return dado;
}


char consultarTopoPilha(Pilha* pilha){
    if(pilha == NULL || pilha->topo == NULL){
        return 0;
    }

    return pilha->topo->dado;
}


int transferir(Pilha* entrega, Pilha* recebe){
    // Verificar se nenhuma entrada e nula
    if(entrega == NULL || recebe == NULL){
        return -1;
    }

    // Verificar se pilha de entrega nao esta vazia
    if(entrega->topo == NULL){
        return 2;
    }

    // Ver se usuario nao escolheu a mesma pilha
    if(entrega == recebe){
        return 3;
    }

    // Tentar inserir consultando o tipo da lista (para nao remover)
    int temp = empilhar(recebe, consultarTopoPilha(entrega));

    // Se estiver fora de ordem
    if (temp == 1){
        return 1;
    }

    // Caso transferencia tenha sido um sucesso
    desempilhar(entrega);

    //empilhar(recebe, desempilhar(entrega));   // Usar o resultado de empilhar pode evitar checagens
    //potencialmente alterar a funcao empilhar para 
    //  usar a linha 158 logo no inicio da funcao talvez seja interessante

    return 0;
}


void imprimePilhas(Pilha* pilha[3]){
    Elemento* atual[3];
    char temp[3];

    printf("\n");
    printf(" 1    2    3")

    // Salve os enderecos do inicio
    for(int i=0; i<3; i++){
        atual[i] = pilha[i]->topo;
    }

    // Repetir por todas as cinco casas das pilhas
    for(int i=0; i<5; i++){ 
        
        // Copiar os dados para veriaveis
        for(int j=0; j<3; j++){
            temp[j] = atual[j]->dado;
            // Em caso de fim da lista ter sido atingido, troque por espaco
            if(temp[j] == 0) temp[j] = ' ';
        }

        // Imprime os valores
        printf("|%c|  |%c|  |%c|", temp[0], temp[1], temp[2]);

        // Busca o endereco das proximas "casas" da pilha
        for (int j=0; j<3; j++){
            atual[j] = atual[j]->proximo;
        }
    }

    return;
}

void pausa (){
    printf("\n\nTecle ENTER para continuar...");
    getchar();
    getchar();
    return;
}