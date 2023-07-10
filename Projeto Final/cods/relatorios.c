#include <stdio.h>
#include <stdlib.h>
#include "festa.h"
#include "cliente.h"

void impressaoRelatorio(){
    int resposta;

    do{
        printf("\n\n---Relatorio---\n");
        printf("1 -> Imprimir Festas cadastradas do Cliente - (pelo ID)\n");
        printf("2 -> Imprimir todas as Festas cadastradas por data - (DD/MM/AAAA)\n");
        printf("0 -> Retornar ao menur anterior\n:");
        scanf("%d", &resposta);

        switch(resposta){
            case 1: imprimirClienteFesta(); break;
            case 2: imprimirFestaData(); break;
            case 0: break;
        default: printf("Opcao invalida.\n");
        }
    } while(resposta != 0);
    return;
}

void imprimirClienteFesta(){
    char* dia_semana[7] = {"Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    int idClien;
    int cont=0, ultId;

    FESTAS festa;
    CLIENTES cliente;

    FILE *arquivoCliente, *arquivoFesta;
    // Arquivo do Cliente
    arquivoCliente = fopen("cadastroCliente.dat", "rb");
    if(arquivoCliente == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    // Arquivo da Festa
    arquivoFesta = fopen("cadastroFesta.dat", "rb");
    if(arquivoFesta == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    printf("Digite o Id do Cliente: ");
    scanf("%d", &idClien);

    fseek(arquivoFesta, -sizeof(FESTAS), SEEK_END);
    fread(&festa, sizeof(FESTAS), 1, arquivoFesta);

    ultId = festa.codFesta;

    fseek(arquivoFesta, 0, SEEK_SET);

    // Cliente não encontrado
    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1){
        if(idClien != festa.codFCliente){
            cont++;
        }
        if(cont == ultId){
            printf("Id nao encontrado\n");
            fclose(arquivoCliente);
            fclose(arquivoFesta);
            return;
        }
    }

    fseek(arquivoFesta, 0, SEEK_SET);

    fseek(arquivoCliente, sizeof(CLIENTES)*(idClien - 1), SEEK_SET);
    fread(&cliente, sizeof(CLIENTES), 1, arquivoCliente);
    printf("Nome do usuario: %s [ID = %d] \n", cliente.nomeCliente, cliente.codCliente);

    // Relatiorio de Clientes
    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1){
        if(idClien == festa.codFCliente){
            printf("                   Tabela da Festa\n");
            printf("----------------------------------------------------------\n");
            printf("| Descricao               | Dados                        |\n");
            printf("----------------------------------------------------------\n");
            printf("| Cod da Festa            | %d\n", festa.codFesta);
            printf("| Cod do Fornecedor       | %d\n", festa.codFFornecedor);
            printf("| Tema da festa           | %s", festa.temaDaFesta);
            printf("| Quantidade de convidados| %d\n", festa.convidados);
            printf("| Data da Festa           | %02d/%02d/%d\n", festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano);
            printf("| Dia da Semana escolhido | %s\n", dia_semana[verificaDiaDaSemana(festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano)]);
            printf("| Hora de Inicio marcado  | %02d:%02d\n", festa.horarioInicio.hh, festa.horarioInicio.mm);
            printf("| Hora do Termino do festa| %02d:%02d\n", festa.horarioFim.hh, festa.horarioFim.mm);
            printf("| Valor da festa          | %.2f [%s]\n\n", festa.valorDaFesta.valorFinal, formaDePagamento[festa.formaDePag - 1]);
        }
    }

    fclose(arquivoCliente);
    fclose(arquivoFesta);
    return;
}

void imprimirFestaData(){
    char* dia_semana[7] = {"Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    int dia, mes, ano, ultId;
    int cont=0;

    FESTAS festa;
    FILE *arquivoFesta;
    // Arquivo da Festa
    arquivoFesta = fopen("cadastroFesta.dat", "rb");
    if(arquivoFesta == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    lerData(&dia, &mes, &ano);

    fseek(arquivoFesta, -sizeof(FESTAS), SEEK_END);
    fread(&festa, sizeof(FESTAS), 1, arquivoFesta);

    ultId = festa.codFesta;

    fseek(arquivoFesta, 0, SEEK_SET);

    // Cliente não encontrado
    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1){
        if((dia != festa.dataMarcada.dia) && (mes != festa.dataMarcada.mes) && (ano != festa.dataMarcada.ano)) {
            cont++;
        }
        if(cont == ultId){
            printf("Essa data nao possui cadastro\n");
            fclose(arquivoFesta);
            return;
        }
    }

    fseek(arquivoFesta, 0, SEEK_SET);

    // Relatiorio de Clientes
    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1){
        if((dia == festa.dataMarcada.dia) && (mes == festa.dataMarcada.mes) && (ano == festa.dataMarcada.ano)){
            printf("                      Tabela da Festa\n");
            printf("----------------------------------------------------------\n");
            printf("| Descricao                  | Dados                     |\n");
            printf("----------------------------------------------------------\n");
            printf("| Cod da Festa               | %d                          \n", festa.codFesta);
            printf("| Cod do Fornecedor          | %d                          \n", festa.codFFornecedor);
            printf("| Cod do Cliente             | %d                          \n", festa.codFCliente);
            printf("| Tema da festa              | %s", festa.temaDaFesta);
            printf("| Quantidade de convidados   | %d                          \n", festa.convidados);
            printf("| Data da Festa              | %02d/%02d/%d                  \n", festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano);
            printf("| Dia da Semana escolhido    | %s                          \n", dia_semana[verificaDiaDaSemana(festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano)]);
            printf("| Hora de Inicio marcado     | %02d:%02d                     \n", festa.horarioInicio.hh, festa.horarioInicio.mm);
            printf("| Hora do Termino do festa   | %02d:%02d                     \n", festa.horarioFim.hh, festa.horarioFim.mm);
            printf("| Valor da festa             | %.2f [%s]                    \n\n", festa.valorDaFesta.valorFinal, formaDePagamento[festa.formaDePag - 1]);

        }
    }

    fclose(arquivoFesta);
    return;
}
