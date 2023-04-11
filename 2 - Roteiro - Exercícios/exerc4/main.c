#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Informe um numero inteiro para obter um valor absoluto.\n");
    printf("Digite um valor inteiro: ");
    scanf("%d", &a);

    if (a >= 0)
    {
        printf("O valor absoluto e %d.\n", a);
    }
    else
    {
        a = -a;
        printf("O valor absoluto e %d.\n", a);
    }

    return 0;
}
