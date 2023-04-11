#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite dois numeros no teclado e sera informado o maior.\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    if (a > b)
    {
        printf("O primeiro e o maior numero.\n");
    }
    else if (b > a)
    {
        printf("O segundo e o maior numero.\n");
    }

    return 0;
}
