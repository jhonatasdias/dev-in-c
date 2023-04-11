#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Ler tres numeros e informar e o menor.\n");
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero inteiro: ");
    scanf("%d", &c);

    //Para valor maior
    if(a > b && a > c)
    {
        printf("O numero %d e o maior.\n", a);
    }
    else if (b > a && b > c)
    {
        printf("O numero %d e o maior.\n", b);
    }
    else if (c > a && c > b)
    {
        printf("O numero %d e o maior.\n", c);
    }

    //Para valor menor
    if(a < b && a < c)
    {
        printf("O numero %d e o menor.\n", a);
    }
    else if (b < a && b < c)
    {
        printf("O numero %d e o menor.\n", b);
    }
    else if (c < a && c < b)
    {
        printf("O numero %d e o menor.\n", c);
    }

    return 0;
}
