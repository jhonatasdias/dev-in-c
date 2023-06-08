#include <stdio.h>
#include <stdlib.h>

struct REGISTRO
{
    int cod;
    char name[20];
    int idade;
    char sexo;
    float salario;
};

void leCadastro(struct REGISTRO *R);

int main()
{
    struct REGISTRO cliente1;
    leCadastro(&cliente1);

    printf("Seu nome e: %s", cliente1.name);

    return 0;
}

void leCadastro(struct REGISTRO *R)
{
    printf("Digite seu cod: ");
    scanf("%d", &R->cod);
    printf("Digite seu nome: ");
    scanf("%s", R->name);
    printf("Digite sua idade: ");
    scanf("%d", &R->idade);
    printf("Digite seu sexo F/M(Feminino/Masculino): ");
    scanf(" %c", &R->sexo);
    printf("Digite seu salario: ");
    scanf("%f", &R->salario);
}

