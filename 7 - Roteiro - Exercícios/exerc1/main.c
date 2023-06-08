#include <stdio.h>
#include <stdlib.h>

ler_vetor();

int main()
{
    int vetorA[10], vetorB[10], vetorC[10];
    printf("Digite 10 numeros para o conjunto A:\n");
    ler_vetor(vetorA,10);

    printf("Digite 10 numeros para o conjunto B:\n");
    ler_vetor(vetorB,10);

    for(int i = 0; i < 10; i++)
    {
        if(vetorA[i] < vetorB[i])
            vetorC[i] = vetorA[i];
        else
            vetorC[i] = vetorB[i];

        printf("Vetor C[%d]: %d\n", i, vetorC[i]);
    }

    return 0;
}

int ler_vetor(int vetor[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("Leia o %d numero ", i+1);
        scanf("%d", &vetor[i]);
    }
}
