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
void realocarClientes(Caixa caixas[], int qtd_caixas, int id);
void estadoCaixa(Caixa caixas[], int qtd_caixas);
Fila* getFila(Caixa* caixa);
bool getEstado(Caixa* caixa);
bool validaCaixa(Caixa caixa, int qtd_caixas, int id);
#endif // CAIXA_H
