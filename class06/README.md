# Comunicação em Grupo (CG)

- Forma mais simples de comunicação: UNICAST
- Forma mais comum de comunicação em grupo: MULTICAST (ou One-to-Many)
  - Permite o envio de uma mensagem para um grupo (com 1 operação), que será então recebida por todos os processos do grupo
  - Isto é mais eficiente do que "feixes" de comunicação UNICAST
  - O remetente não precisa conhecer os destinatários
  - CG é um exemplo de **comunicação indireta**, que em um sistema distribuído pode envolver um intermediário sem acoplamento direto entre remetente e destinatários
  - RPC e RMI são exemplos de acoplamento direto
  - O uso de um intermediário pode permitir:
    - Não acoplamento espacial: o remetente não conhece ou precisa conhecer a identidade dos destinatário e vice-versa
    - Não acoplamento temporal: remetente e destinatários podem ter tempos de vida não coincidentes

|                          | Acoplamento Temporal                                                                                      | Não Acoplamento Temporal                                                                                                    |
|--------------------------|-----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------|
| Acomplamento Especial    | - Comunicação direta entre remetente e destinatário - Destinatário deve existir no envio - Mensagens, RMI | - Comunicação direta entre remetente e destinatário - Remetente e destinatário podem ter tempos de vida diferentes - E-mail |
| Não Acoplamento Espacial | - Remetente não precisa conhecer destinatários - Destinatários devem existir no envio - Multicast IP      | - Remetente não precisa conhecer destinatários - Destinatários podem ter tempos de vida diferentes - JGroups                |

- Não confundir com *não acoplamento temporal* com comunicação assíncrona (envio sem bloqueio)
- Desvantagens da comunicação indireta:
  - Desempenho
  - Dificuldade maior de gerenciamento
- Aplicações:
  - Disseminação de informações
  - Aplicações colaborativas
  - Implementação de tolerância a falhas
  - Suporte ao monitoramento e gerenciamento
  - Etc.
- A comunicação em grupo é um exemplo de comunicação indireta em que se permite o envio de mensagens para grupos de pocesos, sendo geralmente implementadas sobre MULTICAST IP e permitindo:
  - Gerenciamento de membros
  - Detecção de falhas
  - Confiabilidade
  - Garantia de ordenação
- Conceitos-chave:
  - Grupo + membership
  - Processos se associam (join) a um grupo para enviar mensagens para seus membros de forma confiável
  - Grupos podem ser:
    - Abertos ou fechados
    - Com sobreposição ou sem sobreposição
    - Hierárquizados
    - Simétricos
    
  # Tópicos de Implementação
  
  - Funcionalidades
    - Criação e gerênciamento de grupos
    - Associação (join_ e saída (leave)
    - Envio (send) e recebimento (receive)
  - Garantias
    - Acesso às mensagens do grupo
    - Ordenação
    - Confiabilidade (integridade e validade)
    - Concordância (atomicidade = todos recebem ou nenhum recebe)

  - Tipos de ordenação
    - Ordenação absoluta: mensagens chegam na mesma ordem em que são enviadas
      !(https://github.com/taschetto/distributedProgramming/blob/master/class06/img/ordenacaoabsoluta.png)
    - Ordenação consistente ou total: mensagens são recebidas por todos na mesma ordem
      !(https://github.com/taschetto/distributedProgramming/blob/master/class06/img/ordenacaoconsistente.png)
    - Ordenação causal: se o evento de envio de uma mensagem causa o evento de envio de outra mensagen, então estas mensagens são enviadas a todos os receptores na mesma ordem (m1 -> m3 : m3 causada por m1)
