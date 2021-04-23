#include <stdio.h>
#include <conio.h>

int main()
{
    char unaletra, otraletra;

    printf("Escriba una letra y pulse intro, por favor: ");
    scanf_s("%c", &unaletra);

    printf("La letra que ha pulsado era %c y su valor decimal es %d\n", unaletra, unaletra);

    printf("Ahora escriba otra letra, por favor: ");
    scanf_s("%c", &otraletra);

    printf("La letra que ha pulsado era %c y su valor decimal es %d\n", otraletra, otraletra);

    printf("\n\nTerminación normal del programa.\n\n");

	return 0;
}