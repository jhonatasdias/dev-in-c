#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b=1, fatorial=1;


    printf("Ler um numero inteiro e informar o fatorial desse numero.\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &a);

    while(b <= a)
    {
        fatorial = fatorial * b;
        b++;
    }

    printf("Fatorial de %d = %d", a, fatorial);

    return 0;
}
