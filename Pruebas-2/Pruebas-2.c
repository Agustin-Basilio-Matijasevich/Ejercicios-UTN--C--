#include <stdio.h>

#define iteracion 5

int main()
{
	int cont, aux;
	float suma;
	cont = 0; suma = 0;

	while (cont < iteracion)
	{
		aux = 1;

		while (aux % 3 != 0)
		{
			printf("Ingrese un numero multiplo de 3: ");
			scanf_s("%i", &aux);
			printf("Usted ingreso: %i\n", aux);
			if (aux %3 != 0)
			{
				printf("Valor no valido, por favor reintente\n");
			}

		}
		
		suma += aux;
		cont++;
	}

	printf("La suma total es: %.0f\n", suma);
	printf("El promedio es: %.2f\n", suma / iteracion);

	system("Pause");

	return 0;
}