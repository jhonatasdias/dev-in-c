#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cm, in;

    printf("Tabela de conversao de cm para polegada de 2 em 2.\n");
    printf("Centimetro\t\tPolegada\n");

    for(int i=0; i<=100; i+=2)
    {
        cm = i;
        in = cm / 2.54;
        printf("%.2f\t\t%.2f\n", cm, in);
    }
    return 0;
}
