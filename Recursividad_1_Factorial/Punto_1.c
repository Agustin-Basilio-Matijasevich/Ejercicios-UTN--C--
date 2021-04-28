#include <stdio.h>
#include <stdlib.h>

double factorial(double num)  //Funcion que calcula el factorial
{
	if (num == 1 || num == 0)  //Condicion de finalizacion
	{
		return 1;
	}
	else
	{
		return num * factorial(num - 1);  //Recursividad sobre la funcion
	}
}

int main()
{
	//Variables
	double num;  //Numero al cual se le debe calcular el factorial

	//Pido que se ingrese el numero al cual se le debe calcular el factorial
	printf("Ingrese el numero al cual decea calcularle el factorial\n");
	scanf_s(" %lf", &num);
	printf("\n");

	printf("El factorial del numero que usted indico es: %.0lf\n\n", factorial(num));  //Imprimo el resultado de llamar a la funcion

	system("pause");
	return 0;
}