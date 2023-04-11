#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Operação com if
    float a, b, res;
    char opr;

    printf("Program para ler dois numeros e fazer o usuario escolher as quatro operações básicas e mostrar o resultado.\n");
    printf("Digite o primeiro numero: ");
    scanf("%f", &a);
    printf("Digite o segundo numero: ");
    scanf("%f", &b);
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &opr);

    if (opr == '+')
    {
        printf("Resultado=%.2f.\n", a + b);
    }
    else if (opr == '-')
    {
        printf("Resultado=%.2f.\n", a - b);
    }
    else if (opr == '*')
    {
        printf("Resultado=%.2f.\n", a * b);
    }
    else if (opr == '/')
    {
        if (b == 0)
        {
            printf("Nao e possivel divir por 0.\n");
        }
        else
        {
            res = a / b;
            printf("Resultado=%.2f.\n", res);
        }
    }

    return 0;
}
