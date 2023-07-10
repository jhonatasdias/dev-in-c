#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED

/**
*   FILENAME: @file fornecedor.h
*   DESCRIPTION: Estruturas e funções para o funcionamento do arquivo fornecedor.c
*   PUBLIC FUNCTIONS:
-- Função - Principal
void cadastramentoFornecedor();

-- Função - Secundaria
void inserirFornecedor(FORNECEDORES *forncedor);
void listarFornecedor(FORNECEDORES forncedor);
void alterarCadastro(FORNECEDORES *forncedor);
void pesquisarDadosFornecedor(FORNECEDORES *forncedor);

-- Função - Auxiliar
void leFornecedor(FORNECEDORES *forncedor);
void pesquisaNome();
void pesquisaId();

*   NOTE: Faz cadastramento, lista, pesquisa e altera cadastro do fornecedor, a biblioteca é dividida em:
/ função principal: menu do programa
/ função secundaria: são as funções que executam o menu
/ função auxiliar: funções que fazem tarefas especificas do função secundaria

*   AUTHOR: Jhonata Dias
*   START DATE: 06 Jun 2023
*/

// Strucut
typedef struct {
    int codFornecedor;
    char nomeBuffet[100];
    int telefoneFornecedor;
    int status;
} FORNECEDORES;

// Prototipos
// Função - Principal
/**
*NOME: cadastramentoFornecedor()
*DESCRIPTION: Menu contendo as opções para cadastramento do fornecedor
*INPUTS:
*   PARAMETERS: void
*   RETURN: void
*       TYPE: void
*/
void cadastramentoFornecedor();

// Função - Secundaria

/**
*NOME: inserirFornecedor(FORNECEDORES *forncedor)
*DESCRIPTION: Função para inserir cadastro do fornecedor
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void inserirFornecedor(FORNECEDORES *forncedor);

/**
*NOME: void listarFornecedor(FORNECEDORES forncedor)
*DESCRIPTION: Função para listar todos os forncedores armezenado no arquivo cadastroFornecedor.dat
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void listarFornecedor(FORNECEDORES forncedor);

/**
*NOME: alterarCadastro(FORNECEDORES *forncedor)
*DESCRIPTION: Função para alterar dados do forncedor armezenado no arquivo cadastroFornecedor.dat
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void alterarCadastro(FORNECEDORES *forncedor);

/**
*NOME: pesquisarDadosFornecedor(FORNECEDORES *forncedor)
*DESCRIPTION: Menu contendo as opções para pesquisa (id ou data) do fornecedor
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void pesquisarDadosFornecedor(FORNECEDORES *forncedor);

/**
*NOME: void pesquisaNome()
*DESCRIPTION: função pesquisa os dados do fornecedor pela iniciais do nome (ou  o primeiro nome completo)
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void pesquisaNome();

/**
*NOME: pesquisaId()
*DESCRIPTION: função pesquisa os dados do fornecedor pelo id
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void pesquisaId();

// Função - Auxiliar

/**
*NOME: leFornecedor(FORNECEDORES *forncedor)
*DESCRIPTION: função que recolhe todos os dados do fornecedor
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void leFornecedor(FORNECEDORES *forncedor);

#endif // FORNECEDOR_H_INCLUDED
