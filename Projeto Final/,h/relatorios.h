#ifndef RELATORIOS_H_INCLUDED
#define RELATORIOS_H_INCLUDED

/**
*   FILENAME: @file festa.h

*   DESCRIPTION: Estruturas e fun��es para o funcionamento do arquivo relatorios.c

*   PUBLIC FUNCTIONS:

void impressaoRelatorio();
void imprimirClienteFesta();
void imprimirFestaData();

*   NOTE: Impress�o de relatorios do cadastramento da festa

*   AUTHOR: Jhonata Dias
*   START DATE: 06 Jun 2023
*/

// Prototipo
/**
*NOME: void impressaoRelatorio()
*DESCRIPTION: Menu contendo as op��es de imprimir dois tipos de relatorios com os dados do programa
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void impressaoRelatorio();

/**
*NOME: imprimirClienteFesta()
*DESCRIPTION: Imprime os dados (todas as festas vinculado ao cliente) atrav�s do id fornecido pelo usu�rio
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void imprimirClienteFesta();

/**
*NOME: imprimirFestaData()
*DESCRIPTION: Imprime os dados (todas as festas vinculado por data) com a mesma data fornecido pelo usu�rio
*INPUTS:
*   PARAMETERS: void
*   RETURN:
*       TYPE: void
*/
void imprimirFestaData();

#endif // RELATORIOS_H_INCLUDED
