#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,nf;
    int p1=2,p2=3;
    printf("Mostre a media ponderada de duas notas.\n");
    printf("Digite a primeira nota: ");
    scanf("%f",&n1);
    printf("Digite a segunda nota: ");
    scanf("%f",&n2);

    nf = (n1*p1 + n2*p2)/(p1 + p2);

    printf("A nota final e: %.2f\n",nf);
    return 0;
}
