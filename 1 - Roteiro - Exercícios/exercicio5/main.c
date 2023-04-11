#include <stdio.h>
#include <stdlib.h>

int main()
{
    //quantidade de salarios minimos=qut
    float salariom, salariof, qut;
    printf("Calcular a quantidade de salarios minimos.\n");
    printf("Digite o salario minimo: ");
    scanf("%f",&salariom);
    printf("Digite o salario do funcionario: ");
    scanf("%f",&salariof);

    qut = salariof/salariom;

    printf("Quantidade de salarios: %.2f",qut);
    return 0;
}
