#include <stdio.h>
#include <stdlib.h>

conv_data();

int main()
{
    int d, dd, mm, aa;
    printf("Converter a quantidade de dias corridos em data (dd/mm/aa)\n");
    scanf("%d", &d);

    conv_data(d, &dd,&mm, &aa);

    printf("%02d/%02d/%04d\n", dd, mm, aa);

    return 0;
}

int conv_data(int d, int *dd, int *mm, int *aa)
{
    int dia_mes[11]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    *aa=d/365+1900;
    d%=365;
    for(i=0; d>=dia_mes[i]; i++)
    {
        d-=dia_mes[i];
    }
    *dd=d;
    *mm=i;
}
