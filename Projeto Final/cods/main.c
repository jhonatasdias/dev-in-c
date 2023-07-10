#include <stdio.h>
#include <stdlib.h>
#include "fornecedor.h"
#include "festa.h"
#include "relatorios.h"
#include "contrato.h"

int main()
{
    int resp;
    do{
        printf("\n\nProgama para gestao de festas, escolha as opcoes\n");
        printf("1 -> CLIENTE\n");
        printf("2 -> FORNECEDOR\n");
        printf("3 -> FESTA\n");
        printf("4 -> CONTRATO\n");
        printf("5 -> RELATORIOS\n");
        printf("0 -> SAIR\n:");
        scanf("%d", &resp);
        switch(resp){
            case 1: cadastramentoCliente();break;
            case 2: cadastramentoFornecedor();break;
            case 3: cadastramentoFesta();break;
            case 4: cadastramentoContrato(); break;
            case 5: impressaoRelatorio(); break;
            case 0: break;//sair do programa.
            default: printf("Opcao invalida - Aperte ENTER para continuar.\n");getchar();
        }
    }while(resp != 0);

    return 0;
}
