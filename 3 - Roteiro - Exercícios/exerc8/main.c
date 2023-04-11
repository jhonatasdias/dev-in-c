#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, soma=0;
    printf("Digite varios numeros menor que 13, verifique se acabou até chegar a 21.\n");
    printf("Digite um numero: ");
    scanf("%d", &a);

    soma+=a;

    while(soma < 21)
    {
        printf("Ainda nao acabou.\n");
        scanf("%d", &a);
        soma+=a;
    }
    if(soma > 21)
    {
        printf("Acabou.\n");
    }
    else if(soma == 21)
    {
        printf("Acabado, soma = %d", soma);
    }

    return 0;
}
