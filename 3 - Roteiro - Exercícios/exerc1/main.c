#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite dois numeros inteiros, sera mostrado todos os numerdos dentro desse intervalo(fechado), [x,y].\n");
    printf("Digite o numero que representa o limite inferior: ");
    scanf("%d", &a);
    printf("Digite o numero que representa o limite superior: ");
    scanf("%d", &b);
    while (a <= b)
    {
        printf("%d, ", a);
        ++a;
    }
    return 0;
}
