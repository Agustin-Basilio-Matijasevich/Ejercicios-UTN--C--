#include <stdlib.h>
#include <stdio.h>

int mcd(int x, int y)  //Se le dan dos valores y calcula el maximo comun divisor de esos valores
{
	if (y == 0)  //Condicion de salida
	{
		return x;
	}
	else
	{
		mcd(y, x % y);
	}
}

int main()
{
	int x, y;

	//Solicitud de los numeros
	printf("Ingrese dos numeros para calcularles el maximo comun divisor\nIngrese el primer numero: ");
	scanf_s(" %i", &x);
	printf("Ingrese el segundo numero: ");
	scanf_s(" %i", &y);

	printf_s("El maximo comun divisor de %i y %i es: %i\n\n", x, y, mcd(x, y));

	system("pause");
	return 0;
}