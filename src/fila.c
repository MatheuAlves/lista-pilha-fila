#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Função para inicializar a fila
void criarFila(Fila* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

// Função para enfileirar um cliente
void enfileirar(Fila* fila, Cliente cliente) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o cliente!\n");
        return;
    }

    novoNo->cliente = cliente;
    novoNo->proximo = NULL;

    // Se a fila estiver vazia, o novo nó será o primeiro e o último
    if (fila->frente == NULL) {
        fila->frente = novoNo;
        fila->tras = novoNo;
    } else {
        No* atual = fila->frente;
        No* anterior = NULL;

        // Percorre a fila para encontrar a posição adequada, com base na prioridade
        while (atual != NULL && atual->cliente.prioridade <= cliente.prioridade) {
            anterior = atual;
            atual = atual->proximo;
        }

        // Se o novo cliente tiver maior prioridade que o primeiro da fila
        if (anterior == NULL) {
            novoNo->proximo = fila->frente;
            fila->frente = novoNo;
        } else {
            anterior->proximo = novoNo;
            novoNo->proximo = atual;
        }

        // Se o cliente foi adicionado no final da fila, atualiza o ponteiro 'tras'
        if (novoNo->proximo == NULL) {
            fila->tras = novoNo;
        }
    }

    printf("FILA--------------------------------- \n");
    exibirFila(fila);
}


// Função para atender um cliente
void atender(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Não há clientes para atender.\n");
        return;
    }

    No* temp = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->tras = NULL; 
    }

    exibirClienteCadastrado(&temp->cliente);
    printf("Cliente Atendido!\n");
    free(temp);
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->frente == NULL;
}

// Função para exibir todos os clientes na fila
void exibirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    No* atual = fila->frente;
    while (atual != NULL) {
        exibirClienteCadastrado(&atual->cliente); // Usando a função que já existe
        atual = atual->proximo;
    }
}

int quantidadeFila(Fila* fila) {
    int contador = 0;
    No* atual = fila->frente;

    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return 0;
    }

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    printf("Quantidade de pessoas na fila: %d\n", contador);
    return contador;
}

