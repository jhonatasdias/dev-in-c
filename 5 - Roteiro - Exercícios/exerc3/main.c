#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c, k;

    printf("Tabela de conversao de C para K com variação unitária.\n");
    printf("Celsius\t\tKelvin\n");

    for(int i=0; i<=100; i++)
    {
        c = i;
        k = c + 273.15;
        printf("%.2f \t\t %.2f\n", c, k);
    }
    return 0;
}
