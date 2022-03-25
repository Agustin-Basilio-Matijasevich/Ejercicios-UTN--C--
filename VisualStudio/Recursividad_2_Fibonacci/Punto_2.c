#include <stdio.h>
#include <stdlib.h>

int cont = 2;

void fibo(int num1, int num2)
{
	printf(", %i", num1 + num2);

	cont++;

	if (cont < 10)
	{
		fibo(num2, num1 + num2);
	}

}

int main()
{
	printf("{0, 1"); // Apertura de llave para impresion ordenada de numeros e impresion de los dos primeros numeros de arranque de fibonacci

	fibo(0, 1);  //Ejecucion de la funcion que imprime los numeros de fibonacci, se le mandan los numeros de arranque

	printf("}\n\n");  //Cerrado de la llave para impresion ordenada

	system("pause");
	return 0;

}