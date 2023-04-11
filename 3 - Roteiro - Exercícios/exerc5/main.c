#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Digite um numero inteiro e informar em ordem decrescente os impares menor que esse numero.\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &a);

    b = a;

    if(b % 2 != 0)
    {
        while(b > 0)
        {
            printf("%d, ", b);
            b-=2;
        }
    }
    else if(b % 2 == 0)
    {
        b--;
        while(b > 0)
        {
            printf("%d, ", b);
            b-=2;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}
