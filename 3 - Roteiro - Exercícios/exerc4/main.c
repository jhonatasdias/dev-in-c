#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b=1, test;
    printf("Verificar quais os numeros divisores desse numero.\n");
    do
    {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &a);
    }
    while(a <= 0);

    while(b <= a)
    {
        test = a % b;
        if(test == 0)
        {
            printf("%d, ", b);
        }
        b++;
    }
    return 0;
}
