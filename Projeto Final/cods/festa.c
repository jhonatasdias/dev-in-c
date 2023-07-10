#include <stdio.h>
#include <string.h>
#include <time.h>
#include "festa.h"
#include "fornecedor.h"
#include "cliente.h"

//-----------------------------------------------------------------

void cadastramentoFesta(){
    FESTAS festa;
    FORNECEDORES fornecedor;
    int resposta;
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};
    do{
        printf("\n\nCadastramento da Festa\n");
        printf("1 -> Inserir Festa\n");
        printf("2 -> Listar\n");
        printf("3 -> Alterar cadastro\n");
        printf("4 -> Pesquisar dados\n");
        printf("5 -> Imprimir Tabela Informativa\n");
        printf("0 -> Retornar ao menur anterior\n:");
        scanf("%d", &resposta);

        switch(resposta){
            case 1: inserirFesta(&festa, &fornecedor); break;
            case 2: listarFesta(festa); break;
            case 3: alterarCadastroFesta(&festa, &fornecedor); break;
            case 4: pesquisarDadosFesta(); break;
            case 5: imprimirTabela(); break;
            case 0: break;
        default: printf("Opcao invalida.\n");
        }
    } while(resposta != 0);

}

void inserirFesta(FESTAS *festa, FORNECEDORES *fornecedor) {
    int codForn, codClien, dia, mes, ano, diaSemana, op;
    int hhInicio, mmInicio, hhFim, mmFim;
    char conf;
    char tema[100];
    char* dia_semana[7] = {"Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    int tabelaDeDesconto [4] = {10, 5, 2, 0};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    // Arquivo
    FILE *arquivoFesta = fopen("cadastroFesta.dat", "a+b");
    if(arquivoFesta == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    // Cod da Festa
    fseek(arquivoFesta, 0, SEEK_END);
    if (ftell(arquivoFesta) == 0) {
        festa->codFesta = 1;
    } else {
        fseek(arquivoFesta, -sizeof(FESTAS), SEEK_END);
        fread(festa, sizeof(FESTAS), 1, arquivoFesta);
        festa->codFesta++;
        fseek(arquivoFesta, 0, SEEK_END);
    }

    // Cadastrando o Fornecedor
    printf("Digite o codigo do Fornecedor\n:");
    scanf("%d", &codForn);
    while(verificaFornecedor(codForn)){
        do{
            printf("Fornecedor nao identificado, favor verificar novamente se esse Fornecedor existe\n");
            printf("Deseja continuar com o cadastro? [S/N]\n:");
            scanf(" %c", &conf);
        } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
        if(conf == 'n' || conf == 'N') return;
        printf("Digite o codigo do Fornecedor\n:");
        scanf("%d", &codForn);
    }

    festa->codFFornecedor = codForn;

    // Cadastramento do Cliente
    printf("Digite o codigo do Cliente\n:");
    scanf("%d", &codClien);
    while(verificaCliente(codClien)){
        do{
            printf("Cliente nao identificado, favor verificar novamente se esse Cliente existe\n");
            printf("Deseja continuar com o cadastro? [S/N]\n:");
            scanf(" %c", &conf);
        } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
        if(conf == 'n' || conf == 'N') return;
        printf("Digite o codigo do Cliente\n:");
        scanf("%d", &codClien);
    }

    festa->codFCliente = codClien;


    // Tema da festa
    printf("Digite o nome do tema da Festa\n:");
    fflush(stdin);
    fgets(tema, sizeof(tema), stdin);
    while(verificaTemaDaFesta(tema)){
        do{
            printf("Esse Tema de Festa ja exite, favor escolher outro tema\n");
            printf("Deseja continuar com o cadastro? [S/N]\n:");
            scanf(" %c", &conf);
        } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
        if(conf == 'n' || conf == 'N') return;
        printf("Digite o nome do tema da Festa\n:");
        fflush(stdin);
        fgets(tema, sizeof(tema), stdin);
    }

    strcpy(festa->temaDaFesta, tema);

    // Quantidade de Convidados

    printf("Digite a quantidade de Convidados\n:");
    scanf("%d", &festa->convidados);
    while(festa->convidados <= 0){
        printf("Favor digite quantidade de convidados maior que 0\n");
        printf("Digite a quantidade de Convidados\n:");
        scanf("%d", &festa->convidados);
    }

    // Data
    lerData(&dia, &mes, &ano);

    diaSemana = verificaDiaDaSemana(dia, mes, ano);

    printf("\nDia da Semana escolhido %s\n", dia_semana[diaSemana]);

    while(1){
        if(diaSemana == 6){
            // Hora
            do{
                printf("\n\nVoce tem duas opcoes: \n", dia_semana[6]);
                printf("1 -> 12 as 16 horas\n");
                printf("2 -> 18 as 22 horas\n");
                printf("0 -> Cancelamento do Cadastro\n");
                scanf("%d", &op);
                switch(op){
            case 1: hhInicio = 12; mmInicio = 0; hhFim = 16; mmFim = 0; break;
            case 2: hhInicio = 18; mmInicio = 0; hhFim = 22; mmFim = 0; break;
            case 0: return;
            default: printf("Opacao invalida\n");
                }
            }while(op != 1 && op != 2);

            if(verificaDtHrFesta(dia, mes, ano, hhInicio, mmInicio, hhFim, mmFim)){
                printf("Horario Ocupado.\n");
            }
            else
                break;

        }
        else{
            // Hora
            lerHora(&hhInicio, &mmInicio, &hhFim, &mmFim);

            // Verifica Horario vago
            while(verificaDtHrFesta(dia, mes, ano, hhInicio, mmInicio, hhFim, mmFim)){
                do{
                    printf("O horario escolhido ja esta ocupado, favor escolher outra data\n");
                    printf("Deseja continuar com o cadastro? [S/N]\n:");
                    scanf(" %c", &conf);
                } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
                if(conf == 'n' || conf == 'N') return;

                continue;
            }

            break;

        }
        // Data
        lerData(&dia, &mes, &ano);

        diaSemana = verificaDiaDaSemana(dia, mes, ano);

        printf("\nDia da Semana escolhido %s\n", dia_semana[diaSemana]);
    }

    // Data
    festa->dataMarcada.dia = dia;
    festa->dataMarcada.mes = mes;
    festa->dataMarcada.ano = ano;

    // Hora
    festa->horarioInicio.hh = hhInicio;
    festa->horarioInicio.mm = mmInicio;
    festa->horarioFim.hh = hhFim;
    festa->horarioFim.mm = mmFim;

    // Definir preço a ser pago - sem forma de pagamento
    festa->valorDaFesta.valorTotal = retornaValorDaFesta(diaSemana, festa->convidados);

    printf("\nValor Final da Festa sem deducao: %.2f\n", festa->valorDaFesta.valorTotal);

    do{
        printf("\n\nQual a forma de pagamento\n");
        printf("1 -> A vista\n");
        printf("2 -> Duas vezes\n");
        printf("3 -> Tres vezes\n");
        printf("4 -> Quatro ou mais vezes\n:"); // Na pesquisa utlizara o criterio de cadastro do cliente - consultando se  existe festa de um determinado cliente
        scanf("%d", &op);

        switch(op){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            default: printf("Opcao invalida.\n");
        }
    } while(op < 0 || op > 4);

    festa->formaDePag = op;
    // Definir preço a ser pago - com forma de pagamento
    festa->valorDaFesta.valorFinal = festa->valorDaFesta.valorTotal * (1 - tabelaDeDesconto[op - 1] / 100.0);
    festa->valorDaFesta.desconto = tabelaDeDesconto[op - 1] / 100.0;
    printf("\nValor Final da Festa com desconto: %.2f\n [%s]", festa->valorDaFesta.valorFinal, formaDePagamento[op - 1]);

    // Arquivo
    fwrite(festa, sizeof(FESTAS), 1, arquivoFesta);
    fclose(arquivoFesta);

    return;
}

int verificaFornecedor(int codForn){
    FORNECEDORES fornecedor;
    FILE *arquivoFornecedor = fopen("cadastroFornecedor.dat", "rb");
    if(arquivoFornecedor == NULL){
        printf("Erro na abertura do arquivo.");
        return -1;
    }

    while(fread(&fornecedor, sizeof(FORNECEDORES), 1, arquivoFornecedor) == 1 ){
        if( fornecedor.codFornecedor == codForn ){
            fclose(arquivoFornecedor);
            return 0;
        }
    }

    fclose(arquivoFornecedor);
    return 1;
}

int verificaCliente(int codClien){
    CLIENTES cliente;
    FILE *arquivoCliente = fopen("cadastroCliente.dat", "rb");
    if(arquivoCliente == NULL){
        printf("Erro na abertura do arquivo.");
        return -1;
    }

    while(fread(&cliente, sizeof(CLIENTES), 1, arquivoCliente) == 1 ){
        if( cliente.codCliente == codClien ){
            fclose(arquivoCliente);
            return 0;
        }
    }

    fclose(arquivoCliente);
    return 1;
}

int verificaTemaDaFesta(char *tema){
    FESTAS festa;
    char temaMin[100];
    FILE *arquivoFesta = fopen("cadastroFesta.dat", "rb");
    if(arquivoFesta == NULL){
        printf("Erro na abertura do arquivo\n");
        return -1;
    }

    strcpy(temaMin, tema);

    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1 ){
        converterParaMinusculo(festa.temaDaFesta);
        converterParaMinusculo(temaMin);
        if(strcmp(festa.temaDaFesta, temaMin) == 0){
            fclose(arquivoFesta);
            return 1; // O tema ja existe
        }
    }

    fclose(arquivoFesta);
    return 0; // O tema nao existe
}

// Função Listar Fornecedores cadastrados
void listarFesta(FESTAS festa){
    char* dia_semana[7] = {"Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    FILE *arquivoFesta = fopen("cadastroFesta.dat", "rb");
    if(arquivoFesta == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1){
        printf("\n\nCod da Festa [%d]\n", festa.codFesta);
        printf("Cod do Cliente [%d]\n", festa.codFCliente);
        printf("Cod do Fornecedor [%d]\n", festa.codFFornecedor);
        printf("Tema da festa: %s", festa.temaDaFesta);
        printf("Quantidade de convidados: %d\n", festa.convidados);
        printf("Data da Festa: %02d/%02d/%d\n", festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano);
        printf("Dia da Semana escolhido -> %s\n", dia_semana[verificaDiaDaSemana(festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano)]);
        printf("Hora de Inicio marcado: %02d:%02d\n", festa.horarioInicio.hh, festa.horarioInicio.mm);
        printf("Hora do Termino do festa marcado: %02d:%02d\n", festa.horarioFim.hh, festa.horarioFim.mm);
        printf("Valor da festa: %.2f [%s]", festa.valorDaFesta.valorFinal, formaDePagamento[festa.formaDePag - 1]);
    }

    fclose(arquivoFesta);
    return;
}

// Funçao Verifica Conflito de hora, horario livre ou ocupado
int verificaDtHrFesta(int dia, int mes, int ano, int hhInicio, int mmInicio, int hhFim, int mmFim){
    FESTAS festa;
    float timeSomaInicio, timeSomaFim, somaMarcadaInicio, somaMarcadaFim;

    timeSomaInicio = (hhInicio + mmInicio/60.0);
    timeSomaFim = (hhFim + mmFim/60.0);


    FILE *arquivoFesta = fopen("cadastroFesta.dat", "rb");
    if(arquivoFesta == NULL){
        printf("Erro na abertura do arquivo\n");
        return -1;
    }

    while(fread(&festa, sizeof(FESTAS), 1, arquivoFesta) == 1 ){
        somaMarcadaInicio = festa.horarioInicio.hh + festa.horarioInicio.mm/60.0;
        somaMarcadaFim = festa.horarioFim.hh + festa.horarioFim.mm/60.0;
        if( (dia == festa.dataMarcada.dia && mes == festa.dataMarcada.mes && ano == festa.dataMarcada.ano) &&
           ( (timeSomaInicio >= somaMarcadaInicio && timeSomaInicio <= somaMarcadaFim) ||
            (timeSomaFim >= somaMarcadaInicio && timeSomaFim <= somaMarcadaFim) )){
                fclose(arquivoFesta);
                return 1;
            }
    }

    fclose(arquivoFesta);
    return 0;
}

// Retorna o valor da Festa
float retornaValorDaFesta(int diaDaSeman, int quantDeConvidados){

    PRECO precoDaFesta[8] = {
        {30, {1,2,3,4}, 1899.00}, // precoDaFesta [0,2,4,6]
        {30, {5,6,0}, 2099.00}, // precoDaFesta [1,3,5,7]
        {50, {1,2,3,4}, 2199.00},
        {50, {5,6,0}, 2299.00},
        {80, {1,2,3,4}, 3199.00},
        {80, {5,6,0}, 3499.00},
        {100, {1,2,3,4}, 3799.00},
        {100, {5,6,0}, 3999.00}
    };

    // Definindo Criterio convidados/dia da semana
    if(quantDeConvidados < 30){
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 4; j++)
                if(diaDaSeman == precoDaFesta[i].diaSemana[j])
                    return precoDaFesta[i].valor;
    }
    else if(quantDeConvidados < 50){
        for(int i = 2; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(diaDaSeman == precoDaFesta[i].diaSemana[j])
                    return precoDaFesta[i].valor;
    }
    else if(quantDeConvidados < 80){
        for(int i = 4; i < 6; i++)
            for(int j = 0; j < 4; j++)
                if(diaDaSeman == precoDaFesta[i].diaSemana[j])
                    return precoDaFesta[i].valor;
    }
    else{
        for(int i = 6; i < 8; i++)
            for(int j = 0; j < 4; j++)
                if(diaDaSeman == precoDaFesta[i].diaSemana[j])
                    return precoDaFesta[i].valor;
    }

    printf("Erro no fornecimento do valor\n");
    return -1;
}

// ----------------------------------------------------------------------------------------------------
void lerData(int *dia, int *mes, int *ano){
    int ultimoDia;
    char* meses[12] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    while(1){
        printf("Digite a data (DD/MM/AAAA): \n");
        printf("Dia: ");
        scanf("%d", dia);
        printf("Mes: ");
        scanf("%d", mes);
        printf("Ano: ");
        scanf("%d", ano);
        if(*ano < 0){
            printf("Digite um ano maior que 0\n");
            continue;
        }

        if(*mes < 1 || *mes > 12){
            printf("Mes invalido. Favor digitar um mes valido (1 - 12)\n");
            continue;
        }

        if(*mes == 2)
            ultimoDia = 28;
        else if(*mes == 3 || *mes == 5 || *mes == 8 || *mes == 10)
            ultimoDia = 30;
        else
            ultimoDia = 31;

        if(*dia < 1 || *dia > ultimoDia){
            printf("Dia invalido. Favor digitar um dia do mes de %s valido)\n", meses[*mes - 1]);
            continue;
        }

        break;
    }
}

void lerHora(int *hhInicio, int *mmInicio, int *hhFim, int *mmFim) {
    printf("Digite o horario de quando ira acontecer a festa\n ");
    do {
        printf("O horario de inicio (HH/MM):\n");
        printf("HH: ");
        scanf("%d", hhInicio);
        printf("MM: ");
        scanf("%d", mmInicio);
    } while ((*hhInicio < 0 || *hhInicio > 23) || (*mmInicio < 0 || *mmInicio > 59));

    do {
        printf("O horario do fim da festa (HH/MM):\n");
        scanf("%d %d", hhFim, mmFim);
        if ( *hhFim > (*hhInicio + 4) ) {
            printf("Favor digitar horario com intervalo de 4 horas ou menos\n");
        }
    } while ((*hhFim < 0 || *hhFim > 23) || (*mmFim < 0 || *mmFim > 59));
}


void imprimirTabela() {
    TABELADEPRECO tabela[8] = {
        {30, "Segunda a quinta", 1899.00},
        {30, "Sexta a domingo", 2099.00},
        {50, "Segunda a quinta", 2199.00},
        {50, "Sexta a domingo", 2299.00},
        {80, "Segunda a quinta", 3199.00},
        {80, "Sexta a domingo", 3499.00},
        {100, "Segunda a quinta", 3799.00},
        {100, "Sexta a domingo", 3999.00}
    };

    int tabelaDeDesconto [4] = {10, 5, 2, 0};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    printf("                  Tabela de Precos\n");
    printf("Quantidade de convidados | Dia da semana       | Valor\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%-25d| %-19s |R$ %.2f\n", tabela[i].quantidadeConvidados, tabela[i].diaSemana, tabela[i].valor);
    }

    printf("\n\n");

    printf("                  Tabela de Descontos\n");
    printf("Forma de pagamento       | Desconto     \n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < 4; i++) {
        printf("%-25s| %-19d \n", formaDePagamento[i], tabelaDeDesconto[i]);
    }

    return;
}

// Pesquisar Dados da Festa
void pesquisarDadosFesta() {
    char* dia_semana[7] = {"Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    int id;
    FESTAS festa;
    FILE *arquivo = fopen("cadastroFesta.dat", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    printf("Digite o codigo para pesquisar os dados da festa: ");
    scanf("%d", &id);
    // Verificacao - id inexistente
    if(id <= 0){
        printf("ID invalido.\n");
        return;
    }
    // Verificacao - invalido
    fseek(arquivo, (id - 1) * sizeof(FESTAS), 0);
    if(fread(&festa, sizeof(FESTAS), 1, arquivo) != 1){
        printf("Codigo da Festa nao encontrado.\n");
        return;
    }
    printf("\n\nCod da Festa [%d]\n", festa.codFesta);
    printf("Cod do Cliente [Cliente]\n");
    printf("Cod do Fornecedor [%d]\n", festa.codFFornecedor);
    printf("Tema da festa: %s", festa.temaDaFesta);
    printf("Quantidade de convidados: %d\n", festa.convidados);
    printf("Data da Festa: %02d/%02d/%d\n", festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano);
    printf("Dia da Semana escolhido -> %s\n", dia_semana[verificaDiaDaSemana(festa.dataMarcada.dia, festa.dataMarcada.mes, festa.dataMarcada.ano)]);
    printf("Hora de Inicio marcado: %02d:%02d\n", festa.horarioInicio.hh, festa.horarioInicio.mm);
    printf("Hora do Termino do festa marcado: %02d:%02d\n", festa.horarioFim.hh, festa.horarioFim.mm);
    printf("Valor da festa: %.2f [%s]", festa.valorDaFesta.valorFinal, formaDePagamento[festa.formaDePag - 1]);
    fclose(arquivo);
}

void converterParaMinusculo(char *texto) {
    int i = 0;
    while (texto[i] != '\0') {
        texto[i] = tolower(texto[i]);
        i++;
    }
}

int verificaDiaDaSemana(int dia, int mes, int ano){

    struct tm data = {0};
    data.tm_year = ano - 1900;
    data.tm_mon = mes - 1;
    data.tm_mday = dia;

    time_t timestamp = mktime(&data);

    struct tm *info = localtime(&timestamp);
    return info->tm_wday;
}

void alterarCadastroFesta(FESTAS *festa, FORNECEDORES *fornecedor){
    int codForn, codClien, dia, mes, ano, diaSemana, op, id;
    int hhInicio, mmInicio, hhFim, mmFim;
    char conf;
    char tema[100];
    char* dia_semana[7] = {"Domingo", "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};
    int tabelaDeDesconto [4] = {10, 5, 2, 0};
    char *formaDePagamento [4] = {"A vista", "Duas vezes", "Tres vezes", "Quatro vezes ou mais"};

    FILE *arquivoFesta;

    arquivoFesta = fopen("cadastroFesta.dat", "r+b");
    if(arquivoFesta == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    printf("Digite o numero de identificacao para alterar os dados da festa: ");
    scanf("%d", &id);
    if(id <= 0){
        printf("ID invalido.\n");
        fclose(arquivoFesta);
        return;
    }

    // Festa não identificado
    fseek(arquivoFesta, (id - 1) * sizeof(FESTAS), 0);
    if (fread(festa, sizeof(FESTAS), 1, arquivoFesta) != 1) {
        printf("Fornecedor nao encontrado.\n");
        fclose(arquivoFesta);
        return;
    }

    // Cadastrando o Fornecedor
    printf("Digite o codigo do Fornecedor\n:");
    scanf("%d", &codForn);
    while(verificaFornecedor(codForn)){
        do{
            printf("Fornecedor nao identificado, favor verificar novamente se esse Fornecedor existe\n");
            printf("Deseja continuar com o cadastro? [S/N]\n:");
            scanf(" %c", &conf);
        } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
        if(conf == 'n' || conf == 'N') return;
        printf("Digite o codigo do Fornecedor\n:");
        scanf("%d", &codForn);
    }

    festa->codFFornecedor = codForn;

    // Cadastramento do Cliente
    // O codigo do cliente não pode ser alterado, se precisar mudar dados do cliente deve inserir uma nova festa com um novo cliente


    // Tema da festa
    printf("Digite o nome do tema da Festa\n:");
    fflush(stdin);
    fgets(tema, sizeof(tema), stdin);
    while(verificaTemaDaFesta(tema)){
        do{
            printf("Esse Tema de Festa ja exite, favor escolher outro tema\n");
            printf("Deseja continuar com o cadastro? [S/N]\n:");
            scanf(" %c", &conf);
        } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
        if(conf == 'n' || conf == 'N') return;
        printf("Digite o nome do tema da Festa\n:");
        fflush(stdin);
        fgets(tema, sizeof(tema), stdin);
    }

    strcpy(festa->temaDaFesta, tema);

    // Quantidade de Convidados

    printf("Digite a quantidade de Convidados\n:");
    scanf("%d", &festa->convidados);
    while(festa->convidados <= 0){
        printf("Favor digite quantidade de convidados maior que 0\n");
        printf("Digite a quantidade de Convidados\n:");
        scanf("%d", &festa->convidados);
    }

    // Data
    lerData(&dia, &mes, &ano);

    diaSemana = verificaDiaDaSemana(dia, mes, ano);

    printf("\nDia da Semana escolhido %s\n", dia_semana[diaSemana]);

    while(1){
        if(diaSemana == 6){
            // Hora
            do{
                printf("\n\nVoce tem duas opcoes: \n", dia_semana[6]);
                printf("1 -> 12 as 16 horas\n");
                printf("2 -> 18 as 22 horas\n");
                printf("0 -> Cancelamento do Cadastro\n");
                scanf("%d", &op);
                switch(op){
            case 1: hhInicio = 12; mmInicio = 0; hhFim = 16; mmFim = 0; break;
            case 2: hhInicio = 18; mmInicio = 0; hhFim = 22; mmFim = 0; break;
            case 0: return;
            default: printf("Opacao invalida\n");
                }
            }while(op != 1 && op != 2);

            if(verificaDtHrFesta(dia, mes, ano, hhInicio, mmInicio, hhFim, mmFim)){
                printf("Horario Ocupado.\n");
            }
            else
                break;

        }
        else{
            // Hora
            lerHora(&hhInicio, &mmInicio, &hhFim, &mmFim);

            // Verifica Horario vago
            while(verificaDtHrFesta(dia, mes, ano, hhInicio, mmInicio, hhFim, mmFim)){
                do{
                    printf("O horario escolhido ja esta ocupado, favor escolher outra data\n");
                    printf("Deseja continuar com o cadastro? [S/N]\n:");
                    scanf(" %c", &conf);
                } while((conf != 'n' && conf != 'N') && (conf != 's' && conf != 'S'));
                if(conf == 'n' || conf == 'N') return;

                continue;
            }

            break;

        }
        // Data
        lerData(&dia, &mes, &ano);

        diaSemana = verificaDiaDaSemana(dia, mes, ano);

        printf("\nDia da Semana escolhido %s\n", dia_semana[diaSemana]);
    }

    // Data
    festa->dataMarcada.dia = dia;
    festa->dataMarcada.mes = mes;
    festa->dataMarcada.ano = ano;

    // Hora
    festa->horarioInicio.hh = hhInicio;
    festa->horarioInicio.mm = mmInicio;
    festa->horarioFim.hh = hhFim;
    festa->horarioFim.mm = mmFim;

    // Definir preço a ser pago - sem forma de pagamento
    festa->valorDaFesta.valorTotal = retornaValorDaFesta(diaSemana, festa->convidados);

    printf("\nValor Final da Festa sem deducao: %.2f\n", festa->valorDaFesta.valorTotal);

    do{
        printf("\n\nQual a forma de pagamento\n");
        printf("1 -> A vista\n");
        printf("2 -> Duas vezes\n");
        printf("3 -> Tres vezes\n");
        printf("4 -> Quatro ou mais vezes\n:"); // Na pesquisa utlizara o criterio de cadastro do cliente - consultando se  existe festa de um determinado cliente
        scanf("%d", &op);

        switch(op){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            default: printf("Opcao invalida.\n");
        }
    } while(op < 0 || op > 4);

    festa->formaDePag = op;
    // Definir preço a ser pago - com forma de pagamento
    festa->valorDaFesta.valorFinal = festa->valorDaFesta.valorTotal * (1 - tabelaDeDesconto[op - 1] / 100.0);
    festa->valorDaFesta.desconto = tabelaDeDesconto[op - 1] / 100.0;
    printf("\nValor Final da Festa com desconto: %.2f\n [%s]", festa->valorDaFesta.valorFinal, formaDePagamento[op - 1]);

    // Gravar dados alterado no arquivo;
    fseek(arquivoFesta, (id - 1) * sizeof(FESTAS), 0);
    fwrite(festa, sizeof(FESTAS), 1, arquivoFesta);

    // Fechar arquivo
    fclose(arquivoFesta);
    printf("\nFesta alterado com sucesso.\n");
}
