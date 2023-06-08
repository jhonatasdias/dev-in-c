#include <stdio.h>
#include <stdlib.h>

conv_hora();

int main()
{
    int h, min, s, stotal;

    printf("Converter segundos em hh:mm:ss.\n");
    printf("Digite os segundos: ");
    scanf("%d", &stotal);
    conv_hora(stotal, &h, &min, &s);
    printf("%d segundos = %02d:%02d:%02d\n", stotal, h, min, s);
    return 0;
}

int conv_hora(int stotal, int *h, int *min, int *s)
{
    *h=stotal/3600;
    stotal%=3600;
    *min=stotal/60;
    *s=stotal%60;
}
