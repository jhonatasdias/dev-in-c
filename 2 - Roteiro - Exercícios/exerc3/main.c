#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Verificar se um numero e par ou impar.\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &a);

    if (a % 2 == 0)
    {
        printf("E um numero par.\n");
    }
    else
    {
        printf("E um numero impar.\n");
    }

    return 0;
}
