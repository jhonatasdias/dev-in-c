#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=50;
    float sum=0, i=1;

    printf("Digite o ultimo termo para ser somado do seguinte somatorio (1+3/2+5/7+...+99/50)\n");

    while (i <= n)
    {
        sum+= (2 * i - 1)/i;
        i++;
    }

    printf("O somatorio e: %.2f", sum);

    return 0;
}
