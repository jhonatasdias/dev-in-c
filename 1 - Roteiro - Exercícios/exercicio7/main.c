#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //Dados de uma esfera
    float r,c,a,v;
    const float pi=M_PI;
    printf("Calcular o comprimento, a area, o volume de uma esfera.\n");
    printf("Digite o valor do raio: ");
    scanf("%f",&r);
    //Formula do comprimento
    c = 2*pi*r;
    //Formula da area
    a = pi*pow(r,2);
    //Formula do volume
    v = (3.0/4.0)*pi*pow(r,3);

    printf("O valor do comprimento da esfera: %.2f\n",c);
    printf("O valor da area da esfera: %.2f\n",a);
    printf("O valor do volume da esfera: %.2f\n",v);

    return 0;
}
