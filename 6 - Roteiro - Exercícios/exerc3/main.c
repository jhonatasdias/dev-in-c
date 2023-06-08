#include <stdio.h>
#include <stdlib.h>

conv_segundos();

int main()
{
    int h, min, s, segundostotal;

    printf("Converter as horas em segundos.\n");
    printf("Digite as horas, em hora, min e segundos nessa ordem: ");
    scanf("%d %d %d", &h, &min, &s);
    segundostotal=conv_segundos(h,min,s);
    printf("%d h, %d min e %d s = %d segundos\n", h, min, s, segundostotal);
    return 0;
}

int conv_segundos(int h, int min, int s)
{
    h=h*3600;
    min=min*60;
    s=h+min+s;
    return s;
}
