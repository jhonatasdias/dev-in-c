#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

/***********************************************************************************************************************************
*   FILENAME: @file contrato.h
*   DESCRIPTION: Estrutura e funçoes para o funcionamento do arquivo cliente.c
*   PUBLIC FUNCTIONS:
*
*        void inserirCliente(CLIENTES *cliente);
*        void lerCliente(CLIENTES *cliente, int codigoCliente);
*        void listarCliente(CLIENTES cliente);
*        void localizarCliente(CLIENTES cliente);
*        void localizarClienteID(CLIENTES cliente);
*        void localizarClienteNome(CLIENTES cliente);
*        void editarcliente(CLIENTES *cliente);
*        void alterarStatusCliente(CLIENTES *cliente);
*
*   NOTE:
*   AUTHOR: Fernando Antônio Ferreira Ibrahim
*   START DATE: 13 Jun 23
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: InserirCliente(cliente);
*   DESCRIPTION: Realiza a contagem do Id do proximo usuario a seradicionado, abre o arquivo dat para a incersao de dados que acontece
*                no lerlientes(cliente,codigo),  após isso grava eles no arquivo CadastroClientes.
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: lerCliente(cliente,codigoCliente);
*   DESCRIPTION: Realiza a inserção de todos dados dentro do struct clientes;
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*               codigoCliente: codigo calculado previamente que sera unico do usuario;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: listaCliente(cliente);
*   DESCRIPTION: Percorre todo o arquivo CadastroCliente e printa no console os clientes os quais apresentam o status como ativo
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*               codigoCliente: codigo calculado previamente que sera unico do usuario;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: localizar(cliente);
*   DESCRIPTION: Permite com que o usuario selecione o método de pesquisa o qual deseja realizar por id ou por nome através da chamada
*                de duas funcoes possiveis;
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: localizarClienteID(cliente);
*   DESCRIPTION: Percorre o arquivo cadastroCliente.dat, verifica qual dos itens cadastrados possui o mesmo id informado pelo usuario e
*                printa as informações do mesmo no console;
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: localizarClienteNome(cliente);
*   DESCRIPTION: Percorre o arquivo cadastroCliente.dat, verifica quais dos itens cadastrados possui parcialmente ou totalmente o nome
*                informado pelo usuario e printa as informações do mesmo no console;
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: editarcliente(cliente);
*   DESCRIPTION: Percorre o arquivo cadastroCliente.dat, verifica quais dos itens cadastrados possui o id informado pelo usuario e
*                e rescreve o sobre os seus dados;
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

/***********************************************************************************************************************************
*   NAME: alterarStatusCliente(cliente);
*   DESCRIPTION: Percorre o arquivo cadastroCliente.dat, verifica quais dos itens cadastrados possui o id informado pelo usuario e
*                alterna o Status entre 1 e 0 "Ativo ou Inativo" respectivamente;
*   INPUTS:
*          PARAMETROS:
*               CLIENTES *cliente: Faz a chamada da estrutura clientes;
*
*   RETURN: Nenhum;
*   TYPE: void;
*
************************************************************************************************************************************/

    typedef struct {
        int dia;
        int mes;
        int ano;
    }DATA;


    typedef struct {
        int codCliente;
        char nomeCliente[100];
        char enderecoCliente[100];
        int telefoneCliente;
        int status;

        DATA dataNasc;
    }CLIENTES;  // cliente virou um tipo de variavel;

    //funcoes menu
    void cadastramentoCliente();



    //solicita do usuário o preenchimento de dados
    void inserirCliente(CLIENTES *cliente);
    void lerCliente(CLIENTES *cliente, int codigoCliente);

    //Lista todos os cliente com status ativo;
    void listarCliente(CLIENTES cliente);


    void localizarCliente(CLIENTES cliente);
    //Faz a localizaçao de um cliente através do seu id;
    void localizarClienteID(CLIENTES cliente);
    //FAz a localização de um cliente pelo nome do usuário;
    void localizarClienteNome(CLIENTES cliente);

    //Ateraçao de dados do Cliente;
    void editarcliente(CLIENTES *cliente);

    //Alteração do Status do Cliente
    void alterarStatusCliente(CLIENTES *cliente);

#endif
