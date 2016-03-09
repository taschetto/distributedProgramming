# Introdução à Programação Distribuída (continuação)

## Tipos de SD
 - SD pervasivos: formados por equipamentos de tamanho pequeno alimentados por bateria, conexão sem fio e grande mobilidade;
 - Sistemas de informação distribuídos muito encontrados em empresas e organizações, são caracterizados pelo uso de middleware com função de fornecer interoperabilidade para aplicações de rede;
 - Sistemas de computação distrbuídos usam complexas infraestruturas computacionais para melhorar o desempenho de aplicações distribuídas e paralelas:
   - Cluster computing;
   - Grid computing;

## Arquiteturas Distribuídas

 - Modelo cliente-servidor: o cliente solicita serviços ao servidor, que é responsável pelo processamento (two-tier);
  - Servidor: aceita requisições e gera respostas, desempenhando um serviço;
  - Clientes: enviam requisições a um ou mais servidores;
  - É o mais usado na internet;
  - Simples;
  - Centralização;
  - Escalabilidade não é boa;
  - Three-tier: arquitetura cliente-servidor em que interface, regras de negócio e armazenamento correspondem a módulos independentes;
  - N-tier: diferentes serviços são disponibilizados por servidores de aplicação e serviços podem consumir outros serviços;
 - Modelo peer-to-peer (P2P): todos os processos são "iguais" e devem interagir entre si para resolver um problema
  - Processos iguais (peer): processos com a mesma implementação e que podem atuar, conforme a necessidade, como clientes ou servidores;
  - Todos os processos são capazes de desempenhar as mesmas funções;
  - Interação cooperativa;
  - Maior complexidade;
  - Tendência: boa escalabilidade;
 - Cluster (fortemente acoplado): conjunto de máquinas interligadas por uma rede dedicada sendo usado para aplicações que executam processos em várias máquinas;
 - Baseado em infraestrutura: a infraestrutura cria a ilusão de um único espaço de endereçamento;

## Exemplos

 - Serviços p/ compartilhamento de arquivos (S.A.D.);
 - Internet;
 - Intranets;
 - Computação móvel e ubíqua;
 - Seti@Home;
 - MOSIX;
 - VCLUSTER;
 - Jogos em rede;
 - Torrent;
 - EIC;
 
## Requisitos de Projeto

 - Heterogeneidade
  - Um SD é formado por diferentes redes, SOs e processadores com representações internas de dados diferentes;
  - Solução = middleware;
  - Linguagens como Java são uma alternativa interessante;
 - Abertura
  - Padrões abertos com especificação e documentação disponíveis, permitindo entender e estender o sistema;
  - Independência de fornecedor;
 - Segurança
  - É preciso garantir confidencialidade, integridade e disponibilidade;
  - Uso de soluções baseadas em criptografia;
 - Escalabilidade
  - O sistema deve funcionar efetivamente e eficientemente com qualquer número/tamanho de usuários, dados e recursos;
  - Evitar centralização;
  - Usar estruturas de dados adequadas;
 - Tratamento de Falhas
  - Objetivo: manter a disponibilidade do sistema mesmo na ocorrência de falhas;
  - Detecção, mascaramento, tolerância, recuperação;
  - Palavra-chave: redundância;
 - Concorrência
  - É uma qualidade natural de um SD;
  - É preciso garantir exclusão mútua no acesso a recursos compartilhados;
 - Transparência
  - Esconder a separação física de componentes de forma que o sistema seja como um sistema único;
    - Acesso (recursos locais e remotos acessados da mesma forma);
    - Localização;
    - Acesso + localização = rede;
    - Concorrência;
    - Replicação;
    - Falhas;
    - Mobilidade;
    - Escala;
