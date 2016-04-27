# Alguns conceitos básicos

  - Plataforma: camadas de hardware e software de nível mais baixo;
  - Middleware: camada entre o sistema operacional e as aplicações, que **mascara a heterogeneidade** e provê um modelo conveniente mais de programação;
    - Corresponde a um conjunto de rotinas, processos e eventualmente objetos que interagem entre si para dar suporte para que as aplicações possam se comunicar e compartilhar recursos de uma forma mais conveniente;
    
    ```
    +------------------------+
    | Aplicações / Serviços  |
    +------------------------+
    |       Middleware       |
    +------------------------+   }
    |           OS           |   }
    +------------------------+   }---- PLATAFORMA
    |     Hardware + Rede    |   }
    +------------------------+   }
    ```
    
  - Serviço: componente que gerencia recursos e apresenta alguma funcionalidade a usuários e aplicações;
  - Operação: forma como os recursos gerenciados por um serviço são acessados;
  - Interface: relação de operações de um serviço;
  - Troca de mensagens: forma básica de comunicação entre processos em um sistema distribuído;
  - Invocação remota: interação completa (requisição + resposta)
  
# Stateless vs Stateful

  - Stateless significa que o estado do serviço não é levado em consideração entre 2 invocações remotas:
    - Cada repetição carrega suas próprias credenciais e é autenticada individualmente;
    - Servidores **não** mantêm informação do estado sobre clientes;
    - Não necessita estabelecer e fechar conexões;
    - Uma queda no servidor não afeta os clientes;
    - É simples;
    - Chamadas devem conter todo o estado (mais longas);
  - Stateful: significa que as requisições são orientadas à conexão, isto é, cada requisição está relacionada a alterações que foram feitas por requisições prévias;
    - Servidores mantêm informação de estado sobre clientes;
    - Chamadas mais curtas (contém no mínimo 1 identificação);
    - Problemas com quedas de servidores e clientes;

# Semânticas para invocação remota
  - Invocação remota = requisição + resposta;
  - Há garantias diferentes de acordo com as medidas de tolerância a falhas adotadas:
    - Reenvio de requisição;
    - Filtragem de duplicados;
    - Retransmissão de resultados;
  - Invocação local de método = semântica exactly-once
    - Semânticas para sistemas distribuídos:
      - Talvez (maybe): nenhuma medida;
      - Pelo menos uma vez (at-least-once): reenvio;
      - No máximo uma vez (at-most-once): todas;
    - Exemplos:
      - Sun RPC -> pelo menos uma vez;
      - Java RMI -> no máximo uma vez;
      - Corba -> no máximo uma vez ou talvez;
    - Neste contexto, **idempotência** (propriedade de executar várias vezes a mesma operação sem que o resultado se altere depois da primeira execução) é uma propriedade desejável para métodos remotos;

# Técnicas de Otimização

1. Balanceamento de Carga
  - Consiste em atribuir os processos de uma aplicação distribuída às estações de forma que o tempo total de execução seja o mais baixo possível;
  - Ao atribuir um processo a um processaor específico é preciso considerar o custo de comunicação que surgirá;
  - Abordagens p/ o escalonamento de carga:
    - Clustering: processos que se comunicam são colocados no mesmo nodo para reduzir custos de comunicação;
    - Co-scheduling: processos no mesmo grupo são espalhados na rede para explorer concorrência;
    - Balanceamento de carga: processos em nodos com alta carga são transferidos para nodos com baixa carga dinamicamente;
  - Algoritmos com balanceamento de carga podem ser:
    - Estáticos: buscam ums distribuição de tarefas ótima, usando clustering ou co-scheduling; não exploram flutuações de curso prazo;
    - Dinâmicos: coletam informação de estado do sistema e tomam decisões de escalonamento baseadas nelas;
    - Adaptativos: fazem balanceamento a cada novo job (como os dinâmicos) ou quando surgem anomalias na carga;
2. Caching
  - É utilizada para melhorar o desempenho do sistema no acesso a dados/arquivos;
  - Em um sistema distribuído, os dados podem estar armazenados: no disco do servidor, em uma cache na memória do servidor, na memória do cliente, no disco do cliente;
  - Quando os dados estão no cliente e ocorrem atualizações concorrentes aos dados é preciso considerar a consistência de cache;
  - Abordagens para a consistência de cache:
    - Write-through: todas as escritas são propagadas para o armazenamento estável imediatamente confiável, mas tem desempenho ruim;
    - Delayed-write: modificações são escritas na cache do cliente e enviadas ao servidor mais tarde ou periodicamente; um bloco de escrita maior é mais eficiente do que várias pequenas;
    - Write-on-close: modificações são enviadas ao servidor quando o arquivo é fechado,; pressupõe uma semântica orientada à conexão, reduz tráfego intermediário enquanto o arquivo está aberto;
  - Delayed-write e Write-on-close permitem agrupadas escritas redundantes ou pequenas, mas tem baixa confiabilidade e dados não enviados ao servidor podem ser perdidos.
3. Servidores Replicados
  - Melhora desempenho, escalabilidade e disponibilidade
  - Tipos de servidor replicado:
    - Máquinas de estados;
    - Dados com operações de leitura e escrita;
  - Políticas de Replicação:
    - Passiva: clientes interagem com um servidor principal, e os outros servidores que estão na reserva são atualizados antes da resposta ao cliente;
    -  Ativa: todos os servidores recebem os pedidos dos clientes, efetuam a operação, e decide-se por votação qual será a resposta final;
    - Comunicação em grupo é usada muitas vezes para viabilizar a comunicação nesses sistemas;
