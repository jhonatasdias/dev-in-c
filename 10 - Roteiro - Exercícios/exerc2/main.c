#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct
{
    int matricula;
    char nome[30];
    char curso[30];
    int notaPrava1;
    int notaProva2;
    int notaProvaFinal;
} ALUNOS;

void leAlunos(ALUNOS aluno[]);

int main()
{
    FILE *arquivo;
    ALUNOS aluno[TAM];
    //criando arquivo binario
    if((arquivo = fopen("alunos.dat", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    leAlunos(aluno);
    //gravar a estrutura de dados aluno
    fwrite(aluno, sizeof(ALUNOS), TAM, arquivo);
    //fechando arquivo
    fclose(arquivo);

    //lendo arquivo binario
    arquivo = fopen("alunos.dat", "rb");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fread(aluno, sizeof(ALUNOS), TAM, arquivo);

    int i=0;
    while(i < TAM)
    {
        printf("Nome do %d aluno: %s\n", i + 1,aluno[i].nome);
        printf("Nota final do %d aluno (p1 + p2) = %d\n", i + 1, aluno[i].notaPrava1 + aluno[i].notaProva2);
        i++;
    }

    return 0;
}

void leAlunos(ALUNOS aluno[])
{
    int i = 0;
    while(i < TAM)
    {
        printf("Digite as infacoes do %d aluno.\n", i+1);
        printf("Digite o numero da matricula: ");
        scanf("%d", &aluno[i].matricula);
        printf("Digite o nome: ");
        scanf("%s", aluno[i].nome);
        printf("Digite o nome do curso: ");
        scanf("%s", aluno[i].curso);
        printf("Digite a nota da prova1: ");
        scanf("%d", &aluno[i].notaPrava1);
        printf("Digite a nota da prova2: ");
        scanf("%d", &aluno[i].notaProva2);
        printf("Digite a nota da prova final: ");
        scanf("%d", &aluno[i].notaProvaFinal);
        i++;
    }
}
