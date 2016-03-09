# Introdução à Programação Distribuída

Programação/computação distribuída: desenvolvimento e execução de sistemas e aplicações que executam de forma paralela e descentralizada em 2 ou mais computadores interconectados

## Definições de sistemas distribuídos:
  - Aquele cujos componentes de hardware e software, localizados em computadores interconectados, se comunicam e coordenam as suas ações através de trocas de mensagens (Colouris et. al.)
  - Um SD é um conjunto de computadores independentes que se apresenta a seus usuários como um sistema único e coerente (Tanenbaum)
  - A DS is one in which the failure of a computer you didn't even know existed can render your own computer unusable (Lamport)

## Características:
  - Computadores (hardware) autônomos, porém o software cria abstrações que permitem que eles sejam vistos como um sistema único
  - Execução concorrente com compartilhamento de recursos
  - Troca de mensagens
  - Inexistência de relógio global
  - Falhas independentes
  - Muitas vezes componentes e recursos redundantes

## Motivação
  - Compartilhamento de recursos
  - Desempenho
  - Tolerância a falhas
  - Confiabilidade
  - Disponibilidade

## Contexto/evolução
  - Desde os primeiros sistemas, o principal objetivo sempre foi o desempenho:
    - open shop: 7% utilização, 4 jobs/hora
    - processamento batch: 55% utilização, 33 jobs/hora
    - fitas magnéticas: 90% utilização, jobs/hora
    - multiprogramação
    - time-sharing
    - programação concorrente (1 PC)
    - microcomputadores, computador pessoal, redes, etc
    - sistemas distribuídos (1979 - ...)
      - servidores remotos
      - SOs distribuídos
      - SAs distribuídos
      - Middleware

## Vantagens
  - Economia
  - Velocidade
  - Há aplicações inerentemente distribuídas
  - Confiabilidade e disponibilidade
  - Facilidade de expansão
  - Compartilhamento de recursos

# Desvantagens
  - Garantia de segurança
  - Complexidade de desenvolvimento e gerenciamento
  - Alto custo para implementar aplicações colaborativas
  - Dificuldade de depuração
