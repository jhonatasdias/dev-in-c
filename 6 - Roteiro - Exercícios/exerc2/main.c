#include <stdio.h>
#include <stdlib.h>

verifica_num_primo();

int main()
{
    int a, primo;
    printf("Verifique se um numero e primo ou nao.\n");
    scanf("%d", &a);
    primo = verifica_num_primo(a);
    printf("primo = %d\n", primo);
    return 0;
}

int verifica_num_primo(int x)
{
    int div=0;
    for(int i=1; i<=x; i++)
    {
        if(x % i == 0)
        {
            div++;
        }
    }
    if(div==2)
        return 1;
    else
        return 0;
}
