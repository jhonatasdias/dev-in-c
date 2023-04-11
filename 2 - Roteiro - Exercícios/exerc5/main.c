#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Digite um numero e verificar se ele e divisivel por 2 e 7 ao mesmo tempo.\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &a);

    if (a % 2 == 0 && a % 7 == 0)
    {
        printf("O numero %d e divisivel por 2 e 7 simultaneamente.\n", a);
    }
    else
    {
        printf("O valor %d nao e divisivel por 2 e 7 simultaneamente.\n", a);
    }

    return 0;
}
