#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct
{
    int matricula;
    char nome[30];
    char curso[30];
    int notaProva1;
    int notaProva2;
    int notaProvaFinal;
} ALUNOS;

void leAlunos(ALUNOS aluno[]);

void imprimeAlunos(ALUNOS aluno[]);

int main()
{
    FILE *cadastroAlunos;
    ALUNOS aluno[TAM];
    int matricula;

    if((cadastroAlunos = fopen("cadastroAlunos.dat", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    leAlunos(aluno);

    fwrite(aluno, sizeof(ALUNOS), TAM, cadastroAlunos);

    fclose(cadastroAlunos);

    if((cadastroAlunos = fopen("cadastroAlunos.dat", "r+b")) == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    printf("Digite o numero da matricula do aluno que deseja alterar os dados: ");
    scanf("%d", &matricula);

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno[matricula - 1].nome);
    printf("Digite o nome do curso: ");
    scanf("%s", aluno[matricula - 1].curso);
    printf("Digite a nota da prova 1: ");
    scanf("%d", &aluno[matricula - 1].notaProva1);
    printf("Digite a nota da prova 2: ");
    scanf("%d", &aluno[matricula - 1].notaProva2);
    printf("Digite a nota da prova final: ");
    scanf("%d", &aluno[matricula - 1].notaProvaFinal);

    fseek(cadastroAlunos, (matricula - 1)*sizeof(ALUNOS), 0);

    fwrite(&aluno[matricula - 1], sizeof(ALUNOS), 1, cadastroAlunos);

    fclose(cadastroAlunos);

    imprimeAlunos(aluno);

    return 0;
}

void leAlunos(ALUNOS aluno[])
{
    int i = 0;
    while(i < TAM)
    {
        printf("Digite o numero da matricula: ");
        scanf("%d", &aluno[i].matricula);
        printf("Digite o nome do aluno: ");
        scanf("%s", aluno[i].nome);
        printf("Digite o nome do curso: ");
        scanf("%s", aluno[i].curso);
        printf("Digite a nota da prova 1: ");
        scanf("%d", &aluno[i].notaProva1);
        printf("Digite a nota da prova 2: ");
        scanf("%d", &aluno[i].notaProva2);
        printf("Digite a nota da prova final: ");
        scanf("%d", &aluno[i].notaProvaFinal);
        i++;
    }
}

void imprimeAlunos(ALUNOS aluno[])
{
    int i=0;
    while(i < TAM)
    {
        printf("Digite o numero da matricula: %d\n", aluno[i].matricula);
        printf("Digite o nome do aluno: %s\n", aluno[i].nome);
        printf("Digite o nome do curso: %s\n", aluno[i].curso);
        printf("Digite a nota da prova 1: %d\n", aluno[i].notaProva1);
        printf("Digite a nota da prova 2: %d\n"), aluno[i].notaProva2;
        printf("Digite a nota da prova final: %d\n", aluno[i].notaProvaFinal);
        i++;
    }
}
