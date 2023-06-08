#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0, a, i=0, cont=1;

    printf("Digite um numero indefinido de valores e mostre a soma (0 para sair).");
    printf("Digite os valores: ");

    while (cont)
    {
        scanf("%d", &a);

        sum=sum+a;

        while(a != 0)
        {
            scanf("%d", &a);
            sum=sum+a;
            i++;
        }

        printf("A soma e: %d\n", sum);
        printf("Quantidade de valores somados: %d\n", i);

        printf("Digite 1 para continuar: ");
        scanf("%d", &cont);
    }

    return 0;
}
