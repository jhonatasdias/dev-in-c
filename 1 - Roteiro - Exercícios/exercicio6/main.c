#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int c1,c2;
    float h;
    printf("Calcular a hipotenusa de um triangulo.\n");
    printf("Digite o valor de um dos catetos: ");
    scanf("%d",&c1);
    printf("Digite o calo do outro catedo: ");
    scanf("%d",&c2);

    h = sqrt(pow(c1,2)+pow(c2,2));

    printf("A hipotenusa do trinagulo e: %.2f",h);
    return 0;
}
