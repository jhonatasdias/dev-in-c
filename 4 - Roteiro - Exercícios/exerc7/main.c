#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,d=1;
    float i=1, sum=0;

    printf("Programa calculara o somatorio de n termos da seguinte equacao L = 1 - 2/4 + 3/9 -...+n/n^2");
    printf("Digite o valor n: ");
    scanf("%d", &n);

    sum=1;
    i=2;
    d=2;

    while (d <= n)
    {
        if (d % 2 == 0)
        {
            sum+= (i/pow(i,2)) * (-1);
            i++;
            d++;
        }
        else
        {
            sum+= (i/pow(i,2));
            i++;
            d++;
        }
    }

    printf("Resultado: %.2f\n", sum);

    return 0;
}
