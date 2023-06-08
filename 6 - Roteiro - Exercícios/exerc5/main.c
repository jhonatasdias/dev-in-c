#include <stdio.h>
#include <stdlib.h>

conv_data();

int main()
{
    int dd, d, m, a;
    printf("Mostrar quantos dias se passaram desde a data de 01/01/1900.\n");
    printf("Degite o dia, mes e o ano, repectivamente: ");
    scanf("%d %d %d", &d, &m, &a);

    dd=conv_data(d, m, a);

    printf("Se passaram %d dias.", dd);

    return 0;
}

int conv_data(int d, int m, int a)
{
    int dd;

    dd=(a-1900)*365;

    for(int i=1; i<=m; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            dd+=31;
        else if(i == 2)
            dd+=28;
        else
            dd+=30;
    }

    dd+=d;

    return dd;
}
