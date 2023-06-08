#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f, c;

    printf("Tabela que mostre a conversão de C para F com diferenca unitaria.\n");

    printf("Celsius\t\tFahrenheit\n");
    for(int i=0; i<=100; i++)
    {
        c = i;
        f = c * 9/5.0 + 32;
        printf("%.2f\t\t%.2f\n", c, f);
    }
    return 0;
}
