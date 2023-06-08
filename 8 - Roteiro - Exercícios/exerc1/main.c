#include <stdio.h>
#include <stdlib.h>

void LeMatriz(int Matriz[][4], int lin, int col);

void ImprimeMatriz(int Matriz[][4], int lin, int col);

int main()
{
    int m[4][4];
    printf("Digite valores dos elementos da matriz.\n");

    LeMatriz(m, 4, 4);

    ImprimeMatriz(m, 4, 4);

    return 0;
}

void LeMatriz(int Matriz[][4], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &Matriz[i][j]);
}

void ImprimeMatriz(int Matriz[][4], int lin, int col)
{
    int i, j;
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
            printf("[%2d] ", Matriz[i][j]);
        printf("\n");
    }
}
