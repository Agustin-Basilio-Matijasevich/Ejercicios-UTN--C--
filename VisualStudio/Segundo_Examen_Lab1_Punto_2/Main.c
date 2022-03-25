//Librerias
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define filas 3
#define columnas 4
#define totalnum 12

//Declaracion de funciones
void cargar_matriz(int matriz[filas][columnas]);
void mostrar_matriz(int matriz[filas][columnas]);
int es_impar(int numero);
void mostrar_arreglo(int array[totalnum]);
void inicialiar_arreglo(int array[totalnum]);
void ordenar_arreglo(int array[totalnum]);

//Main
int main()
{
	//Variables
	int matriz[filas][columnas];
	int impares[totalnum];
	int cantimpares = 0;

	//Logica
	cargar_matriz(matriz);  //Primero cargamos valores a la matriz
	mostrar_matriz(matriz);  //Ahora mostramos la matriz por pantalla
	inicialiar_arreglo(impares);  //Inicializamos el arreglo (En este programa el valor 0 sera tomado como nulo)

	//Controlamos cuantos impares hay en la matriz
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (es_impar(matriz[i][j]) == 1)
			{
				cantimpares++;
			}
		}
	}

	if (cantimpares > 0)  //Solo si hay impares podemos continuar con el ejercicio
	{
		int posarray = 0;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (es_impar(matriz[i][j]) == 1)
				{
					impares[posarray] = matriz[i][j];
					posarray++;
				}
			}
		}

		printf("Arreglo de impares\n");
		printf("Recuerde que el ´0´ es considerado valor nulo en este programa");
		mostrar_arreglo(impares);

		printf("Se cargaron %i numeros pares y %i numeros impares\n\n", totalnum - cantimpares, cantimpares);

		ordenar_arreglo(impares);

		printf("Arreglo de impares ordenado de menor a mayor");
		mostrar_arreglo(impares);

	}
	else  //En caso de que no haya impares no se pueden hacer las demas consignas
	{
		//Vacio
	}

	system("pause");
	return 0;
}

void cargar_matriz(int matriz[filas][columnas])
{
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			printf("Ingrese un valor para la fila %i columna %i: ", i+1, j+1);
			scanf_s(" %i", &matriz[i][j]);
		}
	}
}

void mostrar_matriz(int matriz[filas][columnas])
{
	printf("\n\n");

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			printf("|%6i|", matriz[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

}

int es_impar(int numero)
{
	if (numero % 2 == 0)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void mostrar_arreglo(int array[totalnum])
{
	printf("\n\n{");

	for (int i = 0; i < totalnum; i++)
	{
		if (i == totalnum - 1)
		{
			printf("%i", array[i]);
		}
		else
		{
			printf("%i, ", array[i]);
		}
	}
	printf("}\n\n");
}

void inicialiar_arreglo(int array[totalnum])
{
	for (int i = 0; i < totalnum; i++)
	{
		array[i] = 0;
	}
}

void ordenar_arreglo(int array[totalnum])
{
	int swap;

	for (int i = 0; i < totalnum - 1; i++)
	{
		for (int j = 0; j < totalnum - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
		}
	}
}