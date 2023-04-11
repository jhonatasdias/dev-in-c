#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ch = carga horaria, salh = salario hora, sall = salario liquido, salb = salario bruto, desc = desconto.
    float ch, salh, sall, salb, desc;
    printf("Calcule o salario liquido do funcionario.\n");
    printf("Qual a carga hoararia de trabalho: ");
    scanf("%f", &ch);
    printf("Qual o salario hora: ");
    scanf("%f", &salh);

    salb = ch * salh;

    if (salb < 350)
    {
        desc = salb * 0;
    }
    else if (salb < 1000)
    {
        desc = salb * 0.1;
    }
    else
    {
        desc = salb * 0.2;
    }

    sall = salb - desc;

    printf("Salario liquido: %.2f\n", sall);

    return 0;
}
