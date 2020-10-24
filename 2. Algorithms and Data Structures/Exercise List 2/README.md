# Lista de Exercícios 2

## Exercicio 1
Implemente um TAD para representar números complexos (*complex.h* e *complex.c*). Sabe-se
que um número complexo é representado por *a + bi*, onde *a* e *b* são números reais e *i* a unidade
imaginária. O TAD deve implementar as seguintes operações:

(a) Função para criar um número complexo, dados a e b.

(b) Função para liberar um número complexo previamente criado.

(c) Função para somar dois números complexos, retornando um novo número com o resultado da operação. Sabe-se que

1. *(a + bi) + (c + di) = (a + c) + (b + d)i*

(d) Função para subtrair dois números complexos, retornando um novo número com o resultado da operação. Sabe-se que

1. *(a + bi) − (c + di) = (a − c) + (b − d)i*

(e) Função para multiplicar dois números complexos, retornando um novo número com o resultado da operação. Sabe-se que

1. *(a + bi)(c + di) = (ac − bd) + (bc + ad)i*

(f) Função para dividir dois números complexos, retornando um novo número com o resultado da operação. Sabe-se que

1. *(a + bi)/(c + di) = ((ac + bd)/(c^2 + d^2)) + ((bc − ad)/(c^2 + d^2))i*

Escreva um programa principal main.c que use números complexos para testar as funções
implementadas na TAD. (*Sugestão: criar dois números complexos, executar todas as operações (+, -, *, /), imprimir os resultados e liberar a memória.*)

## Referência
Capítulo 12 do livro: CELES, W.; CERQUEIRA, R.; RANGEL J. L. Introdução a Estruturas de
Dados. 2a
ed. 2016.