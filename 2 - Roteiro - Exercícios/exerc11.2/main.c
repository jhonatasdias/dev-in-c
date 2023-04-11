#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Com switch;
    int a;
    printf("Pragrama que mostre 5 opcoes ao usuario.\n");
    printf("Digite um numero entre 1 a 5: ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        printf("O valor digitado e: %d", a);
        break;
    case 2:
        printf("O valor digitado e: %d", a);
        break;
    case 3:
        printf("O valor digitado e: %d", a);
        break;
    case 4:
        printf("O valor digitado e: %d", a);
        break;
    case 5:
        printf("O valor digitado e: %d", a);
        break;
    }

    return 0;
}
