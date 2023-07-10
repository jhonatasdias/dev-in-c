#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cliente.h"
#include "contrato.h"
#include "festa.h"


void cadastramentoContrato(){
    CONTRATOS contrato;
    FESTAS festa;

    int resposta;
    printf("\ec\e[3J");
    do{
        printf("\n\n");
        printf("Digite uma das opçoes a baixo:\n1-Incluir contrato\n2-Listar \n3-Localizar \n4-Alterar status\n0-Sair.\n");
        scanf("%d",&resposta);
        switch(resposta) {
        case 1: inserirContrato(&contrato, festa); break;
        case 2: listarContratos(contrato);break;
        case 3: pesquisarContrato(contrato);break;
        case 4: altererarStatusContrato(&contrato);break;
        case 0: break;
        default: printf("Opcao invalida.\n");
        }
    }while(resposta != 0);
    printf("\ec\e[3J");
}

void inserirContrato(CONTRATOS *contrato, FESTAS festa){
    printf("\ec\e[3J");
    //fazendo a leitura dos contratos exisentes cara a identificacao do id do proximo cliente;
    int codigoContrato = 1;


    FILE *arquivo2;
    arquivo2 = fopen("cadastroContratos.dat","rb");
    if(arquivo2 == NULL){
    printf("Criando o Primero Arquivo.\n");
    }else{
        while(fread(contrato, sizeof(CONTRATOS), 1, arquivo2) == 1){
            codigoContrato++;
        }
        fclose(arquivo2);
    }



    int codigoFesta;
    float valorTotalContratoFesta;
    float valorDescontoContratoFesta;
    float valorFinalContratoFesta;
    int formaPagamentoContratoFesta;
    int finded = 0;
    do{
        printf("\nDigite o codigo da Festa no qual sera implementado em contrato: \nDigite 0     para sair.\n");
        scanf("%d", &codigoFesta);
        if(codigoFesta == 0){
            break;
        }
        finded = verificaFesta(festa, *contrato ,codigoFesta, &valorTotalContratoFesta, &valorDescontoContratoFesta, &valorFinalContratoFesta, &formaPagamentoContratoFesta);
    }while(finded == 0) ;

    if(codigoFesta == -1){
        return;
    }
    FILE *arquivo;
    arquivo = fopen("cadastroContratos.dat", "a+b");
    if(arquivo == NULL){
    printf("Criando o Primero Arquivo.\n");
    }
    lerContrato(contrato, codigoContrato, codigoFesta,  valorTotalContratoFesta, valorDescontoContratoFesta, valorFinalContratoFesta, formaPagamentoContratoFesta);
    fwrite(contrato, sizeof(CONTRATOS), 1, arquivo);
    fclose(arquivo);
}



int verificaFesta(FESTAS festa, CONTRATOS contrato ,int codigoFesta, float *valorTotalContratoFesta, float *valorDescontoContratoFesta, float *valorFinalContratoFesta, int *formaPagamentoContratoFesta ){
    printf("\ec\e[3J");
    int find = 0;
    FILE *arquivo;
    arquivo = fopen("cadastroFesta.dat", "rb");
    if(arquivo == NULL){
        printf("Criando o nenhuma festa cadastrada.\n");
        return 0;
    }

    int posicaoFesta;

    while(fread(&festa, sizeof(FESTAS), 1, arquivo) == 1){
        if(festa.codFesta == codigoFesta){
            find = 1;
            break;
        }
    }

    fclose(arquivo);

    FILE *arquivo1;
    arquivo1 = fopen("cadastroContratos.dat", "rb");
    if(arquivo1 == NULL){
        printf("Criando primeiro contrato");
    }else{
        while(fread(&contrato, sizeof(CONTRATOS), 1, arquivo1) == 1){
            if(contrato.codfesta == codigoFesta){
                find = 2;
            }
        }
    }
    fclose(arquivo1);

    posicaoFesta =   - 1;
    if(find == 1){
        printf("\n\nA Festa a seguir foi encontrada corretamente - %s \n", festa.temaDaFesta);
        *valorTotalContratoFesta = festa.valorDaFesta.valorTotal;
        *valorDescontoContratoFesta = festa.valorDaFesta.desconto;
        *valorFinalContratoFesta = festa.valorDaFesta.valorFinal;
        *formaPagamentoContratoFesta = festa.formaDePag;
        return 1;
    }else if(find == 2){
        printf("ERRO: contrato da festa já cadastrada.");
        return 0;
    }else{
        printf("\nERRO: Festa nao encontrada\n\n");
        return 0;
    }
    return 0;
    return 1;
}


void lerContrato(CONTRATOS *contrato, int codigoContrato, int codigoFesta, float valorTotalContratoFesta, float valorDescontoContratoFesta, float valorFinalContratoFesta, int formaPagamentoContratoFesta){
    contrato->codContrato = codigoContrato;
    contrato->codfesta = codigoFesta;
    contrato->valorTotalContrato = valorTotalContratoFesta;
    contrato->valorDescontoContrato = valorDescontoContratoFesta;
    contrato->valorFinalContrato =valorFinalContratoFesta;
    contrato->formaPagamentoContrato = formaPagamentoContratoFesta;
    contrato->status = 1;

}


void listarContratos(CONTRATOS contrato){
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};
    char *status [3] = {"NAO PAGO", "PAGO", "CANCELADO"};
    printf("\ec\e[3J");
    FILE *arquivo = fopen("cadastroContratos.dat", "rb");
    if(arquivo == NULL){
        printf("ERRO: Contratos nao foram cadastrados ainda no arquivo");
        exit(1);
    }
    int find = 0;
    while (fread(&contrato, sizeof(CONTRATOS), 1, arquivo) == 1){
        if( contrato.status != 2){
            find = 1;
            printf("------------------------------\n");
            printf("| Contrato id: %d\n", contrato.codContrato );
            printf("| Codigo da Festa: %d\n", contrato.codfesta);
            printf("| Forma de pagamento: %s\n", formaDePagamento[contrato.formaPagamentoContrato]);
            printf("| Valor do contrato: %.02f \n", contrato.valorTotalContrato);
            printf("| Valor de desconto: %.02f\n", contrato.valorDescontoContrato);
            printf("| Valor Final: %.02f\n", contrato.valorFinalContrato);
            printf("| Status: %s\n", status[contrato.status]);
            printf("------------------------------ \n\n");
       }
    }
    if(find == 0){
        printf("\n\nO sistema nao possui nenhum contrato ativo para ser listado \n\n");
        return;
    }
}

void pesquisarContrato(CONTRATOS contrato){
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};
    char *status [3] = {"NAO PAGO", "PAGO", "CANCELADO"};
    printf("\ec\e[3J");
    FILE *arquivo = fopen("cadastroContratos.dat", "rb");
    if(arquivo == NULL){
        printf("ERRO: Contratos nao foram cadastrados ainda no arquivo");
        exit(1);
    }
    int contratoPesquisado;
    printf("Digite um id do contrato para ser pesquisado: ");
    scanf("%d",&contratoPesquisado);
    int find = 0;
    if(contratoPesquisado <= 0){
        printf("\n\nCodigo do contrato selecionado invalido");
        return;
    }
    while (fread(&contrato, sizeof(CONTRATOS), 1, arquivo) == 1){
        printf("\n\n");
        if( contrato.codContrato == contratoPesquisado){
            find = 1;
            printf("------------------------------\n");
            printf("| Contrato id: %d\n", contrato.codContrato );
            printf("| Codigo da Festa: %d\n", contrato.codfesta);
            printf("| Forma de pagamento: %s\n", formaDePagamento[contrato.formaPagamentoContrato]);
            printf("| Valor do contrato: %.2f \n", contrato.valorTotalContrato);
            printf("| Valor de desconto: %.2f %%\n", (contrato.valorDescontoContrato*100));
            printf("| Valor Final: %.2f\n", contrato.valorFinalContrato);
            printf("| Status: %s\n", status[contrato.status]);
            printf("------------------------------");
            printf("\n\n");
        }
    }
    if(find == 0){
        printf("\n\nO contrato selecionado nao foi encontrado");
    }
}

void altererarStatusContrato(CONTRATOS *contrato){
    //Alteraçao do Status do Cliente específicado
    int id;
    printf("\ec\e[3J");
    printf("Digite o id do contrato o qual tera seu status alterado: ");
    fflush(stdin);
    scanf("%d", &id);

    //Caso id seja invalido
    if(id <= 0){
        printf("ID invalido.\n");
        return;
    }
    //fim do caso

    FILE *arquivo;
    arquivo = fopen("cadastroContratos.dat","r+b");
    if(arquivo == NULL){
        printf("ERRO: arquivo nao possui nenhum contrato cadastrado");
    }
    id = id - 1;
    //Caso Não encontre o cliente
    fseek(arquivo, sizeof(CONTRATOS)*(id), 0);
        if (fread(contrato, sizeof(CONTRATOS), 1, arquivo) != 1) {
        printf("Contrato nao encontrado.\n");
        fclose(arquivo);
        return;
    }
    //fim do caso
    fseek(arquivo, sizeof(CONTRATOS)*(id), 0);
    fread(contrato,sizeof(CONTRATOS), 1, arquivo);
    int alteracaoDesejada = 0;
    int erro = 0;
    char *status [3] = {"NAO PAGO", "PAGO", "CANCELADO"};
    if(contrato->status == 1){
        do{
        erro = 0;
        printf("STATUS: %s \n\n", status[contrato->status]);
        printf("Digite uma das opcoes: \n1- NAO PAGO\n2- CANCELADO\n0-Sair\n");
        scanf("%d", &alteracaoDesejada);
        if(alteracaoDesejada == 1){
            contrato->status = 0;
            erro = 0;
        }else if(alteracaoDesejada == 2){
            contrato->status = 2;
            erro = 0;
        }else if(alteracaoDesejada == 0){
            erro = 0;
        }
        else{
            printf("\nERRO: opcao invalida");
            erro = 1;
        }
        if(erro == 1) break;;
        }while(erro == 1);
    }
    if(contrato->status == 2){
        do{
        erro = 0;
        printf("STATUS: %s \n", status[contrato->status]);
        printf("Digite uma das opcoes: \n1- PAGO\n2- NAO PAGO\n0-Sair\n");
        scanf("%d", &alteracaoDesejada);
        if(alteracaoDesejada == 1){
            contrato->status = 1;
            erro = 0;
        }else if(alteracaoDesejada == 2){
            contrato->status = 0;
            erro = 0;
        }else if(alteracaoDesejada == 0){
            erro = 0;
        }
        else{
            printf("\nERRO: opcao invalida");
            erro = 1;
        }
        if(erro == 1) break;
        }while(erro == 1);
    }
    if(contrato->status == 0){
        do{
        erro = 0;
        printf("STATUS: %s \n", status[contrato->status]);
        printf("Digite uma das opcoes: \n1- PAGO\n2- CANCELADO\n0-Sair\n");
        scanf("%d", &alteracaoDesejada);
        if(alteracaoDesejada == 1){
            contrato->status = 1;
            erro = 0;
        }else if(alteracaoDesejada == 2){
            contrato->status = 2;
            erro = 0;
        }else if(alteracaoDesejada == 0){
            erro = 0;
        }
        else{
            erro = 1;
            printf("\nERRO: opcao invalida");
        }
        if(erro == 1) break;;
        }while(erro == 1);
    }
    fseek(arquivo, sizeof(CONTRATOS)*(id), 0);
    fwrite(contrato, 1, sizeof(CONTRATOS), arquivo);
    fclose(arquivo);


}
//Aterar as formas de Status;
