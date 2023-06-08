#include <stdio.h>
#include <stdlib.h>

void leMtriz(int matriz[][3], int lin, int col);

void matrizElementoMaior(int matrizA[][3], int matrizB[][3], int matrizMaior[][3],int lin, int col);

void printMatriz(int matriz[][3], int lin, int col);

int main()
{
    int matrizA[3][3], matrizB[3][3], matrizE[3][3];

    leMatriz(matrizA, 3, 3);

    leMatriz(matrizB, 3, 3);

    matrizElementoMaior(matrizA, matrizB, matrizE, 3, 3);

    printMatriz(matrizE, 3, 3);

    return 0;
}

void leMatriz(int matriz[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &matriz[i][j]);
}

void matrizElementoMaior(int matrizA[][3], int matrizB[][3], int matrizMaior[][3],int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            if(matrizA[i][j] > matrizB[i][j])
                matrizMaior[i][j] = matrizA[i][j];
            else
                matrizMaior[i][j] = matrizB[i][j];
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
