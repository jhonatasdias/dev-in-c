#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int x, y = 0;
    int subt = 0;
    printf("Subtrair o primeiro pelo segundo.\n");
    printf("Digite o primeiro valor: ");
    scanf("%d/n",&x);
    printf("Digite o segundo valor: ");
    scanf("%d/n",&y);
    subt = x - y;
    printf("A subtracao do primeiro pelo segundo e: %d \n", subt);
    return (0);
}
