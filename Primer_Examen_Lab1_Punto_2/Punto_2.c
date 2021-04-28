//Librerias
#include <stdio.h>

int main()
{
	//Variables
	int contarA = 0, contarB = 0;  //Contadores de numeros que cumplen A y numeros que no cumplen B

	printf("Numeros Divisibles por  3 que no forman parte del conjunto entre 25 y 35\n\n");

	//Impresion de los numeros
	printf("{ ");

	for (int i = 60; i > 5; i--)  //Recorre todos los numeros entre 60 y 5
	{
		if (i < 25 || i > 35) //Excluye los numeros entre 25 y 35
		{
			if (i % 3 == 0)  //Excluye los numeros que no sean divisibles por 3
			{
				printf("%i, ", i);
				contarA++;
			}
			else
			{
				contarB++;
			}
		}
		else
		{
			contarB++;
		}
	}

	printf("}\n\n");

	//Impresion de datos extra
	printf("La cantidad de numeros que cumplen las condiciones son: %i\n", contarA);
	printf("La cantidad de numeros que no cumplen las condiciones son: %i\n\n", contarB);

	//Pausa y finalizacion del programa
	system("Pause");
	return 0;
}