#include <stdio.h>
#include <stdlib.h>
#include <math.h>>

int main()
{
    float s, c, r;
    const float PI = M_PI;

    printf("Tabela que mostre seno e cosseno de 0 a 360 (graus) e de 15 em 15 (graus).\n");
    printf("Graus\t\tSeno\t\tCosseno\n");

    for (int i=0; i<=360; i+=15)
    {
        r = i * PI/180.0;
        s = sin(r);
        c = cos(r);
        printf("%d \t\t %.2f \t\t %.2f\n", i, s, c);
    }
    return 0;
}
