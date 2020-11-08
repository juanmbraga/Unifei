Para resolver o problema abaixo modifique a TAD Fila Dinâmica Encadeada Simples apresentada na
aula **(a incluir)**.

## Exercicio 1
Considere o cenário de distribuição de senhas em um atendimento bancário, no qual há uma mesa para
atendimento negocial e uma mesa para atendimento de caixa. Crie um programa que gere e distribua
as senhas conforme a ordem de chegada do cliente, o tipo de atendimento (caixa ou negocial) e o perfil
do cliente (preferencial ou convencional), de acordo com as etapas abaixo.

(a) Solicitar o limite diário de n atendimentos (Ex: 20 senhas);

(b) Criar uma fila de Senhas de Entrada (SE) com a sequência numérica de 0 até o limite diário de n
senhas;

(c) Criar uma fila para cada relação de atendimento e perfil de cliente. (Ex: (XP) Caixa Preferencial,
(XC) Caixa Convencional, (NP) Negocial Preferencial, (NC) Negocial Convencional);

(d) Criar um menu para retirada de senha:

1. Solicitar o tipo de atendimento (X) para Caixa e (N) para Negocial;

1. Solicitar o perfil do cliente (P) para Preferencial e (C) para Convencional;

1. Retirar da fila SE o número do atendimento para gerar a senha de acordo com o tipo de atendimento e o perfil do cliente (Ex: XP01, NC02, etc.);

1. Adicionar esta senha na fila do atendimento correspondente.

1. Imprimir a fila correspondente após a adição da senha nova.

(e) Criar um menu para chamada de senha:

1. Chamar aleatoriamente um tipo de atendendimento (Negocial ou Caixa);
1. A cada 2 chamadas de perfil de cliente Preferencial, chamar um perfil de cliente Convencional.
1. Imprimir a senha chamada.

(f) Encerrar o programa quando os n atendimentos diários forem realizados:

1. Verificar se todas as filas de senha e atendimento estão vazias.
2. Imprimir o número de atendimentos realizados por cada uma das mesas (Negocial ou Caixa).