#include <stdio.h>
#include <stdlib.h>

void leMatriz(int matriz[][3], int lin, int col);

void somaMatriz(int matrizA[][3], int matrizB[][3], int matrizC[][3],int lin, int col);

void printMatriz(int matriz[][3], int lin, int col);

int main()
{
    int matrizA[3][3], matrizB[3][3], matrizC[3][3];

    leMatriz(matrizA, 3, 3);

    leMatriz(matrizB, 3, 3);

    somaMatriz(matrizA, matrizB, matrizC, 3, 3);

    printMatriz(matrizC, 3, 3);

    return 0;
}

void leMatriz(int matriz[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &matriz[i][j]);
}

void somaMatriz(int matrizA[][3], int matrizB[][3], int matrizC[][3],int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
}

void printMatriz(int matriz[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
            printf("[%2d] ", matriz[i][j]);
        printf("\n");
    }
}
