#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Operação com switch
    float a, b, res;
    char opr;

    printf("Program para ler dois numeros e fazer o usuario escolher as quatro operações básicas e mostrar o resultado.\n");
    printf("Digite o primeiro numero: ");
    scanf("%f", &a);
    printf("Digite o segundo numero: ");
    scanf("%f", &b);
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &opr);

    switch (opr)
    {
    case '+':
        res = a + b;
        printf("Resultado:%.2f\n", res);
        break;
    case '-':
        res = a - b;
        printf("Resultado:%.2f\n", res);
        break;
    case '*':
        res = a * b;
        printf("Resultado:%.2f\n", res);
        break;
    case '/':
        if (b == 0)
        {
            printf("Nao e possivel divir por 0.\n");
        }
        else
        {
            res = a / b;
            printf("Resultado:%.2f\n", res);
        }
        break;
    }

    return 0;
}
