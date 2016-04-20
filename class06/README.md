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
      !(https://github.com/taschetto/distributedProgramming/blob/master/class06/img/ordenacaoabsoluta.png?raw=true)
    - Ordenação consistente ou total: mensagens são recebidas por todos na mesma ordem
      !(https://github.com/taschetto/distributedProgramming/blob/master/class06/img/ordenacaoconsistente.png?raw=true)
    - Ordenação causal: se o evento de envio de uma mensagem causa o evento de envio de outra mensagen, então estas mensagens são enviadas a todos os receptores na mesma ordem (m1 -> m3 : m3 causada por m1)
      !(https://github.com/taschetto/distributedProgramming/blob/master/class06/img/ordenacaocausal.png?raw=true)

# Implementação Absoluta

- Método:
  - Usar timestamps globais identificando todas as mensagens
  - Exige relógios sincronizados
  - Kernel do receptor mantém mensagens recebidas, mas deve considerar que uma mensagem com o maior atraso pode chegar com timestamp menor do que a 1ª da fila
- Dificuldade: sincronizar relógios
- Muitas aplicações **não** necessitam deste tipo de ordenação

# Implementação de Ordenação Total ou Consistente

- Método 1:
  - Remetentes mandam as mensagens do grupo para um sequenciador
  - O sequenciador associa um número às mensagens e as envia para o grupo;
  - Receptor(es) salva(m) as mensagens e as entregam pela ordem de sequência
  - Este método está sujeito a um ponto único de falhas e, portanto, tem baixa confiabilidade
- Método 2: protocolo Abcast
  - Remetente atribui um número de sequência temporário à mensagem e faz o envio para todos os membros de grupo
  - Quando uma mensagem é recebida, o membro i do grupo retorna uma proposta de número de sequência, max(fmax, pmax) + 1 + i/N, onde
    - pmax = número máximo já proposto pelo recebedor i
    - fmax = número máximo já acordado no grupo
    - i = número do processo
    - N = número total de processos do grupo
  - Enviador recebe as propostas de números de sequência dos recebedores, opta pelo maior e envia "commit" com número escolhido
  - Número de sqeuência são sempre únicos
- Jgroups
  - Ferramente para comunicação confiável com grupos fechados de processos em Java
  - Baseado em Multicast IP, porém permite:
    - Transmissão sem perdas
    - Fragmentação
    - Ordenação
    - Atomicidade
    - Notificações quando houver alteração no grupo
