#include <stdio.h>
#include <stdlib.h>
#define TAM 256

int main()
{
    int i, letras[TAM], espaco=0, letrapP=0;
    char texto[121];

    printf("Digite o texto: ");
    fgets(texto, 121, stdin);

    for(int i = 0; i < TAM; i++)
        letras[i]=0;

    for(int i = 0; texto[i]!=0; i++)
        letras[texto[i]]++; /*o indice assume valor inteiro, como texto[i]
        tem como saida uma letra, se for letra a 2x, assumira
        o mesmo indice 2x somando assim letra[a=65]=2, depois eh so imprimir a tabela ascII, letra[a] até letra[z]*/
     for(int i = 0; texto[i]!=0; i++)
        if(texto[i] == ' ')
            espaco++;

    printf("Quantidade de espacos: %d\n", espaco);

    for(int i = 0; texto[i]!=0; i++)
        if(texto[i] == 'p' || texto[i] == 'P')
            letrapP++;

    printf("Quantidade de p(s)/P(s): %d\n", letrapP);

    for(int i = 'a'; i <= 'z'; i++)
    {
        if(letras[i]!=0)
            printf("%c = %d\n", i, letras[i]);
    }
    return 0;
}
