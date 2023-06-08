#include <stdio.h>
#include <stdlib.h>
#define TAM 150

int main()
{
    FILE *arquivo;
    char poema[TAM];

    if((arquivo = fopen("poema.txt", "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite seu poema: ");
    fgets(poema, TAM, stdin);

    fwrite(poema, sizeof(char), TAM, arquivo);

    fclose(arquivo);

    printf("Salvamento executado com sucesso.\n");

    return 0;
}
