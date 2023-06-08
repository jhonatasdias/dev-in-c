#include <stdio.h>
#include <stdlib.h>
#define MQUADRADA 4

void leMatriz(int matriz[][MQUADRADA], int lin, int col);

void impMatriz(int matriz[][MQUADRADA], int lin, int col);

int main()
{
    int matriz[MQUADRADA][MQUADRADA];

    leMatriz(matriz, MQUADRADA, MQUADRADA);

    impMatriz(matriz, MQUADRADA, MQUADRADA);

    return 0;
}

void leMatriz(int matriz[][MQUADRADA], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &matriz[i][j]);
}

void impMatriz(int matriz[][MQUADRADA], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(j <= i)
                printf("[%2d] ", matriz[i][j]);
            else
                printf("[  ] ");
        }
        printf("\n");
    }
}
