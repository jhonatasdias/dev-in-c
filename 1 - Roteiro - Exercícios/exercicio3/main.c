#include <stdio.h>
#include <stdlib.h>

int main()
{
    //pre�o do produto=pp; pre�o com desconto=pcd, desconto=d
    float pp, pcd, d=10;
    printf("Calcular o preco com desconto de 10 por cento.\n");
    printf("Digite o pre�o do produto: ");
    scanf("%f",&pp);
    pcd = pp*(1-d/100);
    printf("O valor do produto com desconto e: %.2f\n",pcd);
    return 0;
}
