#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float i=1, sum=0;

    printf("Digite qual o termo devera ser somado do seguinte somatorio (1+1/2+...+1/n)\n");
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    while (i <= n)
    {
        sum+=(1/i);
        i++;
    }

    printf("O somatorio e: %.2f", sum);

    return 0;
}
