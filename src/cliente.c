#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

Cliente criarCliente(const char* nome, const char* cpf, int prioridade, int numeroItens) {
    Cliente cliente;
    snprintf(cliente.nome, MAX_NOME, "%s", nome);
    snprintf(cliente.cpf, MAX_CPF, "%s", cpf);
    cliente.prioridade = prioridade;
    cliente.numeroItens = numeroItens;
    return cliente;
}

void exibirClienteCadastrado(const Cliente* cliente) {
    printf("\nCliente: %s\n", cliente->nome);
    printf("CPF: %s\n", cliente->cpf);
    printf("Itens: %d\n", cliente->numeroItens);
    printf("Prioridade: %d\n", cliente->prioridade);
}

int validarCPF(const char* cpf) {
    if (strlen(cpf) != 11) {
        printf("Erro: O CPF deve conter exatamente 11 dígitos.\n");
        return 0;
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("Erro: O CPF deve conter apenas números.\n");
            return 0;
        }
    }

    return 1;
}

int validarPrioridade(int prioridade) {
    if (prioridade == 1 || prioridade == 2  || prioridade == 3) {
        return 1;
    }
    else{
        printf("Erro: Você digitou um valor inválido!\n");
        return 0; 
    }
}

Cliente cadastrarCliente() {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    int prioridade, numeroItens;

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nome);

    do {
        printf("Digite o CPF (11 dígitos): ");
        scanf("%s", cpf);
    } while (!validarCPF(cpf));

    do {
        printf("Digite a prioridade (1: Alta, 2: Média, 3: Baixa): ");
        scanf("%d", &prioridade);
    } while (!validarPrioridade(prioridade));
    
    do {
        printf("Digite o número de itens no carrinho: ");
        scanf("%d", &numeroItens);
    } while (!(numeroItens > 0));

    Cliente cliente = criarCliente(nome, cpf, prioridade, numeroItens);

    printf("\nCliente cadastrado com sucesso!\n");
    exibirClienteCadastrado(&cliente);
    
    return cliente;
}
