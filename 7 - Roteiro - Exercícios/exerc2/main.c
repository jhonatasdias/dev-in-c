#include <stdio.h>
#include <stdlib.h>

ler_vetor();

int main()
{
    int n;
    printf("Digite a quantidade de numeros a ser analisado: ");
    scanf("%d", &n);

    int vetor[n], vetorP[n], vetorN[n];
    int quantP=0, quantN=0;

    ler_vetor(vetor,n);

    for(int i = 0; i < n; i++)
    {
        if(vetor[i] > 0)
        {
            vetorP[quantP] = vetor[i];
            quantP++;
        }
        if(vetor[i] < 0)
        {
            vetorN[quantN] = vetor[i];
            quantN++;
        }

    }
    printf("Numeros positivos: %d\n", quantP);
    for(int i = 0; i < quantP; i++)
        printf("%d ", vetorP[i]);

    printf("\n");

    printf("Numeros negativos: %d\n", quantN);
    for(int i = 0; i < quantN; i++)
        printf("%d ", vetorN[i]);

    return 0;
}

int ler_vetor(int vetor[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &vetor[i]);
    }
}
