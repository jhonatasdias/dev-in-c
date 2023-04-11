#include <stdio.h>
#include <stdlib.h>

int main()
{
    float basemaior, basemenor, altura, area;
    printf("Calcular area do trapezio.\n");
    printf("Digite o valor da base maior: ");
    scanf("%f",&basemaior);
    printf("Digite o valor da base menor: ");
    scanf("%f",&basemenor);
    printf("Digite o valor da altura: ");
    scanf("%f",&altura);

    area = (basemaior + basemenor)*altura/2;

    printf("A area do trapezio e: %.2f",area);
    return 0;
}
