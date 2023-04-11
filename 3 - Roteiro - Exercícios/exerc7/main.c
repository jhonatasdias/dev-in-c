#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, soma=0, qut=10;

    printf("Digite 10 numeros inteiros e apresente a soma deles:\n");

    do
    {
        scanf("%d", &a);
        soma+=a;
        qut-=1;
    }
    while(qut>0);

    printf("Soma=%d\n", soma);

    return 0;
}
