#include "cliente.h"
#include "caixa.h"
#include <stdio.h>

int main() {
    int qtd_caixas = 5;
    int id;
    Caixa caixas[qtd_caixas];
    Fila* fila;
    Cliente cliente;
    int opcao;

    for(int i = 0; i < qtd_caixas; i++){
        caixas[i] = criarCaixa(i + 1);
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar Novo Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Mudar o estado de algum caixa\n");
        printf("4. Ver todas as filas\n");
        printf("5. Ver todos os caixas\n");
		printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
			case 0:
                printf("Saindo...\n");
                break;
            case 1:
                cliente = cadastrarCliente();
                do{
                    printf("\nDigite o ID do caixa que deseja inserir o cliente: ");
                    scanf("%d", &id);
                } while (!(validaCaixa(caixas[id-1], qtd_caixas, id)));
                fila = getFila(&caixas[id-1]);
                enfileirar(fila, cliente);
                break;
            case 2:
                do{
                    printf("Digite o ID do caixa que deseja atender o cliente: ");
                    scanf("%d", &id);
                } while (!(validaCaixa(caixas[id-1], qtd_caixas, id)));
                fila = getFila(&caixas[id-1]);
                atender(fila);
                break;
            case 3:
                estadoCaixa(caixas, qtd_caixas);
                break;
            case 4:
                printf("\nFILAS:\n");
                for(int i = 0; i < qtd_caixas; i++){
                    printf("Caixa: %d\n", i+1);
                    fila = getFila(&caixas[i]);
                    exibirFila(fila);
                    printf("----------------------------------------------------------\n");
                }
                break;
            case 5:
                printf("\nCAIXAS:\n");
                for(int i = 0; i < qtd_caixas; i++){
                    exibirCaixa(&caixas[i]);
                    printf("----------------------------------------------------------\n");
                }
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
