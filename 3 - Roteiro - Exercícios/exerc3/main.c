#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Digite dois numeros inteiro sendo necessariamente x<=y, depois imprimir todos os numeros dentro do intervalo(fechado)\n");
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    if (x <= y)
    {
        while (x <= y)
        {
            printf("%d, ", x);
            ++x;
        }
    }
    else
    {
        printf("Digite somente valores onde x<=y.\n");
        return 0;
    }
}
