#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ang1,ang2,ang3;
    printf("Calcular a medida do terceiro angulo de um triangulo.\n");
    printf("Digite o valor do primeiro angulo: ");
    scanf("%f",&ang1);
    printf("Digite o valor do segundo angulo: ");
    scanf("%f",&ang2);

    ang3 = 180.0 - ang1 - ang2;

    printf("O valor do terceiro angulo e: %.2f\n",ang3);

    return 0;
}
