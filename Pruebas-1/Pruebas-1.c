#include <stdio.h>

#define iteracion 5

int main()
{
	int cont, aux;
	float suma;
	cont = 0; suma = 0;

	while (cont < iteracion)
	{
		printf("Ingrese un numero: ");
		scanf_s("%i", &aux);
		printf("Usted ingreso: %i\n", aux);
		suma += aux;
		cont++;
	}

	printf("La suma total es: %.0f\n", suma);
	printf("El promedio es: %.2f\n", suma / iteracion);

	system("Pause");

	return 0;
}