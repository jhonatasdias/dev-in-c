#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct REGISTRO
{
    int idade;
    float salario;
};

void leRegistro(struct REGISTRO cliente[]);

float mediaIdade(struct REGISTRO cliente[]);

float mediaSalario(struct REGISTRO cliente[]);

int main()
{
    struct REGISTRO cliente[TAM];

    float mediaSal = 0, mediaIda = 0, acimaMediaSal[TAM], abaixoMediaSal[TAM];
    int contSAc = 0, contSAb = 0, i = 0;

    leRegistro(cliente);

    mediaSal = mediaSalario(cliente);

    mediaIda = mediaIdade(cliente);

    while(i < TAM)
    {
        if(cliente[i].salario > mediaSal)
            acimaMediaSal[contSAc++] = cliente[i].salario;
        else
            abaixoMediaSal[contSAb++] = cliente[i].salario;
        i++;
    }

    printf("Media de Idade: %.2f\n", mediaIda);
    printf("Media de salario: %.2f\n", mediaSal);
    printf("Salario acima da media: ");
    for(int j = 0; j < contSAc; j++)
        printf("%.2f ", acimaMediaSal[j]);
    printf("\n");
    printf("Salario abaixo da media: ");
    for(int j = 0; j < contSAb; j++)
        printf("%.2f ", abaixoMediaSal[j]);
    printf("\n");

    return 0;
}

void leRegistro(struct REGISTRO cliente[])
{
    int i = 0;
    while(i < TAM)
    {
        printf("Digite a idade: ");
        scanf("%d", &cliente[i].idade);
        printf("Digite o salario: ");
        scanf("%f", &cliente[i].salario);
        i++;
    }
}

float mediaIdade(struct REGISTRO cliente[])
{
    int i = 0, soma = 0;
    while(i < TAM)
    {
        soma += cliente[i].idade;
        i++;
    }
    return soma/ (float)TAM;
}

float mediaSalario(struct REGISTRO cliente[])
{
    int i = 0, soma = 0;
    while(i < TAM)
    {
        soma += cliente[i].salario;
        i++;
    }
    return soma/ (float)TAM;
}
