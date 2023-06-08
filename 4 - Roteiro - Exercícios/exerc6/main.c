#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=21;
    float sum=0, i=250;

    printf("O programa mostrara o resultado do seguinte somatorio j = 21/250 + 22/249 +...+ 250/21\n");

    while (i >= 21)
    {
        sum+= n/i;
        n++;
        i--;
    }

    printf("Resultado: %.2f\n", sum);

    return 0;
}
