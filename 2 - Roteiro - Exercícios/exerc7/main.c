#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, sum;
    printf("Ler tres numeros e informar a soma dos maiores.\n");
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero inteiro: ");
    scanf("%d", &c);

    if(a < b && a < c)
    {
        sum = b + c;
        printf("A soma e %d.\n", sum);
    }
    else if (b < a && b < c)
    {
        sum = a + c;
        printf("A soma e %d.\n", sum);
    }
    else if (c < a && c < b)
    {
        sum = a + b;
        printf("A soma e %d.\n", sum);
    }

    return 0;
}
