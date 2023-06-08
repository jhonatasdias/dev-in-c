#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

typedef struct
{
    int cod;
    char nome[30];
    int idade;
    char sexo;
    float salario;
} REGISTRO;

void leRegistro(REGISTRO cliente[]);
void imprimeRegistro(REGISTRO cliente[]);

int main(void)
{
    int exe = 1;
    char pesquisa[30];
    REGISTRO cliente[TAM];

    leRegistro(cliente);

    printf("Digite o nome do cliente que deseja encontrar: ");
    while(exe)
    {
        scanf("%s", pesquisa);
        for(int i = 0; i < TAM; i++)
        {
            if(strcmp(pesquisa, cliente[i].nome) == 0)
            {
                printf("Codigo  Nome                Idade   Sexo     Salario\n");
                printf("%-7d %-20s %-7d %-7c %.2f\n", cliente[i].cod, cliente[i].nome, cliente[i].idade, cliente[i].sexo, cliente[i].salario);
                exe = 0;
                break;
            }
        }
        printf("Cliente nao encontrado tente novamente.\n");
    }

    return 0;
}

void leRegistro(REGISTRO cliente[])
{
    int i = 0;
    while(i < TAM)
    {
        printf("Digite o codigo: ");
        scanf("%d", &cliente[i].cod);
        printf("Digite o nome: ");
        scanf("%s", &cliente[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &cliente[i].idade);
        printf("Digite o sexo feminino ou masculino (F/M): ");
        scanf(" %c", &cliente[i].sexo);
        printf("Digite o salario: ");
        scanf("%f", &cliente[i].salario);
        i++;
    }
}

void imprimeRegistro(REGISTRO cliente[])
{
    int i = 0;
    printf("Codigo  Nome                Idade   Sexo     Salario\n");
    while(i < TAM)
    {
        printf("%-7d %-20s %-7d %-7c %.2f\n", cliente[i].cod, cliente[i].nome, cliente[i].idade, cliente[i].sexo, cliente[i].salario);
        i++;
    }
}

