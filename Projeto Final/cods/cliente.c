#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "festa.h"
//executar    gcc main.c cliente.c contrato.c -o main
//ender "nome"; você  consegue adicionar um agrupamento de dados em outra estrutura; "Uma estura dentro de outra estrutura"



void cadastramentoCliente(){
    CLIENTES cliente;
    int resposta;
    printf("\ec\e[3J");

    do{
        printf("\n\nDigite \n1-Inserir Cliente \n2-Listar \n3-Pesquisar\n4-Editar\n5-Alterar o status\n0- Sair\n");
        fflush(stdin);
        scanf("%d", &resposta);

        switch (resposta) {
        case 1: inserirCliente(&cliente);break;
        case 2: listarCliente(cliente);break;
        case 3: localizarCliente(cliente); break;
        case 4: editarcliente(&cliente); break;
        case 5: alterarStatusCliente(&cliente); break;
        case 0: break;
        default: printf("Opcao invalida.\n");
        }
    fflush(stdin);
    }while(resposta != 0 );
}





//inserir cliente
void inserirCliente(CLIENTES *cliente){
    printf("\ec\e[3J");
    int codigoCliente = 1;

    FILE *arquivo1;

    arquivo1 = fopen("cadastroCliente.dat", "rb");
    if(arquivo1 == NULL){
    printf("Criando o Primero Arquivo.\n");
    }else{
        //fazendo a leitura dos cliente exisentes cara a identificacao do id do proximo cliente;
        while(fread(cliente, sizeof(CLIENTES), 1 , arquivo1) == 1 ){
            codigoCliente++;
        }
        fclose(arquivo1);
    }



    FILE *arquivo;
    arquivo = fopen("cadastroCliente.dat", "a+b");

    if(arquivo == NULL){
    printf("Erro na abertura do arquivo.\n");
    exit(1);
    }

    lerCliente(cliente, codigoCliente);

    fwrite(cliente, sizeof(CLIENTES), 1, arquivo);


    fclose(arquivo);
}


//fazendo a simples captura dos dados do cliente;

void lerCliente(CLIENTES *cliente, int codigoCliente){   // ao passar o cliente por referência devemos utilizar a " ->" para específicar um ponot específico de uma struct específica;

    int erro = 0;

    cliente->codCliente = codigoCliente;
    cliente->status = 1;
    printf("\n\nDigite o nome do Cliente:");
    fflush(stdin);
    fgets(cliente->nomeCliente, sizeof(cliente->nomeCliente), stdin);
    printf("\nDigite o endereco do Cliente:");
    fflush(stdin);
    fgets(cliente->enderecoCliente, sizeof(cliente->enderecoCliente), stdin);
    printf("\nDigite o telefone do Cliente:");
    fflush(stdin);
    scanf("%d", &cliente->telefoneCliente);
    fflush(stdin);
    printf("\nDigite a data de nascimento do usuario.\n");
    do{
        erro = 0;
        printf("\nDia: ");
        fflush(stdin);
        scanf("%d", &cliente->dataNasc.dia);
        printf("Mes: ");
        fflush(stdin);
        scanf("%d", &cliente->dataNasc.mes);
        printf("Ano: ");
        fflush(stdin);
        scanf("%d", &cliente->dataNasc.ano );

        if(cliente->dataNasc.ano > 2023 || cliente->dataNasc.ano < 0 ){
            printf("\nAno digitado invalido");
            erro = 1;
        }else if (cliente->dataNasc.mes < 1 || cliente->dataNasc.mes > 12) {
            printf("\nMes digitado invalido");
            erro = 1;
        }else {
            int ultimoDia = 31;
            if(cliente->dataNasc.mes == 2){
                ultimoDia = 28;
            } else if(cliente->dataNasc.mes == 3 || cliente->dataNasc.mes == 5 || cliente->dataNasc.mes == 8 || cliente->dataNasc.mes == 10 ){
                ultimoDia = 30;
            }
            if(cliente->dataNasc.dia < 1 || cliente->dataNasc.dia > ultimoDia){
                printf("\nDia digitado invalido");
                erro = 1;
            }
            if (erro == 1) {
                printf("\n Por favor insira novamente ods dados da data de nascimento.");
            }
        }
    }while(erro == 1);

}



//Faz a listagem de todos os cliente existentes e ativos do arquivos;

void listarCliente(CLIENTES cliente){
    printf("\ec\e[3J");
    FILE *arquivo = fopen("cadastroCliente.dat", "rb");
    if(arquivo == NULL){
        printf("ERRO: clientes nao foram cadastrados ainda no arquivo");
        exit(1);
    }
    while (fread(&cliente, sizeof(CLIENTES), 1, arquivo) == 1){
        printf("\n\n");
        if( cliente.status == 1){
            printf("Id do usuario: %d\n", cliente.codCliente);
            printf("Nome do usuario: %s", cliente.nomeCliente);
            printf("Endereco do usuario: %s", cliente.enderecoCliente);
            printf("Numero de Telefone do Usuario: %d \n", cliente.telefoneCliente);
            printf("Data de nascimento do Usuario: %d / %d / %d", cliente.dataNasc.dia, cliente.dataNasc.mes, cliente.dataNasc.ano);
            printf("\n\n");
        }
    }
}




//Faz a localição de um cliente específico através de seu id
void localizarCliente(CLIENTES cliente ){
    printf("\ec\e[3J");
    int opcao;
    printf("Digite uma das opcoes para Localizar: \n1 - ID\n2 - Nome\n");
    fflush(stdin);
    scanf("%d", &opcao);
    if(opcao == 1){
        localizarClienteID(cliente);
    }else if(opcao == 2) {
        localizarClienteNome(cliente);
    }else {
    printf("ERRO: opcao invalida");
    }

}

void localizarClienteID(CLIENTES cliente){
    CLIENTES clienteDesejado;
    printf("\ec\e[3J");
    FILE *arquivo = fopen("cadastroCLiente.dat", "rb");
    if(arquivo == NULL){
        printf("ERRO: arquivo nao possui nenhum cliente cadastrado");
    }

        int localizarId = 0;
        printf("Digite o id no qual você deseja pesquisar: ");
        scanf("%d", &localizarId);
        //Caso o id seja inválido
        if(localizarId <= 0){
            printf("ID invalido.\n");
            return;
        }
        //fim do caso
        localizarId = localizarId - 1;
        fseek(arquivo, (sizeof(CLIENTES) * localizarId), 0);
        if (fread(&cliente, sizeof(CLIENTES), 1, arquivo) != 1) {
            printf("Cliente nao encontrado.\n");
            fclose(arquivo);
            return;
        }
        fseek(arquivo, (sizeof(CLIENTES) * localizarId), 0);
        fread(&clienteDesejado,sizeof(CLIENTES), 1, arquivo);
        printf("\n\nId do cliente: %d\n", clienteDesejado.codCliente);
        printf("Nome do cliente: %s", clienteDesejado.nomeCliente);
        printf("Endereco do cliente: %s", clienteDesejado.enderecoCliente);
        printf("Numero de Telefone do cliente: %d \n", clienteDesejado.telefoneCliente);
        printf("Data de nascimento do cliente: %d / %d / %d", clienteDesejado.dataNasc.dia, clienteDesejado.dataNasc.mes, clienteDesejado.dataNasc.ano);
        printf("\nStatus do Usuario: %d", cliente.status);
        printf("\n\n");

}

void localizarClienteNome(CLIENTES cliente){


    char nomeDesejado[100];
    char nomeMin[100];
    char cadasMin[100];
    int cont=0, ultId;
    FILE *arquivoCliente = fopen("cadastroCliente.dat", "rb");
    if(arquivoCliente == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    printf("Digite o Cliente a ser pesquisado: ");
    scanf("%s", nomeDesejado);

    strcpy(nomeMin, nomeDesejado);

    fseek(arquivoCliente, -sizeof(CLIENTES), SEEK_END);
    fread(&cliente, sizeof(CLIENTES), 1, arquivoCliente);
    ultId = cliente.codCliente;

    fseek(arquivoCliente, 0, SEEK_SET);

    // Sai da fun��o caso n�o exista
    while (fread(&cliente, sizeof(CLIENTES), 1, arquivoCliente) == 1) {
        converterParaMinusculo(nomeMin);
        strcpy(cadasMin, cliente.nomeCliente);
        converterParaMinusculo(cadasMin);
        if (strncmp(cadasMin, nomeMin, strlen(nomeMin)) != 0) {
            cont++;
        }
        if(cont == ultId){
            printf("cliente nao encontrado\n");
            return;
        }
    }

    fseek(arquivoCliente, 0, SEEK_SET);

    // Informa dados existente
    while (fread(&cliente, sizeof(CLIENTES), 1, arquivoCliente) == 1) {
        converterParaMinusculo(nomeMin);
        strcpy(cadasMin, cliente.nomeCliente);
        converterParaMinusculo(cadasMin);
        if (strncmp(cadasMin, nomeMin, strlen(nomeMin)) == 0) {
        printf("\n\nId do cliente: %d\n", cliente.codCliente);
        printf("Nome do cliente: %s", cliente.nomeCliente);
        printf("Endereco do cliente: %s", cliente.enderecoCliente);
        printf("Numero de Telefone do cliente: %d \n", cliente.telefoneCliente);
        printf("Data de nascimento do cliente: %d / %d / %d", cliente.dataNasc.dia, cliente.dataNasc.mes, cliente.dataNasc.ano);
        printf("\nStatus do Usuario: %d", cliente.status);
        printf("\n\n");
        }
    }
    fclose(arquivoCliente);
    return;



}






//Edicão de um cliente específicado

void editarcliente(CLIENTES *cliente){
    printf("\ec\e[3J");
    FILE *arquivo = fopen("cadastroCliente.dat","r+b");
    if(arquivo == NULL){
        printf("ERRO: arquivo nao possui nenhum cliente cadastrado");
    }

    int localizarCliente = 0;
    printf("\n\nDigite o Id do cliente no qual você deseja alterar os dados: ");
    scanf("%d", &localizarCliente);
    //Caso o id seja inválido
    if(localizarCliente <= 0){
        printf("ID invalido.\n");
        return;
    }
    //fim do caso

    localizarCliente = localizarCliente - 1;
    fseek(arquivo, (sizeof(CLIENTES)*localizarCliente), 0);

    //Caso o Clinente não seja encontrado
    if (fread(cliente, sizeof(CLIENTES), 1, arquivo) != 1) {
        printf("Cliente nao encontrado.\n");
        fclose(arquivo);
        return;
    }
    //fim do caso

    fseek(arquivo, (sizeof(CLIENTES)*localizarCliente), 0);
    fread(cliente, sizeof(CLIENTES), 1, arquivo);
    printf("Digite o nome do Cliete:");
    fflush(stdin);
    fgets(cliente->nomeCliente, sizeof(cliente->nomeCliente), stdin);
    printf("Edereco: ");
    fflush(stdin);
    fgets(cliente->enderecoCliente, sizeof(cliente->enderecoCliente), stdin);
    printf("Telefone: ");
    fflush(stdin);
    scanf("%d", &cliente->telefoneCliente);
    printf("Data de Nascimento\n");
    printf("Dia: ");
    fflush(stdin);
    scanf("%d", &cliente->dataNasc.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &cliente->dataNasc.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &cliente->dataNasc.ano  );
    fseek(arquivo, (sizeof(CLIENTES) * localizarCliente), 0);
    fwrite(cliente ,1, sizeof(CLIENTES), arquivo);
    fclose(arquivo);
}





//Alteraçao do Status do Cliente específicado
void alterarStatusCliente(CLIENTES *cliente){
    printf("\ec\e[3J");
    int id;
    printf("\n\n");
    printf("Digite o id do cliente o qual tera seu status alterado: ");
    fflush(stdin);
    scanf("%d", &id);

    //Caso id seja invalido
    if(id <= 0){
        printf("ID invalido.\n");
        return;
    }
    //fim do caso

    FILE *arquivo;
    arquivo = fopen("cadastroCliente.dat","r+b");
    if(arquivo == NULL){
        printf("ERRO: arquivo nao possui nenhum cliente cadastrado");
    }
    id = id - 1;
    //Caso Não encontre o cliente
    fseek(arquivo, sizeof(CLIENTES)*(id), 0);
        if (fread(cliente, sizeof(CLIENTES), 1, arquivo) != 1) {
        printf("Cliente nao encontrado.\n");
        fclose(arquivo);
        return;
    }
    //fim do caso
    fseek(arquivo, sizeof(CLIENTES)*(id), 0);
    fread(cliente,sizeof(CLIENTES), 1, arquivo);
    if(cliente->status == 1){
        cliente->status = 0;
    }else{
        cliente->status = 1;
    }
    fseek(arquivo, sizeof(CLIENTES)*(id), 0);
    fwrite(cliente, 1, sizeof(CLIENTES), arquivo);
    fclose(arquivo);
}

//fechamento do arquivo
