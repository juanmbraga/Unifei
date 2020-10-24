# Lista de Exercícios 3

## Exercicio 1
Modfique a TAD Lista Encadeada Simples apresentada em aula (ListaProfessora) para:

(a) Armazenar itens com a seguinte estrutura:

```C
struct aluno{
    int matricula;
    char nome[30];
    float nota;
};
```

(b) Incluir cinco novas funções que:

1. Receba duas listas e retorne uma terceira contendo as duas primeiras concatenadas.
2. Dada uma lista L1, crie e retorne uma cópia dela em L2 eliminando os valores repetidos (matrícula do aluno).
3. Dada uma lista L1, inverta a lista e armazene em L2. A função deve retornar a lista L2.
4. Verifique se a lista está ordenada ou não (crescente ou decrescente), de acordo com a matrícula do aluno.
5. Calcule e retorne o tamanho da lista dinâmica encadeada. A função deve ser recursiva.

## Referência
Capítulo 5 do livro: BACKES, A. Estrutura de Dados Descomplicada em Linguagem C. 2016.