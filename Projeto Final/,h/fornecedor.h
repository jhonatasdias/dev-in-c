#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED

/**
*   FILENAME: @file fornecedor.h
*   DESCRIPTION: Estruturas e fun��es para o funcionamento do arquivo fornecedor.c
*   PUBLIC FUNCTIONS:
-- Fun��o - Principal
void cadastramentoFornecedor();

-- Fun��o - Secundaria
void inserirFornecedor(FORNECEDORES *forncedor);
void listarFornecedor(FORNECEDORES forncedor);
void alterarCadastro(FORNECEDORES *forncedor);
void pesquisarDadosFornecedor(FORNECEDORES *forncedor);

-- Fun��o - Auxiliar
void leFornecedor(FORNECEDORES *forncedor);
void pesquisaNome();
void pesquisaId();

*   NOTE: Faz cadastramento, lista, pesquisa e altera cadastro do fornecedor, a biblioteca � dividida em:
/ fun��o principal: menu do programa
/ fun��o secundaria: s�o as fun��es que executam o menu
/ fun��o auxiliar: fun��es que fazem tarefas especificas do fun��o secundaria

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
// Fun��o - Principal
/**
*NOME: cadastramentoFornecedor()
*DESCRIPTION: Menu contendo as op��es para cadastramento do fornecedor
*INPUTS:
*   PARAMETERS: void
*   RETURN: void
*       TYPE: void
*/
void cadastramentoFornecedor();

// Fun��o - Secundaria

/**
*NOME: inserirFornecedor(FORNECEDORES *forncedor)
*DESCRIPTION: Fun��o para inserir cadastro do fornecedor
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void inserirFornecedor(FORNECEDORES *forncedor);

/**
*NOME: void listarFornecedor(FORNECEDORES forncedor)
*DESCRIPTION: Fun��o para listar todos os forncedores armezenado no arquivo cadastroFornecedor.dat
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void listarFornecedor(FORNECEDORES forncedor);

/**
*NOME: alterarCadastro(FORNECEDORES *forncedor)
*DESCRIPTION: Fun��o para alterar dados do forncedor armezenado no arquivo cadastroFornecedor.dat
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void alterarCadastro(FORNECEDORES *forncedor);

/**
*NOME: pesquisarDadosFornecedor(FORNECEDORES *forncedor)
*DESCRIPTION: Menu contendo as op��es para pesquisa (id ou data) do fornecedor
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void pesquisarDadosFornecedor(FORNECEDORES *forncedor);

/**
*NOME: void pesquisaNome()
*DESCRIPTION: fun��o pesquisa os dados do fornecedor pela iniciais do nome (ou  o primeiro nome completo)
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void pesquisaNome();

/**
*NOME: pesquisaId()
*DESCRIPTION: fun��o pesquisa os dados do fornecedor pelo id
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void pesquisaId();

// Fun��o - Auxiliar

/**
*NOME: leFornecedor(FORNECEDORES *forncedor)
*DESCRIPTION: fun��o que recolhe todos os dados do fornecedor
*INPUTS:
*   PARAMETERS:
*       FORNECEDORES *fornecedor: estrutura do fornecedor contendo todos os dados necessarios para o cadastro
*   RETURN:
*       TYPE: void
*/
void leFornecedor(FORNECEDORES *forncedor);

#endif // FORNECEDOR_H_INCLUDED
