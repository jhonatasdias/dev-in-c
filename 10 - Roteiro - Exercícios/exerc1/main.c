#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nome[30];
    char curso[30];
    int notaPrava1;
    int notaProva2;
    int notaProvaFinal;
} ALUNOS;

void leAlunos(ALUNOS *aluno);

int main(void)
{
    FILE *arquivo;
    ALUNOS aluno;
    //criando arquivo binario
    if((arquivo = fopen("alunos.dat", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    leAlunos(&aluno);
    //gravar a estrutura de dados aluno
    fwrite(&aluno, sizeof(aluno), 1, arquivo);
    //fechando arquivo
    fclose(arquivo);

    //lendo arquivo binario
    arquivo = fopen("alunos.dat", "rb");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fread(&aluno, sizeof(aluno), 1, arquivo);


    printf("Nome do aluno: %s\n", aluno.nome);
    printf("Nota final do aluno (p1 + p2) = %d\n", aluno.notaPrava1 + aluno.notaProva2);

    return 0;
}

void leAlunos(ALUNOS *aluno)
{
    printf("Digite as infações do aluno.\n");
    printf("Digite o numero da matricula: ");
    scanf("%d", &aluno->matricula);
    printf("Digite o nome: ");
    scanf("%s", aluno->nome);
    printf("Digite o nome do curso: ");
    scanf("%s", aluno->curso);
    printf("Digite a nota da prova1: ");
    scanf("%d", &aluno->notaPrava1);
    printf("Digite a nota da prova2: ");
    scanf("%d", &aluno->notaProva2);
    printf("Digite a nota da prova final: ");
    scanf("%d", &aluno->notaProvaFinal);
}
