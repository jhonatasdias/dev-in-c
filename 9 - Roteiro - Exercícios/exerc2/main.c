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

void imprimeCadastro(struct REGISTRO cliente);

int main()
{
    struct REGISTRO cliente1;
    leCadastro(&cliente1);
    imprimeCadastro(cliente1);

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

void imprimeCadastro(struct REGISTRO cliente)
{
    printf("Seu codigo e: %d\n", cliente.cod);
    printf("Seu nome e: %s\n", cliente.name);
    printf("Sua idade e: %d\n", cliente.idade);
    printf("Seu sexo e: %c\n", cliente.sexo);
    printf("Seu salario e: %.2f\n", cliente.salario);
}
