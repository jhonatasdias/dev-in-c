#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

/**
*   FILENAME: @file festa.h

*   DESCRIPTION: Estruturas e funções para o funcionamento do arquivo relatorios.c

*   PUBLIC FUNCTIONS:

void impressaoRelatorio();
void imprimirClienteFesta();
void imprimirFestaData();

*   NOTE: Impressão de relatorios do cadastramento da festa

*   AUTHOR: Jhonata Dias
*   START DATE: 06 Jun 2023
*/

// Prototipo
/**
*NOME: void impressaoRelatorio()
*DESCRIPTION: Menu contendo as opções de imprimir dois tipos de relatorios com os dados do programa
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void impressaoRelatorio();

/**
*NOME: imprimirClienteFesta()
*DESCRIPTION: Imprime os dados (todas as festas vinculado ao cliente) através do id fornecido pelo usuário
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void imprimirClienteFesta();

/**
*NOME: imprimirFestaData()
*DESCRIPTION: Imprime os dados (todas as festas vinculado por data) com a mesma data fornecido pelo usuário
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void imprimirFestaData();

#endif // RELATORIOS_H_INCLUDED
