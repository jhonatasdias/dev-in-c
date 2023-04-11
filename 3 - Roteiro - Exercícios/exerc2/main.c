#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b=7;

    printf("Todos os numeros multiplos de 7 menores que 1000.\n");

    while (b < 1000)
    {
        printf("%d, ", b);
        b += 7;
    }

}
