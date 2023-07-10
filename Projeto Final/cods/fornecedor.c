#include <stdio.h>
#include <stdlib.h>
#include "fornecedor.h"
#include <ctype.h>

void cadastramentoFornecedor(){
    FORNECEDORES forncedor;
    int resposta;

    do{
        printf("\n\nCadastramento de Fornecedores\n");
        printf("1 -> Inserir\n");
        printf("2 -> Listar\n");
        printf("3 -> Alterar cadastro\n");
        printf("4 -> Pesquisar dados\n");
        printf("5 -> Alterar status (ativo/inativo)\n"); // Falta habilitar status e pesquisar somente ativos 1 - ATIVO / 0 - INATIVO
        printf("0 -> Retornar ao menur anterior\n:");
        scanf("%d", &resposta);

        switch(resposta){
            case 1: inserirFornecedor(&forncedor); break;
            case 2: listarFornecedor(forncedor); break;
            case 3: alterarCadastro(&forncedor); break;
            case 4: pesquisarDadosFornecedor(&forncedor);break;
            case 5: break; // Falta implementar essa função
            case 0: break;
        default: printf("Opcao invalida.\n");
        }
    } while(resposta != 0);
}

// Função Inserir um novo Fornecedor
void inserirFornecedor(FORNECEDORES *forncedor){
    FILE *arquivo;

    arquivo = fopen("cadastroFornecedor.dat", "a+b");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    // Cod do Fornecedor
    fseek(arquivo, 0, SEEK_END);
    if (ftell(arquivo) == 0) {
        forncedor->codFornecedor = 1;
    } else {
        fseek(arquivo, -sizeof(FORNECEDORES), SEEK_END);
        fread(forncedor, sizeof(FORNECEDORES), 1, arquivo);
        forncedor->codFornecedor++;
        fseek(arquivo, 0, SEEK_END);
    }

    leFornecedor(forncedor);

    fwrite(forncedor, sizeof(FORNECEDORES), 1, arquivo);

    fclose(arquivo);
}

// Função Listar Fornecedores cadastrados
void listarFornecedor(FORNECEDORES forncedor){
    FILE *arquivo = fopen("cadastroFornecedor.dat", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while(fread(&forncedor, sizeof(FORNECEDORES), 1, arquivo) == 1){
        printf("\n\nID [%d]\n", forncedor.codFornecedor);
        printf("Nome do Buffet: %s\n", forncedor.nomeBuffet);
        printf("Numero do teledone: %d\n", forncedor.telefoneFornecedor);
    }

    fclose(arquivo);

}

// Titulo
void leFornecedor(FORNECEDORES *forncedor){
    forncedor->status = 1;
    printf("\n\nDigite o nome do Buffet: ");
    fflush(stdin);
    fgets(forncedor->nomeBuffet, sizeof(forncedor->nomeBuffet), stdin);
    printf("Digite o numero do telefone: ");
    scanf("%d", &forncedor->telefoneFornecedor);
}

// Titulo
void alterarCadastro(FORNECEDORES *forncedor){
    int id;
    FILE *arquivo = fopen("cadastroFornecedor.dat", "r+b");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    printf("Digite o numero de identificacao para alterar os dados do fornecedor: ");
    scanf("%d", &id);
    if(id <= 0){
        printf("ID invalido.\n");
        return;
    }
    // Fornecedor não identificado
    fseek(arquivo, (id - 1) * sizeof(FORNECEDORES), 0);
    if (fread(forncedor, sizeof(FORNECEDORES), 1, arquivo) != 1) {
        printf("Fornecedor nao encontrado.\n");
        fclose(arquivo);
        return;
    }
    // Inicialização da alteração dos dados
    printf("Digite o nome do Buffet: ");
    fflush(stdin);
    fgets(forncedor->nomeBuffet, sizeof(forncedor->nomeBuffet), stdin);
    printf("Digite o numero do telefone: ");
    scanf("%d", &forncedor->telefoneFornecedor);
    // Gravar dados alterado no arquivo;
    fseek(arquivo, (id - 1) * sizeof(FORNECEDORES), 0);
    fwrite(forncedor, sizeof(FORNECEDORES), 1, arquivo);
    // Fechar arquivo
    fclose(arquivo);
    printf("Fornecedor alterado com sucesso.\n");
}

// Titulo
void pesquisarDadosFornecedor(FORNECEDORES *forncedor){
    int resposta;
    // Pesquisa por ID e por nome
    do{
        printf("\n\nPesquisa de Dados do Fornecedor\n");
        printf("1 -> Pesquisa pelo ID\n");
        printf("2 -> Pesquisar pelo Buffet\n");
        printf("0 -> Retornar ao menur anterior\n:");
        scanf("%d", &resposta);

        switch(resposta){
            case 1: pesquisaId(); break;
            case 2: pesquisaNome(); break;
            case 0: break;
        default: printf("Opcao invalida.\n");
        }
    } while(resposta != 0);

    return;
}

void pesquisaNome(){
    char *nomeDesejado[100];
    char *nomeMin[100];
    char *cadasMin[100];
    int cont=0, ultId;
    FORNECEDORES fornecedor;
    FILE *arquivoFornecedor = fopen("cadastroFornecedor.dat", "rb");
    if(arquivoFornecedor == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    printf("Digite o Buffet a ser pesquisado: ");
    scanf("%s", nomeDesejado);

    strcpy(nomeMin, nomeDesejado);

    fseek(arquivoFornecedor, -sizeof(FORNECEDORES), SEEK_END);
    fread(&fornecedor, sizeof(FORNECEDORES), 1, arquivoFornecedor);
    ultId = fornecedor.codFornecedor;

    fseek(arquivoFornecedor, 0, SEEK_SET);

    // Sai da função caso não exista
    while (fread(&fornecedor, sizeof(FORNECEDORES), 1, arquivoFornecedor) == 1) {
        converterParaMinusculo(nomeMin);
        strcpy(cadasMin, fornecedor.nomeBuffet);
        converterParaMinusculo(cadasMin);
        if (strncmp(cadasMin, nomeMin, strlen(nomeMin)) != 0) {
            cont++;
        }
        if(cont == ultId){
            printf("Fornecedor nao encontrado\n");
            return;
        }
    }

    fseek(arquivoFornecedor, 0, SEEK_SET);

    // Informa dados existente
    while (fread(&fornecedor, sizeof(FORNECEDORES), 1, arquivoFornecedor) == 1) {
        converterParaMinusculo(nomeMin);
        strcpy(cadasMin, fornecedor.nomeBuffet);
        converterParaMinusculo(cadasMin);
        if (strncmp(cadasMin, nomeMin, strlen(nomeMin)) == 0) {
            // Nome encontrado
            printf("Fornecedor encontrado:\n");
            printf("\n\nID [%d]\n", fornecedor.codFornecedor);
            printf("Nome do Fornecedor: %s\n", fornecedor.nomeBuffet);
            printf("Numero do telefone do Fornecedor: %d\n", fornecedor.telefoneFornecedor);
        }
    }
    fclose(arquivoFornecedor);
    return;
}

void pesquisaId(){
    int id;
    FORNECEDORES fornecedor;
    FILE *arquivoFornecedor = fopen("cadastroFornecedor.dat", "rb");
    if(arquivoFornecedor == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    printf("Digite o numero de identificacao para pesquisar os dados do fornecedor: ");
    scanf("%d", &id);
    // Verificacao - id inexistente
    if(id <= 0){
        printf("ID invalido.\n");
        return;
    }
    // Verificacao - invalido
    fseek(arquivoFornecedor, (id - 1) * sizeof(FORNECEDORES), 0);
    if(fread(&fornecedor, sizeof(FORNECEDORES), 1, arquivoFornecedor) != 1){
        printf("Fornecedor nao encontrado.\n");
        return;
    }
    printf("\n\nID [%d]\n", fornecedor.codFornecedor);
    printf("Nome do Fornecedor: %s\n", fornecedor.nomeBuffet);
    printf("Numero do telefone do Fornecedor: %d\n", fornecedor.telefoneFornecedor);
    fclose(arquivoFornecedor);

}
