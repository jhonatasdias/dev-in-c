#include <stdio.h>
#include <stdlib.h>

void leMatriz(int matrizA[][3], int lin, int col);

int somaMatrizDP(int matrizA[][3], int lin, int col);

int main()
{
    int m[3][3], somaDP;

    leMatriz(m, 3, 3);

    somaDP = somaMatrizDP(m, 3, 3);

    printf("A soma da DP e: %d\n", somaDP);

    return 0;
}

void leMatriz(int MatrizA[][3], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &MatrizA[i][j]);
}

int somaMatrizDP(int matrizA[][3], int lin, int col)
{
    int soma = 0, i, j;
    for(i = 0, j = 0; i < lin; i++, j++)
        soma += matrizA[i][j];
    return soma;
}
