# Sistema de Gestão de Filas em Supermercado

## Descrição do Projeto
Este projeto visa desenvolver um sistema de gestão de filas para os caixas de um supermercado, onde clientes com diferentes prioridades (como idosos, gestantes e pessoas com deficiência) têm um atendimento preferencial. O sistema foi implementado em C e utiliza estruturas de dados como listas encadeadas e filas com prioridade para organizar o atendimento de maneira eficiente e justa.

## Objetivos

O objetivo principal deste sistema é simular o gerenciamento de filas em um supermercado com o foco na priorização de atendimento para clientes com necessidades especiais, garantindo que a fila de cada caixa seja organizada de acordo com a prioridade dos clientes.

## Requisitos

### Estruturas de Dados

1. **Cliente**
   - **Nome**: Máximo de 100 caracteres.
   - **CPF**: Um número inteiro de 11 dígitos.
   - **Prioridade**: Um número inteiro (1 - Alta, 2 - Média, 3 - Baixa).
   - **Número de Itens no Carrinho**: Um número inteiro representando a quantidade de itens no carrinho do cliente.

2. **Caixa**
   - **Número de Identificação**: Um número inteiro que representa o identificador único de cada caixa.
   - **Estado do Caixa**: Se o caixa está aberto ou fechado.

3. **Fila**
   - Cada caixa possui uma fila própria de clientes, onde os clientes com maior prioridade (menor número) são atendidos antes.

### Funcionalidades do Sistema

O sistema oferece as seguintes operações:

1. **Cadastrar um Cliente**
   - Solicita o nome, CPF, prioridade e número de itens no carrinho.
   - Adiciona o cliente à fila de acordo com sua prioridade e o caixa escolhido.

2. **Atender um Cliente**
   - Remover o cliente com maior prioridade da fila para ser atendido no caixa especificado.

3. **Abrir ou Fechar um Caixa**
   - Permite ao usuário abrir ou fechar um dos 5 caixas disponíveis.
   - Se um caixa for fechado, os clientes na fila desse caixa devem ser realocados para outros caixas abertos.

4. **Imprimir a Lista de Clientes em Espera**
   - Exibe os dados dos clientes em espera, organizados por prioridade, para cada caixa.

5. **Imprimir o Status dos Caixas**
   - Exibe o estado (aberto ou fechado) de cada caixa e o número de clientes em espera.

### Funcionalidades Especiais

- **Filas com Prioridade**: Cada caixa possui uma fila com prioridade para atendimento. Clientes com prioridade mais alta (1) são atendidos antes.
  
- **Gerenciamento de Caixas**: O sistema começa com 5 caixas abertos. O usuário pode abrir ou fechar caixas, mas não pode adicionar mais caixas. Quando um caixa é fechado, os clientes na fila desse caixa são redistribuídos para os caixas abertos.

## Estrutura do Sistema

- **Estruturas**:
  - **Cliente**: Representa o cliente com nome, CPF, prioridade e número de itens no carrinho.
  - **Caixa**: Representa o caixa com seu número de identificação e estado (aberto ou fechado).
  - **Fila**: Cada caixa possui uma fila de clientes, que é organizada com base na prioridade do cliente.

- **Listas Encadeadas**: São utilizadas para armazenar os clientes nas filas de cada caixa, permitindo a inserção e remoção eficientes de clientes.

## Implementação

O programa foi implementado em linguagem C e utiliza as seguintes funções principais:

- **Funções de Cadastro**: Para adicionar novos clientes às filas de acordo com a prioridade.
- **Funções de Atendimento**: Para remover clientes da fila quando forem atendidos no caixa.
- **Funções de Gerenciamento de Caixas**: Para abrir e fechar caixas e realocar clientes de caixas fechados.
- **Funções de Impressão**: Para exibir as informações de clientes nas filas e o status dos caixas.

