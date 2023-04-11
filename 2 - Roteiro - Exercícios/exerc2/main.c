#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    printf("Leia um numero real e informar se ele e positivo, negativo ou nulo.\n");
    printf("Digite um número real: ");
    scanf("%f", &a);

    if (a > 0)
    {
        printf("E um numero positivo.\n");
    }
    else if (a < 0)
    {
        printf("E um numero negativo.\n");
    }
    else
    {
        printf("E um numero nulo.\n");
    }

    return 0;
}
