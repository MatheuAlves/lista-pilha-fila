#include "caixa.h"
#include <stdio.h>
#include <stdlib.h>

Caixa criarCaixa(int id) {
    Caixa caixa;
    caixa.id = id;
    caixa.aberto = 1;
    
    // Aloca memória para a fila
    caixa.fila = (Fila*)malloc(sizeof(Fila));
    if (caixa.fila != NULL) {
        criarFila(caixa.fila);
    } else {
        printf("Erro ao alocar memória para a fila do caixa %d.\n", id);
    }
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

void realocarClientes(Caixa caixas[], int qtd_caixas, int id) {
    Caixa* caixa_origem = &caixas[id];

    while (!filaVazia(caixa_origem->fila)) {
        int menorFila = 9999;
        int caixaDestino = -1;

        for (int i = 0; i < qtd_caixas; i++) {
            if (caixas[i].aberto && i != id) {
                int fila_tamanho = quantidadeFila(caixas[i].fila);
                if (fila_tamanho < menorFila) {
                    menorFila = fila_tamanho;
                    caixaDestino = i;
                }
            }
        }

        if (caixaDestino != -1) {
            Cliente clienteTransferido = caixa_origem->fila->frente->cliente;

            atender(caixa_origem->fila); 

            enfileirar(caixas[caixaDestino].fila, clienteTransferido);
        } 
        else {
            printf("Não há caixas abertos para realocar clientes.\n");
            break;
        }
    }
}

void estadoCaixa(Caixa caixas[], int qtd_caixas) {
    int id;
    printf("Digite o ID do caixa que deseja alterar o estado: ");
    scanf("%d", &id);

    if (id <= 0 || id > qtd_caixas) {
        printf("Caixa inválido. Tente novamente.\n");
        return;
    }

    Caixa* caixa_selecionado = &caixas[id - 1];

    if (!caixa_selecionado->aberto) {
        // Se o caixa está fechado, ele pode ser aberto
        printf("\nCaixa %d Aberto!\n", id);
        caixa_selecionado->aberto = 1;
    } 
    else {
        // Verifica se todos os outros caixas estão fechados
        int todosFechados = 1;  // Assumimos inicialmente que todos estão fechados
        for (int i = 0; i < qtd_caixas; i++) {
            if (i != id - 1 && caixas[i].aberto) {  // Ignora o caixa que estamos verificando
                todosFechados = 0;  // Encontrou um caixa aberto
                break;
            }
        }

        // Se todos os outros caixas estão fechados e o atual está aberto, não podemos fechá-lo
        if (todosFechados) {
            printf("Não pode fechar o último caixa aberto.\n");
            return;
        }

        // Se houver clientes na fila, realocamos
        if (!filaVazia(caixa_selecionado->fila)) {
            printf("Realocando clientes antes de fechar o caixa...\n");
            realocarClientes(caixas, qtd_caixas, id - 1);
        }

        // Fecha o caixa
        caixa_selecionado->aberto = 0;
        printf("\nCaixa %d Fechado!\n", id);
    }
}

Fila* getFila(Caixa* caixa) {
    return caixa->fila; 
}

bool getEstado(Caixa* caixa) {
    return caixa->aberto;
}

bool validaCaixa(Caixa caixa, int qtd_caixas, int id) {
    if (getEstado(&caixa) == 1) { 
        if (id > 0 && id <= qtd_caixas) {  
            return 1;  
        } else {
            return 0;  
        }
    }
    return 0;
}

