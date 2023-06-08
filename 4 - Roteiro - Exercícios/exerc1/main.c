#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0, a;

    printf("Digite um numero indefinido de valores e mostre a soma, sendo 0 pode parar o programa.");
    printf("Digite os valores: ");
    scanf("%d", &a);

    sum=sum+a;

    while(a != 0)
    {
        scanf("%d", &a);
        sum=sum+a;
    }

    printf("A soma e: %d", sum);

    return 0;
}
