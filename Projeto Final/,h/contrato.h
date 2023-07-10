#ifndef CONTRATO_H_INCLUDED
#define CONTRATO_H_INCLUDED
#include "cliente.h"
#include "festa.h"

/***********************************************************************************************************************************
*   FILENAME: @file contrato.h
*   DESCRIPTION: Estrutura e funçoes para o funcionamento do arquivo cliente.c
*   PUBLIC FUNCTIONS:
*
*    void lerContrato(CONTRATOS *contrato, int codigoContrato, int codigoFesta, float valorTotalContratoFesta, float valorDescontoContratoFesta, float valorFinalContratoFesta, int formaPagamentoContratoFesta);
*    void inserirContrato(CONTRATOS *contrato, FESTAS festa);
*    void listarContratos(CONTRATOS contrato);
*    void pesquisarContrato(CONTRATOS contrato);
*    void telaContrato();
*    void altererarStatusContrato(CONTRATOS *contrato);
*    int verificaFesta(FESTAS festa, CONTRATOS contrato ,int codigoFesta, float *valorTotalContratoFesta, float *valorDescontoContratoFesta, float *valorFinalContratoFesta, int *formaPagamentoContratoFesta );
*
*
*
*   NOTE:
*   AUTHOR: Fernando Antônio Ferreira Ibrahim
*   START DATE: 13 Jun 23
************************************************************************************************************************************/


/***********************************************************************************************************************************
*   NAME: inserirContrato(contrato, festa);
*   DESCRIPTION: Seleciona qual será o id do próximo contrato, faz a abertura do arquivo cadastroContratos.dat e cadastroFornecedores.dat
*                 e a chamada das funções lerContrato() e verificaFesta() possibilitando assim a inserção de um contrato.
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;
*               FESTAS *festa: Faz a chamada da estrutura festa;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME:  verificaFesta( festa,  contrato , codigoFesta,  valorTotalContratoFesta, valorDescontoContratoFesta,  valorFinalContratoFesta, formaPagamentoContratoFesta );
*   DESCRIPTION: Percorre o arquivo cadastroFetas.h verificando se a festa informada pelo usuário é existentes, caso exista armazena seus dados;
                Caso seja existente retorna 1, caso contrario 0;
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;
*               FESTAS *festa: Faz a chamada da estrutura festa;
*               int codigoFesta: Caso seja encontrada a festa, o ponteiro armazena o valor presente no codigo da festa
*               float valorTotalContratoFesta: Caso seja encontrada a festa o ponteiro armazena o seu valor Total;
*               float valorDescontoContratoFesta:   Caso seja encontrada a festa o ponteiro armazena oseu Valor de Desconto;
*               float valorFinalContratoFesta: Caso seja encontrada a festa o ponteiro armazena o seu valor Final;
*               int formaPagamentoContratoFesta: Caso seja encontrada a festa o ponteiro armazena o valor da sua forma de pagamento;
*
*   RETURN: Nenhum;
*       TYPE: int;
*       Erro code:
*           Values: VALID_DATA : valid read;
*           KB_BAD_DATA : invalid kbd data;
*           KB_DISCONNECTED : keyboard not present;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME:  lerContrato( festa,  contrato , codigoFesta,  valorTotalContratoFesta, valorDescontoContratoFesta,  valorFinalContratoFesta, formaPagamentoContratoFesta );
*   DESCRIPTION: Armazena em contrato todos os valores já previamente encontrados pelo sistema da festá selecionada;
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;
*               FESTAS *festa: Faz a chamada da estrutura festa;
*               int codigoFesta: Passa o valor do código da festa encontrada;
*               float valorTotalContratoFesta: Passa o valor Total da festa encontrada;
*               float valorDescontoContratoFesta: Passa o Valor de Desconto da festa encontrada;
*               float valorFinalContratoFesta: Passa o valor Final da festa encontrada;
*               int formaPagamentoContratoFesta: Passa o valor da sua forma de pagamento da festa encontrada;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/


/***********************************************************************************************************************************
*   NAME:  pesquisarContrato( contrato);
*   DESCRIPTION: Percorre o arquivo de cadastroContratos tentando identificar o contrato o qual aprensenta o id informado pelo usuario
*                e printa o seus dados no console;
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME:  cadastramentoContrato();
*   DESCRIPTION: Printa no console a tela de menu com algumas funções que o sistema possui para o manuseio de contratos;
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/


/***********************************************************************************************************************************
*   NAME:  listarContratos(contrato);
*   DESCRIPTION: Percorre o arquivo cadastroContrato.dat e printa no console todos os contratos que não possui o status como cancelado
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/


/***********************************************************************************************************************************
*   NAME:  altererarStatusContrato(contrato);
*   DESCRIPTION: pesquisa em cadastroContratos.dat o contrato selecionado pelo cliente, informa o seu status e permite a sua alteração;
*   INPUTS:
*          PARAMETROS:
*               CONTRATOS *contrato: Faz a chamada da estrutura contrato;;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

typedef struct{
        int codContrato;
        float valorTotalContrato;
        float valorDescontoContrato;
        float valorFinalContrato;
        char formaPagamentoContrato;
        int status;
        int codfesta;
    }CONTRATOS;

    //Faz a leitura dos dados inserindo um contrato no arquivo CadastroContratos.dat
    void lerContrato(CONTRATOS *contrato, int codigoContrato, int codigoFesta, float valorTotalContratoFesta, float valorDescontoContratoFesta, float valorFinalContratoFesta, int formaPagamentoContratoFesta);
    //Pega verficia a existencia da festa informada e caso exista captura o seus dados.
    int verificaFesta(FESTAS festa, CONTRATOS contrato ,int codigoFesta, float *valorTotalContratoFesta, float *valorDescontoContratoFesta, float *valorFinalContratoFesta, int *formaPagamentoContratoFesta );
    //Faz a chamda das duas funçoes anteriores sequencialmente;
    void inserirContrato(CONTRATOS *contrato, FESTAS festa);
    //Fara a pesquisa de um contrato já existente
   void pesquisarContrato(CONTRATOS contrato);
   //Tela de Menu
    void cadastramentoContrato();
    //Faz a listagem de todos os contratos ativos no sistema
    void listarContratos(CONTRATOS contrato);
    //Altera o status de um contrato pelo seu id;
    void altererarStatusContrato(CONTRATOS *contrato);


#endif
