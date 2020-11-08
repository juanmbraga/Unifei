# Esquema do codigo

## Notas
- E preciso verificar se listas existem, se todas serao inicializadas no inicio da main, e so poderao ser apagadas no fim do programa?
  
## 1. criaLista(int tipo)
*desempenha papel comum*

Gera um no descritor generico, adequando o tipo de lista recebido. 

- Passagem do tipo e necessaria?
- Poderiam ser definidas na main...

## 2. liberaFila(Fila* fila)
*desempenha papel comum*

Contem loop que limpa todos os elementos e nos descritores de uma lista generica qualquer. 

## 3. tamanhoFila(Fila* fila)
*desempenha papel comum*

Retorna o tamanho guardado no no descritor da fila. 

## 4. enfileirar(?)
*PROBLEMA - Deixar por ultimo*

Inserir uma das senhas em uma das listas.

### Para fila de senhas
- dado: numero simples (int)
- tipo: numero 0 (zero)

### Para filas de espera
- dado: numero da senha (int)
- dado: informacoes da lista (exemplo: XP)
- Solucao: uma string? limitaria o numero de senhas
- Solucao: uma string e um int? 
- Solucao: um vetor de 3 inteiros? os 2 primeiros lidos como char, e o terceiro como numero mesmo
- Solucao: dois inteiros, um para senha e outro para indicar qual lista.
- Solucao: apenas um inteiro para a senha, e usar um dado "tipo" (int) no descritor para definir o tipo e deixar a responsabilidade para a main

### Problema: Argumentos da funcao
- Receber a senha na chamada? 
  - um argumento (int)
- Retirar uma senha diretamente da pilha de senhas? 
  - dois argumentos (Fila*) + (int)
- Receber indicacao de qual lista de espera? 
  - dois argumentos (int) ou (char) + (int)
- Escrever baseado no tipo do no descritor generico?
  - reduziria um argumento, apenas a fila e um inteiro (int)
- Como a manipulacao seria diferente para a fila de senhas e de espera, como fazer a verificacao dos tipos?
  - Senhas tem tipo 0 (zero) e o inteiro e salvo em variavel int
  - Fila de espera tem tipos maiores que zero, o inteiro e salvo na terceira casa do vetor (dado[3]) ou variavel (int)
  - Informacao sobre a lista nao precisara ser passada, funcao escreve baseado no tipo salvo no no descritor, em vetor de char ou de int
- (Sera que nao seria melhor fazer funcoes separadas para cada tipo de lista?)

## 5. desenfileirar(Fila* fila)
*desempenha papel comum*

Pode ser usada para ambas as filas, uma vez que retira apenas um elemento generico do final, assim como o dado. 

## 6. consultaInicio(Fila* fila)
*desempenha papel comum*

### Como implementar?
- Imprime o valor do primeiro item da lista passada? NAO
  - Verifica o tipo de lista baseado no no descritor para imprimir os diferentes dados para imprimir
- Retorna o valor do primeiro item? SIM
  - Teria mais um argumento (indesejavel?), e daria para usar o retorno para verificacao
  - Necessario, pois e preciso para passar o numero quando a pessoa tira uma senha
- Criar funcoes separadas, pois retornar um valor adicional (o int indicando o tipo da lista alem do int da senha em si) requeriria o retorno do struct 
- Remover a parte de passar o tipo da lista por parametro, assim a main fica encarregada de imprimir de acordo com o tipo de lista solicitada.
- Ou fazer o programa retornar o struct com os dados? seria preciso disponibilizar na main e nao deixar em .c. Melhor nao.

### Para que servira? (olhar na proposta)
- Ler um dado de senha para passar para funcao de adicionar na fila de espera (parametro ou retorno ou ~~impressao~~)
- Ler o dado do primeiro item da lista (aqui nao e preciso passar por parametro, apenas imprimir)
  - Seria possivel configurar a saida para retornar zero quando a lista estiver vazia (usar senhas a partir de 1)
  - Seria isso uma gambiarra? usar uma funcao para consultar o primeiro item, mas fazer isso de maneira diferente? (procurar como outros fizeram)

## 7. imprimeFila(Fila* fila)
*desempenha papel comum*

Imprime todos os itens de uma dada fila de espera (nao e preciso imprimir a de senhas, ja que nao foi solicitado)