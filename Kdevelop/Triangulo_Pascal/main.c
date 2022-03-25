#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int triangulo[20][39];  //Matriz 20x39 para contener triangulo de pascal
int fil, col;  //Cantidad de filas y columnas para la matriz del triangulo de pascal (max 100)
int calcont = 0;  //Cantidad de calculos a realizar
int cont = 0;  //Contador de calculos para saber el progreso del programa

double factorial(int num);  //Recibe un numero entero y devuelve su factorial en formato double
void cargartriangulo(int i, int j, int m, int n);  //Se le pasa posicion inicial para filas y columnas de la matriz para n y para m (todo "0" menos columna ahi va la mitad para centrar el triangulo) y ella carga en la matriz triangulo el triangulo de pascal tan grande como se haya indicado en el tamaño de filas
void imprimirtriangulo(int i, int j);  //Se le manda valor de inicio para filas y columnas e Imprime la matriz generada por cargartriangulo con formato adecuado
int calcolumnas(int columnas, int filas);  //Se le manda un "1" y la cantidad de filas y devuelve la cantidad de columnas
void inicializarmatriz(int i, int j);  //Se le manda posicion de inicio y la funcion inicializa la matriz del triangulo colocando "0" en todas las posiciones
double sumarial(int num);  //Se le da un numero entero y devuelve el reultado de sumar todos los numeros desde 1 hasta el numero dado

int main()
{
	//Ciclo de control de ingreso de dato
	do
	{
		printf("Se recomienda Maximizar la ventana del cmd para que la impresion de triangulos grandes salga bien\n");
		printf("Ingrese la cantidad de filas que quiere imprimir del triangulo de Pascal (Maximo 20)\n");
		scanf(" %i", &fil);

		if (fil <= 0 || fil > 20)
		{
			printf("La cantidad de filas y columnas debe ser mayor a 0 y menor o igual que 20, por favor, reintente.\n\n");

		}

	} while (fil <= 0 || fil > 20);  //Controla que el numero ingresado este dentro del rango indicado

	col = calcolumnas(1, fil);  //Carga en col el valor de columnas segun las filas que nos dieron usando la funcion calcolumnas

	calcont = sumarial(fil);

	printf("Calculando...\n\n");
	cargartriangulo(0, col/2, 0, 0);

	printf("El triangulo de pascal con %i filas es: \n\n", fil);

	imprimirtriangulo(0, 0);

	printf("\n\n");

	system("pause");
	return 0;

}

int calcolumnas(int columnas, int filas)
{
	if (filas == 1)  //Condicion de finalizacion
	{
		return columnas;
	}
	else
	{
		return calcolumnas(columnas + 2, filas - 1);
	}
}

double factorial(int num)
{
	if (num == 1 || num == 0)  //Condicion de finalizacion
	{
		return 1;
	}
	else
	{
		return num * factorial(num - 1);
	}
}

double sumarial(int num)
{
	if (num == 1 || num == 0)  //Condicion de finalizacion
	{
		return 1;
	}
	else
	{
		return num + sumarial(num - 1);
	}
}

void cargartriangulo(int i, int j, int m, int n)
{
	if (i < fil && j < col && triangulo[i][j] == 0)
	{
		//cargar m!/n!.(m-n)!
		triangulo[i][j] = ((factorial(m)) / ((factorial(n)) * (factorial(m - n))));

		cont++;
		calcont--;
		printf("Calculo %4i Realizado, Quedan: %4i\n\n", cont, calcont);

		cargartriangulo(i + 1, j - 1, m + 1, n);
		cargartriangulo(i + 1, j + 1, m + 1, n + 1);
	}
}



void imprimirtriangulo(int i, int j)
{
	bool corrio = false;  //controla si se ejecuto el segundo if

	if (i < fil)
	{
		if (j < col)
		{
			corrio = true;

			if (triangulo[i][j] == 0)
			{
				printf("      ");
			}
			else
			{
				printf("%6i", triangulo[i][j]);
			}

			imprimirtriangulo(i, j + 1);
		}
		else if (i < fil && !corrio)
		{
			printf("\n");
			imprimirtriangulo(i + 1, 0);
		}
	}
}

void inicializarmatriz(int i, int j)
{
	bool corrio = false;  //controla si se ejecuto el segundo if

	if (i < fil)
	{
		if (j < col)
		{
			corrio = true;

			triangulo[i][j] = 0;

			imprimirtriangulo(i, j + 1);
		}
		else if (i < fil && !corrio)
		{
			imprimirtriangulo(i + 1, 0);
		}
	}
}
