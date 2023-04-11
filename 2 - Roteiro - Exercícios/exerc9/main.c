#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2, n3, n4, media;

    printf("Tira a media de quatro notas e verificar se e aprovado com media 6 ou nao.\n");
    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);
    printf("Digite a quarta nota: ");
    scanf("%f", &n4);

    media = (n1 + n2 + n3 + n4)/4.0;

    if (media >= 60)
    {
        printf("Aprovado com media=%.2f.\n", media);
    }
    else
    {
        printf("Reprovado com media=%.2f.\n", media);
    }

    return 0;
}
