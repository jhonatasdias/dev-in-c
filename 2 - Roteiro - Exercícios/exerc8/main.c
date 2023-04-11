#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    printf("Ler quatro numeros e informar em ordem decrescente.\n");
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero inteiro: ");
    scanf("%d", &c);
    printf("Digite o quarto numero inteiro: ");
    scanf("%d", &d);

    //a o maior de todos
    if (a > b && a > c && a > d)
    {
        printf ("%d, ", a);

        if (b > c && b > d)
        {
            printf("%d, ", b);

            if (c > d)
            {
                printf("%d, %d", c, d);
            }
            else
            {
                printf("%d, %d", d, c);
            }
        }
        else if (c > b && c > d)
        {
            printf("%d, ", c);

            if (b > d)
            {
                printf("%d, %d", b, d);
            }
            else
            {
                printf("%d, %d", d, b);
            }
        }
        else
        {
            printf("%d, ", d);

            if (b > c)
            {
                printf("%d, %d", b, c);
            }
            else
            {
                printf("%d, %d", c, b);
            }
        }
    }

    //b o maior de todos
    if (b > a && b > c && b > d)
    {
        printf ("%d, ", b);

        if (a > c && a > d)
        {
            printf("%d, ", a);

            if (c > d)
            {
                printf("%d, %d", c, d);
            }
            else
            {
                printf("%d, %d", d, c);
            }
        }
        else if (c > a && c > d)
        {
            printf("%d, ", c);

            if (a > d)
            {
                printf("%d, %d", a, d);
            }
            else
            {
                printf("%d, %d", d, a);
            }
        }
        else
        {
            printf("%d, ", d);

            if (a > c)
            {
                printf("%d, %d", a, c);
            }
            else
            {
                printf("%d, %d", c, a);
            }
        }
    }

    //c o maior de todos
    if (c > a && c > b && c > d)
    {
        printf ("%d, ", c);

        if (a > b && a > d)
        {
            printf("%d, ", a);

            if (b > d)
            {
                printf("%d, %d", b, d);
            }
            else
            {
                printf("%d, %d", d, b);
            }
        }
        else if (c > a && c > d)
        {
            printf("%d, ", b);

            if (a > d)
            {
                printf("%d, %d", a, d);
            }
            else
            {
                printf("%d, %d", d, a);
            }
        }
        else
        {
            printf("%d, ", d);

            if (a > b)
            {
                printf("%d, %d", a, b);
            }
            else
            {
                printf("%d, %d", b, a);
            }
        }
    }

    //d o maior de todos
    if (d > a && d > b && d > c)
    {
        printf ("%d, ", d);

        if (a > b && a > c)
        {
            printf("%d, ", a);

            if (b > d)
            {
                printf("%d, %d", b, d);
            }
            else
            {
                printf("%d, %d", d, b);
            }
        }
        else if (b > a && b > c)
        {
            printf("%d, ", b);

            if (a > c)
            {
                printf("%d, %d", a, c);
            }
            else
            {
                printf("%d, %d", c, a);
            }
        }
        else
        {
            printf("%d, ", c);

            if (a > b)
            {
                printf("%d, %d", a, b);
            }
            else
            {
                printf("%d, %d", b, a);
            }
        }
    }

    return 0;

}
