#ifndef FESTA_H_INCLUDED
#define FESTA_H_INCLUDED

#include "cliente.h"
#include "fornecedor.h"

/**
*   FILENAME: @file festa.h

*   DESCRIPTION: Estruturas e funções para o funcionamento do arquivo festa.c

*   PUBLIC FUNCTIONS:

-- Função Principal
void listarFesta(FESTAS festa)
void pesquisarDadosFesta()
alterarCadastroFesta(FESTAS *festa, FORNECEDORES *fornecedor)
void imprimirTabela()

-- Função Auxiliar
void converterParaMinusculo(char *texto)
void lerData(int *dia, int *mes, int *ano)
void lerHora(int *hhInicio, int *mmInicio, int *hhFim, int *mmFim)

-- Funções
int verificaTemaDaFesta(char *tema)
int verificaDiaDaSemana(int dia, int mes, int ano)
int verificaDtHrFesta(int dia, int mes, int ano, int hhInicio, int mmInicio, int hhFim, int mmFim)
float retornaValorDaFesta(int diaDaSeman, int quantDeConvidados)
int verificaFornecedor(int codForn)
int verificaCliente(int codClien)

*   NOTE: A bibliotexa é dividida em:
/ função principal: menu do programa
/ função secundaria: são as funções que executam o menu
/ função auxiliar: tem o papel de executar tarefas especificas que contribuem tanto no arquivo festa.c quanto em todo o programa
/ função de verificação: todo o programa festa.c passa por uma serie de verificações, essas funções funções fazem esse papel se eh permitido
determinada entrada pelo usuário ou não.

*   AUTHOR: Jhonata Dias
*   START DATE: 06 Jun 2023
*/

// Estruturas da festa

typedef struct{
    int hh;
    int mm;
}HORARIO;

typedef struct{
    float valorTotal;
    float desconto;
    float valorFinal;
} VALOR;

typedef struct{
    int codFesta;
    int codFCliente;
    int codFFornecedor;
    int convidados;
    char temaDaFesta[100];
    int formaDePag;
    VALOR valorDaFesta;
    DATA dataMarcada;
    HORARIO horarioInicio;
    HORARIO horarioFim;
}FESTAS;

// Tabelas

typedef struct {
    int quantidadeConvidados;
    char diaSemana[20];
    float valor;
} TABELADEPRECO;

typedef struct {
    int maximoConvidados;
    int diaSemana[4];
    float valor;
} PRECO;

// Prototipos
// Função principal

/**
*NOME: void cadastramentoFesta()
*DESCRIPTION: Menu contendo as opções para cadastramento da festa
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void cadastramentoFesta();

// Função - Secundaria
/**
*NOME: void inserirFesta(FESTAS *festa, FORNECEDORES *fornecedor)
*DESCRIPTION: Função para inserir cadastro da festa
*INPUTS:
*   PARAMETERS:
*       FESTAS *festa: estrutura da festa contendo todos os dados necessarios para o cadastro
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void inserirFesta(FESTAS *festa, FORNECEDORES *fornecedor);

/**
*NOME: listarFesta(FESTAS festa)
*DESCRIPTION: Função para listar todos as festas armezenado no arquivo cadastroFesta.dat
*INPUTS:
*   PARAMETERS:
*       FESTAS festa: estrutura da festa contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void listarFesta(FESTAS festa);

/**
*NOME: pesquisarDadosFesta()
*DESCRIPTION: função pesquisa os dados da festa pelo id
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void pesquisarDadosFesta();

/**
*NOME: alterarCadastroFesta(FESTAS *festa, FORNECEDORES *fornecedor)
*DESCRIPTION: Função para alterar dados do forncedor armezenado no arquivo cadastroFesta.dat
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor
*       FESTAS *festa: estrutura da festa contendo os dados necessario para alteração dos dados
*   RETURN:
*       TYPE: void
*/
void alterarCadastroFesta(FESTAS *festa, FORNECEDORES *fornecedor);

/**
*NOME: void imprimirTabela()
*DESCRIPTION: taela informativa de valores e desconto
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void imprimirTabela();

// Função - Auxiliar

/**
*NOME: void converterParaMinusculo(char *texto)
*DESCRIPTION: converte todo o texto para minusculo
*INPUTS:
*   PARAMETERS:
*       char *texto: parametro do texto que ira ser convertido para minusculo
*   RETURN:
*       TYPE: void
*/
void converterParaMinusculo(char *texto);

/**
*NOME: void lerData(int *dia, int *mes, int *ano)
*DESCRIPTION: função que ler uma data verificando os dias e os meses estão de acordo com o calendario
*INPUTS:
*   PARAMETERS:
*       int *dia: dia da data
*       int *mes: mes da data
*       int *ano: ano da data
*   RETURN:
*       TYPE: void
*/
void lerData(int *dia, int *mes, int *ano);

/**
*NOME: void lerHora(int *hhInicio, int *mmInicio, int *hhFim, int *mmFim)
*DESCRIPTION: função que ler uma hora verificando as horas e os minutos estão de acordo com horario convencional(máximo: 23:59)
*INPUTS:
*   PARAMETERS:
*       int *dia: dia da data
*       int *mes: mes da data
*       int *ano: ano da data
*   RETURN:
*       TYPE: void
*/
void lerHora(int *hhInicio, int *mmInicio, int *hhFim, int *mmFim);

// Função - verificação

/**
*NOME: int verificaTemaDaFesta(char *tema)
*DESCRIPTION: verifica se o nome da festa existe no arquivo cadastroFesta.dat
*INPUTS:
*   PARAMETERS:
*       char *tema: entreda do nome do tema
*   RETURN:
*       TYPE: int
*           0 - condição valida, o nome do tema não está sendo repetido nos dados armazenados (cadastroFesta.dat)
*           1 - condição invalida, o nome do tema está sendo repetido nos dados armazenados (cadastroFesta.dat)
*/
int verificaTemaDaFesta(char *tema);

/**
*NOME: verificaDiaDaSemana(int dia, int mes, int ano)
*DESCRIPTION: verfica o dia da semana e retorna valores de 0 até 6 sendo de domingo até sábado respectivamente
*INPUTS:
*   PARAMETERS:
*       int dia: dia da data
*       int mes: mes da data
*       int ano: ano da data
*   RETURN:
*       TYPE: int
*           0 - domingo
*           1 - segunda-feira
*           2 - terça-feira
*           3 - quarta-feira
*           4 - quinta-feira
*           5 - sexta-feira
*           6 - sábado
*/
int verificaDiaDaSemana(int dia, int mes, int ano);

/**
*NOME: int verificaDtHrFesta(int dia, int mes, int ano, int hhInicio, int mmInicio, int hhFim, int mmFim)
*DESCRIPTION: verifica a data e a hora já existe no arquivo cadastroFesta.dat
*INPUTS:
*   PARAMETERS:
*       int dia: dia da data
*       int mes: mes da data
*       int ano: ano da data
*       int hhInicio: parametro de entrada da hora
*       int mmInicio: parametro de entrada dos minutos
*       int hhFim: parametro de entrada da hora
*       int mmFim: parametro de entrada dos minutos
*   RETURN:
*       TYPE: int
*           0 - condição valida, o nome do tema não está sendo repetido nos dados armazenados (cadastroFesta.dat)
*           1 - condição invalida, o nome do tema está sendo repetido nos dados armazenados (cadastroFesta.dat)
*/
int verificaDtHrFesta(int dia, int mes, int ano, int hhInicio, int mmInicio, int hhFim, int mmFim);


/**
*NOME: retornaValorDaFesta(int diaDaSeman, int quantDeConvidados)
*DESCRIPTION: função informa o valor da festa de acordo ao dia da semana e a quantidade de convidados
*INPUTS:
*   PARAMETERS:
*       int diaDaSeman: parametro dia da semana (0-6)
*       int quantDeConvidados: parametro quantidades de convidados
*   RETURN:
*       TYPE: float
*           valor da festa conforme a tabela de informações
*/
float retornaValorDaFesta(int diaDaSeman, int quantDeConvidados);

/**
*NOME: int verificaFornecedor(int codForn)
*DESCRIPTION: função verifica se o fornecedor existe ou não no arquivo cadastroFornecedor.dat
*INPUTS:
*   PARAMETERS:
*       int codForn: parametro de entrada o codigo do fornecedor
*   RETURN:
*       TYPE: int
*           0 - condição valida, existe fornecedor cadastrado
*           1 - condição invalida, não existe fornecedor cadastrado
*/
int verificaFornecedor(int codForn);

/**
*NOME: int verificaCliente(int codClien)
*DESCRIPTION: função verifica se o cliente existe ou não no arquivo cadastroCliente.dat
*INPUTS:
*   PARAMETERS:
*       int codClien: parametro de entrada o codigo do cliente
*   RETURN:
*       TYPE: int
*           0 - condição valida, existe cliente cadastrado
*           1 - condição invalida, não existe cliente cadastrado
*/
int verificaCliente(int codClien);

#endif // FESTA_H_INCLUDED
