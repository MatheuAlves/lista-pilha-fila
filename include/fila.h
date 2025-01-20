#ifndef FILA_H
#define FILA_H

#include "cliente.h"

typedef struct No {
    Cliente cliente;       // Cliente na fila
    struct No* proximo;    // Ponteiro para o próximo nó
} No;

typedef struct {
    No* frente;    // Início da fila
    No* tras;      // Fim da fila
} Fila;

// Funções da fila
void criarFila(Fila* fila);
void enfileirar(Fila* fila, Cliente cliente);
void atender(Fila* fila);
void exibirFila(Fila* fila);
int filaVazia(Fila* fila);
int quantidadeFila(Fila* fila);

#endif // FILA_H
