#include <stdio.h>
#include <stdlib.h>

void leMatriz(int matriz[][3], int lin, int col);

void matrizTransposta(int matrizOri[][3], int MatrizTra[][3], int lin, int col);

void printMatriz(int matriz[][3], int lin, int col);

int main()
{
    int matrizC[3][3], matrizD[3][3];

    leMatriz(matrizC, 3, 3);

    matrizTransposta(matrizC, matrizD, 3, 3);

    printMatriz(matrizD, 3, 3);

    return 0;
}

void leMatriz(int matriz[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &matriz[i][j]);
}

void matrizTransposta(int matrizOri[][3], int MatrizTra[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            MatrizTra[i][j] = matrizOri[j][i];
}

void printMatriz(int matriz[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
            printf("[%d] ", matriz[i][j]);
        printf("\n");
    }
}
