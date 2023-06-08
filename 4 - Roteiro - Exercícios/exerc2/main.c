#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0, a, i=0;

    printf("Digite um numero indefinido de valores e mostre a soma, sendo 0 pode parar o programa.");
    printf("Digite os valores: ");
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

    return 0;
}
