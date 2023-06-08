#include <stdio.h>
#include <stdlib.h>

le_no_intervalo();

int main()
{
    int dia, mes;
    printf("Informe o mes entre 1 e 12: ");
    mes = le_no_intervalo(1,12);
    if(mes == 2)
    {
        printf("Informe o dia entre 1 e 28: ");
        dia = le_no_intervalo(1,28);
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        printf("Informe o dia entre 1 e 30: ");
        dia = le_no_intervalo(1,30);
    }
    else
    {
        printf("Informe o dia entre 1 e 31: ");
        dia = le_no_intervalo(1,31);
    }
    printf("Data: %02d/%02d\n", dia, mes);
    return 0;
}

int le_no_intervalo(int de, int ate)
{
    int x;
    do
    {
        scanf("%d", &x);
    }
    while(x<de || x>ate);
    return x;
}
