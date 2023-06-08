#include <stdio.h>
#include <stdlib.h>
#define TAM 150

int main()
{
    FILE *arquivo;
    char poema[TAM];

    if((arquivo = fopen("poema.txt", "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fread(poema, sizeof(char), TAM - 1, arquivo);

    fclose(arquivo);

    printf("Seu poema e: %s", poema);

    return 0;
}
