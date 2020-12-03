//Definindo o deque para ser usado na main
typedef struct deque Deque;

// funções para alocar e desalocar memória
Deque* gera_deque();
int liberar_deque(Deque **deq);

//funções para adicionar elementos no deque
int insere_inicio_deque(Deque* deq, char *nome);
int insere_fim_deque(Deque* deq, char *nome);

//funções para remover elementos do deque
int remove_inicio_deque(Deque* deq);
int remove_fim_deque(Deque* deq);

// funções para obter informações do deque
int tamanho_deque(Deque *deq);
int consultar_inicio_deque(Deque *deq, char *nome);
int consultar_fim_deque(Deque *deq, char *nome);
 
 //função para imprimir o deque
void imprimir_deque(Deque* deq);
