#include <stdio.h>
#include <stdlib.h>

ler_vetor();

int main()
{
    int vetor[10];
    int menor=999, maior=0;
    int soma=0;
    float media;

    ler_vetor(vetor,10);

    for(int i = 0; i < 10; i++)
    {
        if(vetor[i] < menor)
            menor = vetor[i];
        if(vetor[i] > maior)
            maior = vetor[i];
        soma+=vetor[i];
    }

    media = soma / 10;

    printf("A maior Temperatura: %d\n", maior);
    printf("A menor Temperatura: %d\n", menor);
    printf("A temperatura media: %.2f\n", media);
    printf("Temperatura inferior da media: ");
    for(int i = 0; i < 10; i++)
        if(vetor[i] < media)
            printf("%d ", vetor[i]);

    return 0;
}

int ler_vetor(int vetor[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Digite a %d temperatura, sendo minimo de 15C e maximo de 40C: ", i+1);
        do
        {
            scanf("%d", &vetor[i]);
        }
        while(vetor[i] < 15 || vetor[i] > 40);
    }
}
