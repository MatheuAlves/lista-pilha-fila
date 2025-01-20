#include "caixa.h"
#include <stdio.h>
#include <stdlib.h>  // Para malloc

Caixa criarCaixa(int id) {
    Caixa caixa;
    caixa.id = id;
    caixa.aberto = 1;
    
    // Aloca memória para a fila
    caixa.fila = (Fila*)malloc(sizeof(Fila));
    if (caixa.fila != NULL) {
        criarFila(caixa.fila);  // Inicializa a fila
    } else {
        printf("Erro ao alocar memória para a fila do caixa %d.\n", id);
    }

    exibirCaixa(&caixa);
    return caixa;
}

void exibirCaixa(const Caixa *caixa) {
    printf("ID do Caixa: %d\n", caixa->id);
    if (caixa->aberto) {
        printf("Estado: Aberto\n");
    } else {
        printf("Estado: Fechado\n");
    }

    quantidadeFila(caixa->fila);
    printf("\n");
}

void estadoCaixa(Caixa caixas[], int qtd_caixas) {
    int id;
    printf("Digite o ID do caixa que deseja alterar o estado: ");
    scanf("%d", &id);

    // Verifica se o ID do caixa existe
    if (id <= 0 || id > qtd_caixas) {
        printf("ID inválido. Tente novamente.\n");
    } else {
        // Altera o estado do caixa selecionado (abre ou fecha)
        Caixa *caixa_selecionado = &caixas[id - 1];  // Ajusta para índice de 0 a qtd_caixas-1
        caixa_selecionado->aberto = !caixa_selecionado->aberto;  // Alterna o estado

        // Exibe o novo estado do caixa
        exibirCaixa(caixa_selecionado);
    }
}

Fila* getFila(Caixa* caixa) {
    return caixa->fila;  // Retorna diretamente o ponteiro para a fila
}
