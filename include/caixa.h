#ifndef CAIXA_H
#define CAIXA_H
#include <stdbool.h>
#include "fila.h" 

typedef struct {
    int id;
    bool aberto;
    Fila* fila;
} Caixa;

// Funções relacionadas ao caixa
Caixa criarCaixa(int id);
void exibirCaixa(const Caixa *caixa);
void estadoCaixa(Caixa caixas[], int qtd_caixas);
Fila* getFila(Caixa* caixa);
#endif // CAIXA_H
