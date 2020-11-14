# Lista de Exercícios 5 - Pseudo-Torre de Hanoi

## Considere um cenário abaixo onde são dados:

- Três tubos numerados de 1 a 3;
- Cinco cubos, identificados pelas vogais do alfabeto (A, E, I, O e U).
- Os tubos possuem uma abertura na parte inferior, por onde os cubos podem ser inseridos e removidos, apenas um por vez (ou seja, os cubos estarão empilhados dentro do tubo).
- Inicialmente, os tubos 2 e 3 estão vazios e o tubo 1 contém todos os cubos em ordem alfabética, sendo que o último inserido foi o cubo com a letra A.
- É necessário que os cubos sejam transferidos para o tubo 3 de forma que a ordem alfabética original seja sempre mantida (durante todo o processo de movimentação dos cubos).

| Tubo 1 | Tubo 2 | Tubo 3|
|:--------:|--------|-------|
| U |   |   | 
| O |   |   | 
| I |   |   |
| E |   |   |
| A |   |   |

## Escreva um programa que transfira os cubos do tubo 1 para o tubo 3, seguindo as seguintes instruções:

- Utilize as funções **empilhar()** e **desempilhar()** da TAD Pilha Dinâmica (link para codigo da prof), para transferir um cubo de um tubo para outro;
- Durante o processo todos os tubos podem ser utilizados para armazenamento auxiliar dos cubos.
- O programa deve ser interativo, ou seja, a cada movimentação o usuário deve escolher o tubo de
origem e o tubo de destino do cubo.
- A cada movimentação de cubo, imprima as três pilhas que representam os tubos.
- 
*Dica: utilize a ideia do algoritmo da Torre de Hanoi.*

## Credito

Exercicio passado pela professora [Elisa de Cassia Silva Rodrigues](https://github.com/elisa-rodrigues).

Agradecimento pela ajuda do monitor [Ricardo Dalarme](https://github.com/ricardodalarme) na parte de impressao recursiva.