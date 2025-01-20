#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100
#define MAX_CPF 12

typedef struct {
    char nome[MAX_NOME];
    char cpf[MAX_CPF]; 
    int prioridade;
    int numeroItens;
} Cliente;

// Protótipos das funções
Cliente criarCliente(const char* nome,const char* cpf, int prioridade, int numeroItens);
void exibirCliente(const Cliente* cliente);
Cliente cadastrarCliente();
void exibirClienteCadastrado(const Cliente* cliente);

#endif
